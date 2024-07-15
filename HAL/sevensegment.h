/*
 * sevensegment.h
 *
 * Created: 1/20/2021 5:17:13 AM
 *  Author: karim hassan
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "Gpio.h"

/****************** masking values*****************************/
#define SEG_MASK_NORMAL		0x7f//0111 1111
#define SEG_MASK_BCD		0xf0//1111 0000  :  higher nibble

#define SEG_EN_CONNECTED	0xFF
#define SEG_EN_BOTH			0xFF
#define SEG_EN_DISCONNECTED	0XDD


/************* hardware configuration **************/
#define	SEGA_PORT		GPIO_A
#define	SEGB_PORT		GPIO_B
#define	SEGC_PORT	    GPIO_C
#define SEGD_PORT		GPIO_D

#define SEG_EN1_PORT	GPIO_C
#define SEG_EN2_PORT	GPIO_C

#define SEG_EN11_PORT   GPIO_D
#define SEG_EN22_PORT   GPIO_D

#define SEG_EN111_PORT  GPIO_D
#define SEG_EN222_PORT  GPIO_D


#define SEG_EN_STATE	SEG_EN_CONNECTED

#define SEG1_EN			PIN_6
#define SEG2_EN			PIN_7

#define SEG11_EN        PIN_2
#define SEG22_EN        PIN_3

#define SEG111_EN       PIN_4
#define SEG222_EN       PIN_5


/*******************type defenations ***************/
#define SEG_HIGER_NIBBLE(reg,val) (reg&0x0f)|(val<<4)


/*CC common cathode CA common anode*/

typedef enum stype
{
	
	CC_BCD,//higher nibble
	CA_BCD, // higher nibble
	CC_Normal,
	CA_Normal,
	
}seg_type_t;


/**************************************************/
void seg_init(seg_type_t seg_type , uchar8 seg_port);

void seg_write(seg_type_t seg , uchar8 seg_port , uchar8 val , uchar8 seg_en);

void seconds();

void minutes();

void HOURES();


#endif /* SEVENSEGMENT_H_ */