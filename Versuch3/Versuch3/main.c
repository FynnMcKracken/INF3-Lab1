#include <lpc11xx.h>
#include "spi.h"

unsigned int btn, btn2;
unsigned int c, c2;
int oX, oY;

/* ----------------------------------------------------------------
   Warten einer gegebenen Anzahl an Millisekunden (msWait).
   Die Funktion verwendet den Timer32B0 als Zeitbasis
   ---------------------------------------------------------------- */
void Waitms(const unsigned int msWait) {
  unsigned int   aktTime, diff;
  aktTime = LPC_TMR32B0->TC; //aktuellen Zaehlerstand des Timers auslesen
  do {
      //bereits vergangene Zeit berechnen
			if (LPC_TMR32B0->TC >= aktTime) diff = LPC_TMR32B0->TC - aktTime;
			else diff = (0xFFFFFFFF - aktTime) + LPC_TMR32B0->TC;
  } while (diff	< msWait);
}

/* ----------------------------------------------------------------
   Senden einer Sequenz von 16-Bit Kommandos an das TFT-Display
   mittels SPI-Interface. Dabei wird die Data/Command Leitung
   entsprechend gesetzt
   ---------------------------------------------------------------- */
void SendCommandSeq(const unsigned short * data, int Anzahl){
  int  index;
	unsigned char   SendeByte;
	for (index=0; index<Anzahl; index++){
		LPC_GPIO0->DATA |= 0x10;	  //Data/Command auf High => Kommando-Modus
		SendeByte = (data[index] >> 8) & 0xFF; //High-Byte des Kommandos
		SPISend8Bit(SendeByte);
		SendeByte = data[index] & 0xFF; //Low-Byte des Kommandos
		SPISend8Bit(SendeByte);
		LPC_GPIO0->DATA &= ~0x10;		//Data/Command auf Low => Daten-Modus	
	}
}

/* ----------------------------------------------------------------
   Initialisierung des TFT-Displays fuer den 65536-Farben Modus
   entsprechend der in der Vorlesung beschriebenen Schritte einschlie�lich
   der Uebertragung der Initialisierungs-Kommandos.
   Zur Ueberwachung der Zeitabstaende wird die Funktion Waitms verwendet.
   Zum senden eines Kommandos an das Display wird die Funktion SendCommand
   verwendet. 
   ---------------------------------------------------------------- */
void InitDisplay(void) {
    const unsigned short InitData[] = { 
	  //Initialisierungsdaten fuer 256 Farben Modus
		0xFDFD, 0xFDFD, 
		/* pause  */
		0xEF00, 0xEE04, 0x1B04, 0xFEFE, 0xFEFE, 
		0xEF90, 0x4A04, 0x7F3F, 0xEE04, 0x4306, 
		/* pause  */
		0xEF90, 0x0983, 0x0800, 0x0BAF, 0x0A00, 
		0x0500, 0x0600, 0x0700, 0xEF00, 0xEE0C, 
		0xEF90, 0x0080, 0xEFB0, 0x4902, 0xEF00, 
		0x7F01, 0xE181, 0xE202, 0xE276, 0xE183, 
		0x8001, 0xEF90, 0x0000,
		// pause
		0xEF08,	0x1800,	0x1200, 0x1583,	0x1300,
		0x16AF 	//Hochformat 132 x 176 Pixel
	}; 

	  Waitms(300); 
	  LPC_GPIO1->DATA &= ~0x80;  //Reset-Eingang des Displays auf Low => Hardware-Reset; ???so auf High???
    Waitms(75);
	  LPC_GPIO2->DATA |= 0x400;  //SSEL auf High
    Waitms(75);
	  LPC_GPIO0->DATA |= 0x10;   //Data/Command auf High
    Waitms(75);
	  LPC_GPIO1->DATA |= 0x80;   //Reset-Eingang des Displays auf High => kein Hardware-Reset 
	
    SendCommandSeq(&InitData[0], 2);
    Waitms(75); 
    SendCommandSeq(&InitData[2], 10);
    Waitms(75); 
    SendCommandSeq(&InitData[12], 23);
		Waitms(75); 
    SendCommandSeq(&InitData[35], 6); 
}

void InitButtons(void) {
	
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); //Activate clock for TMR32B0
	
	LPC_TMR32B0->PR = 12000; //Set presacler to 12000 -> 12MHz/12000 = 1ms
	LPC_TMR32B0->TCR = 0x2;		// Stop and reset timer
	LPC_TMR32B0->MCR = 0x3;		// Set MCR with MR0 for IR and reset
	LPC_TMR32B0->MR0 = 1;			// Match register to 1
	LPC_TMR32B0->TCR = 0x1;		// Start timer
	NVIC->ISER[0] |= 0x40000; // Set exception for TMR32B0 (Exception 18)
}

void drawRect(int oy) {
	int i;
	short y1, y2;
	unsigned short data[] = {
		0xEF08, 0x1805, 0x1246, 0x153B, 0x1351, 0x165C
	};
	data[4] += oy;
	data[5] += oy;
	SendCommandSeq(data, 6);
	for(i=0; i<120; i++) {
		if(i%12 == 0) {
				SPISend8Bit(0xFF);
				SPISend8Bit(0xE0);
		} else if (i>0 && (i-11) % 12 == 0) {
				SPISend8Bit(0xFF);
				SPISend8Bit(0xE0);
		} else {
			SPISend8Bit(0xF8);
			SPISend8Bit(0x00);
		}
	}

}

int main() {
	int i = 0;
	const unsigned short data[] = {
		0xEF08, 0x1805, 0x1246, 0x153B, 0x1352, 0x165B
	};
	
	 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);	//siehe Hinweis in Getting Started
	 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);		//Enables clock for 32-bit counter/timer 0
	 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);		//Enables Clock for 16-bit-counter/timer0, s. [3.5.14]
  
   LPC_GPIO0->DIR	|= 0x10;		//PIO0_4 als Data/Command, digitaler Ausgang
	 LPC_GPIO1->DIR |= 0x80;		//PIO1_7 als Reset, digitaler Ausgang
	
   //Timer32B0 initialisieren. Er liefert die Zeitbasis fuer die Funktion waitms
   LPC_TMR32B0->PR  = 48000; 	//bei P-Clock 48Mhz ergibt sich 1Khz Timer Aufl�sung
   LPC_TMR32B0->TCR = 0x02;  	//setzt Timer zurueck und haelt ihn an
   LPC_TMR32B0->TCR = 0x01;  	//startet Timer

	 //SPI-Schnittstelle initialisieren:
   SPIInit8BitMaster();
   
	 //Display initialisieren:
   InitDisplay();
	 
	 
	 for(i=0; i<176*132; i++) {
			SPISend8Bit(0xFF);
			SPISend8Bit(0xE0);
	 }
	 drawRect(0);
	 InitButtons();
	
   while (1) {;} 	//Endlosschleife
}

void TIMER32_0_IRQHandler(void){
	btn = LPC_GPIO2->DATA;
	btn = (btn & 0x200)>>9;  //Check and mask for PIN2_9
	btn2 = LPC_GPIO1->DATA;
	btn2 = (btn2 & 0x10)>>4; //Check and mask for PIN1_4
	
	
	if(!(btn)) { //If button pressed increment counter
		c++;
	}	else { //Button released
		if(c>10) { //If counter big enough turn on next LED
			if(oY < 84) {
				drawRect2(++oY);
				c = 0;
			}	
		}
		c = 0;
	}
	if(!(btn2)) { //If button pressed increment counter
		c2++;
	}	else { //Button released
		if(c2>10) { //If counter big enough turn on next LED
			if(oY > 0) {
				drawRect2(--oY);
				c = 0;	
			}
		}
		c2 = 0;
	}
	
	LPC_TMR32B0->IR &= 0x1;
	return;
}





