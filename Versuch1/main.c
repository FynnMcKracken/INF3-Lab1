/******************************************************************************
;*	Hochschule f�r Angewandte Wissenschaften Hamburg													*	
;*	Fakult�t DMI																															*
;*	Department Medientechnik																									*
;*	Veranstaltung: Informatik 3 & Elektronik                                  *
;******************************************************************************
;*	Praktikum Versuch1						    																				*
;*	Programmrumpf f�r C-Programme mit �Vision4 von Keil												*
;******************************************************************************
;*	Namen / Matrikel-Nr.: 1.                                                  *
;*												2.																									*
;******************************************************************************
;*	Abgabedatum:																															*
;*****************************************************************************/

#include <lpc11xx.h>			// LPC1114 definitions


int main(){ 
	
	LPC_GPIO3->DIR |= 0x3F; 	//Set PIN3_5 to PIN3_0 as outputs
	LPC_GPIO2->DIR |= 0xC0; 	//Set PIN2_6 and PIN2_7 as outputs
	
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9); //Activate clock for TMR32B0
	
	LPC_TMR32B0->PR = 12000; //Set presacler to 12000 -> 12MHz/12000 = 1ms
	LPC_TMR32B0->TCR = 0x2;		// Stop and reset timer
	LPC_TMR32B0->MCR = 0x600;		// Set MCR with MR3 for IR and reset
	LPC_TMR32B0->MR3 = 500;		// Match register 3 to 500
	LPC_TMR32B0->TCR = 0x1;		// Start timer
	NVIC->ISER[0] |= 0x40000; // Set exception for TMR32B0 (Exception 18)
	
	LPC_GPIO3->DATA = ~(0x1); // Turn on LED3_0
	
	while(1) { ; }
}

void nextLED() {
	if(~(LPC_GPIO3->DATA) < 0x80 && ~(LPC_GPIO3->DATA) > 0x0) {
		LPC_GPIO3->DATA >>= 1;
	} else if (~(LPC_GPIO3->DATA) & 0x80){
		LPC_GPIO3->DATA = 0xFFF;
		LPC_GPIO2->DATA = ~(0x40);
	} else if(~(LPC_GPIO2->DATA) & 0x40) {
		LPC_GPIO2->DATA = ~(0x80);
	} else if(~(LPC_GPIO2->DATA) & 0x80) {
		LPC_GPIO3->DATA = ~(0x1);
		LPC_GPIO2->DATA = 0xFFF;
	}
	return;
}

void TIMER32_0_IRQHandler(void){
	if (~(LPC_GPIO3->DATA) & 0x1) {
		LPC_GPIO3->DATA = ~(0x2);
	} else if( ~(LPC_GPIO3->DATA) & 0x2) {
		LPC_GPIO3->DATA = ~(0x4);
	} else if( ~(LPC_GPIO3->DATA) & 0x4) {
		LPC_GPIO3->DATA = ~(0x8);
	} else if( ~(LPC_GPIO3->DATA) & 0x8) {
		LPC_GPIO3->DATA = ~(0x10);
	} else if(~(LPC_GPIO3->DATA) & 0x10) {
		LPC_GPIO3->DATA = ~(0x20);
	} else if(~(LPC_GPIO3->DATA) & 0x20) {
		LPC_GPIO3->DATA = 0xFFF;
		LPC_GPIO2->DATA = ~(0x40);
	} else if(~(LPC_GPIO2->DATA) & 0x40) {
		LPC_GPIO2->DATA = ~(0x80);
	} else if(~(LPC_GPIO2->DATA) & 0x80) {
		LPC_GPIO3->DATA = ~(0x1);
		LPC_GPIO2->DATA = 0xFFF;
	}
	
	LPC_TMR32B0->IR &= 0x8;
	return;
}

