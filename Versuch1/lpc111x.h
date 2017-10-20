/***********************************************************************/
/*                                                                     */
/*  Copyright Michael Berens 14.2.2014                                 */
/***********************************************************************/
/*                                                                     */
/*  LPC111X.H:  Header file for NXP LPC1114/301                        */
/*                                                                     */
/***********************************************************************/

#ifndef LPC111x_H
#define LPC111x_H

/* Nested Vector Interrupt Controller (NVIC) */
#define ISER	(*((volatile unsigned long*) 0xE000E100))
#define ICER	(*((volatile unsigned long*) 0xE000E180))
#define ISPR	(*((volatile unsigned long*) 0xE000E200))
#define ICPR	(*((volatile unsigned long*) 0xE000E280))

#define IPR0	(*((volatile unsigned long*) 0xE000E400))
#define IPR1	(*((volatile unsigned long*) 0xE000E404))
#define IPR2	(*((volatile unsigned long*) 0xE000E408))
#define IPR3	(*((volatile unsigned long*) 0xE000E40C))
#define IPR4	(*((volatile unsigned long*) 0xE000E410))
#define IPR5	(*((volatile unsigned long*) 0xE000E414))
#define IPR6	(*((volatile unsigned long*) 0xE000E418))
#define IPR7	(*((volatile unsigned long*) 0xE000E41C))

#endif  // LPC111x_H
