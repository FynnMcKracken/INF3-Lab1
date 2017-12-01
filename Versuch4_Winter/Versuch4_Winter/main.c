/********************************************************************
;*  Hochschule für Angewandte Wissenschaften Hamburg		    		    *
;*  Fakultaet DMI																										*
;*  Department Medientechnik								    										*
;*  Vorlesung INF3 & Elektronik					     												*
;********************************************************************
;*  Praktikum Teil 2 	  									     											*
;*	Programmrumpf für C-Programme mit dem Keil	     		   					*
;*	Entwicklungsprogramm uVision4 für ARM-Mikrocontroller						*
;********************************************************************
;*	Versuch-Nr.: 4																									*
;********************************************************************
;*	Namen / Matrikel-Nr.:  1.		                                    *
;*              			     2.																			  *
;********************************************************************
;* 	Abgabedatum:             																				*
;********************************************************************/

#include <lpc11xx.h>
#include "spi.h"
#include "picture.h"

/*##################################################################### 

  In diesem Projekt wird das Display im 256-Farben-Modus initialisiert.

  #####################################################################
   --------------------------------------------------------------------
   Warten einer gegebenen Anzahl an Millisekunden (msWait).
   Die Funktion verwendet den Timer32B0 als Zeitbasis
   --------------------------------------------------------------------*/
void Waitms(const unsigned int msWait){
  unsigned int   aktTime, diff;
  aktTime = LPC_TMR32B0->TC; //aktuellen Zaehlerstand des Timers auslesen
  do {
      //bereits vergangene Zeit berechnen
			if (LPC_TMR32B0->TC >= aktTime) diff = LPC_TMR32B0->TC - aktTime;
			else diff = (0xFFFFFFFF - aktTime) + LPC_TMR32B0->TC;
  } while (diff	< msWait);
}

/* ----------------------------------------------------------------
   Senden einer Sequenz von  16-Bit Kommandos an das TFT-Display
   mittels SPI-Interface. Dabei wird die Data/Command Leitung
   entsprechend gesetzt
   ---------------------------------------------------------------- */
void SendCommandSeq(const unsigned short * data, int Anzahl)
{
  int  index;
	unsigned char   SendeByte;
	for (index=0; index<Anzahl; index++){
		LPC_GPIO0->DATA |= 0x10;	  //Data/Command auf High => Kommando-Modus			
		SendeByte = (data[index] >> 8) & 0xFF; 	//High-Byte des Kommandos
		SPISend8Bit(SendeByte);
		SendeByte = data[index] & 0xFF; 				//Low-Byte des Kommandos
		SPISend8Bit(SendeByte);
		LPC_GPIO0->DATA &= ~0x10;								//Data/Command auf Low => Daten-Modus	
	}
}

/* ----------------------------------------------------------------
   Initialisierung des TFT-Displays fuer den 65536-Farben Modus
   entsprechend der im Skript beschriebenen Schritte einschließlich
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
		0xEF90, 0x4A04, 0x7F1F, 0xEE04, 0x4306, 
		/* pause  */
		0xEF90, 0x0983, 0x0800, 0x0BAF, 0x0A00, 
		0x0500, 0x0600, 0x0700, 0xEF00, 0xEE0C, 
		0xEF90, 0x0080, 0xEFB0, 0x4902, 0xEF00, 
		0x7F01, 0xE181, 0xE202, 0xE276, 0xE183, 
		0x8001, 0xEF90, 0x0000,
		//pause
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
}

void displayImage(void) {
	int i;
	unsigned short data[] = {
		0xEF08, 0x1803, 0x126F, 0x152E, 0x137D, 0x162C //Offset: x=20, y=50; Size: w=66, h=82
	};
	SendCommandSeq(data, 6);
	for(i=0; i<sizeof(Bild1); i++) {
		SPISend8Bit(FarbTabelle[Bild1[i] >> 4]); //Draw most significant byte first
		SPISend8Bit(FarbTabelle[Bild1[i] & 0xF]);
	}
	
}


int main() {
		int i;
	
	 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);	//siehe Hinweis in Getting Started
	 LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);		//Enables clock for 32-bit counter/timer 0
  
   LPC_GPIO0->DIR	|= 0x10;		//PIO0_4 als Data/Command, digitaler Ausgang
	 LPC_GPIO1->DIR |= 0x80;		//PIO1_7 als Reset, digitaler Ausgang
	
   //Timer32B0 initialisieren. Er liefert die Zeitbasis fuer die Funktion waitms
   LPC_TMR32B0->PR  = 48000; //bei P-Clock 48Mhz ergibt sich 1Khz Timer Auflösung
   LPC_TMR32B0->TCR = 0x02;  //setzt Timer zurueck und haelt ihn an
   LPC_TMR32B0->TCR = 0x01;  //startet Timer

	 //SPI-Schnittstelle initialisieren:
   SPIInit8BitMaster();
   
	 //Display initialisieren:
   InitDisplay();
	for(i=0; i<132*176; i++) {
		SPISend8Bit(0xFF);
	}
	displayImage();

   while (1) {;} 	//Endlosschleife
}

