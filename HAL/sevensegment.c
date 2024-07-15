/*
 * sevensegment.c
 *
 * Created: 1/20/2021 5:16:51 AM
 *  Author: karim hassan
 */ 

#include "sevensegment.h"
#include <util/delay.h>

static char seg_num[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void seg_init(seg_type_t seg_type , uchar8 seg_port)
{
	
	switch(seg_type)
	{
		case CC_Normal:
		case CA_Normal:	initialize_port_mask(seg_port , SEG_MASK_NORMAL); 
		                break;

		case CA_BCD:
		case CC_BCD:	initialize_port_mask(seg_port , SEG_MASK_BCD);
		                break;
	}
	#if defined(SEG_EN_STATE)&&(SEG_EN_STATE==SEG_EN_CONNECTED)
		#ifndef _once_
		#define _once_
            initialize_pin(SEG_EN1_PORT,SEG1_EN,OUTPUT);
			initialize_pin(SEG_EN2_PORT,SEG2_EN,OUTPUT);
			
			initialize_pin(SEG_EN1_PORT,SEG11_EN,OUTPUT);
			initialize_pin(SEG_EN2_PORT,SEG22_EN,OUTPUT);
			
			initialize_pin(SEG_EN1_PORT,SEG111_EN,OUTPUT);
			initialize_pin(SEG_EN2_PORT,SEG222_EN,OUTPUT);
		#endif
	#endif

}





void seg_write(seg_type_t seg_type , uchar8 seg_port , uchar8 val , uchar8 seg_en)
{

	switch(seg_type)
	{

	case CC_Normal:	io_write_port_clear(seg_port,SEG_MASK_NORMAL);
	                io_write_port_mask(seg_port,seg_num[val]);
	                break;

	case CA_Normal:	io_write_port_clear(seg_port ,SEG_MASK_NORMAL);
	                io_write_port_mask(seg_port,~seg_num[val]);
	                break;

	case CC_BCD:	io_write_port_clear(seg_port ,SEG_MASK_BCD);
                    io_write_port_mask(seg_port,val<<4);
                    break;

	case CA_BCD:	io_write_port_clear(seg_port ,SEG_MASK_BCD);
                    io_write_port_mask(seg_port,val<<4);
                    break;
	}
	#if defined(SEG_EN_STATE)&&(SEG_EN_STATE==SEG_EN_CONNECTED)
		if(seg_en==SEG1_EN)
		{
			io_write_pin(SEG_EN1_PORT,SEG1_EN,LOW);
			io_write_pin(SEG_EN2_PORT,SEG2_EN,HIGH);
		}
		else if (seg_en==SEG2_EN)
		{
		    io_write_pin(SEG_EN2_PORT,SEG2_EN,LOW);
		    io_write_pin(SEG_EN1_PORT,SEG1_EN,HIGH);
		}
		else if (seg_en==SEG11_EN)
		{
			io_write_pin(SEG_EN2_PORT,SEG22_EN,HIGH);
			io_write_pin(SEG_EN1_PORT,SEG11_EN,LOW);
		}
		else if (seg_en==SEG22_EN)
		{
			io_write_pin(SEG_EN2_PORT,SEG22_EN,LOW);
			io_write_pin(SEG_EN1_PORT,SEG11_EN,HIGH);
		}
		else if (seg_en==SEG111_EN)
		{
			io_write_pin(SEG_EN2_PORT,SEG222_EN,HIGH);
			io_write_pin(SEG_EN1_PORT,SEG111_EN,LOW);
		}
		else if (seg_en==SEG222_EN)
		{
			io_write_pin(SEG_EN2_PORT,SEG222_EN,LOW);
			io_write_pin(SEG_EN1_PORT,SEG111_EN,HIGH);
		}
		else if(seg_en==SEG_EN_BOTH)
		{
		    io_write_pin(SEG_EN2_PORT,SEG2_EN,LOW);
		    io_write_pin(SEG_EN1_PORT,SEG1_EN,LOW);
			
			io_write_pin(SEG_EN2_PORT,SEG22_EN,LOW);
			io_write_pin(SEG_EN1_PORT,SEG11_EN,LOW);
			
			io_write_pin(SEG_EN2_PORT,SEG222_EN,LOW);
			io_write_pin(SEG_EN1_PORT,SEG111_EN,LOW);
			
		}
		#endif
}





void seconds()
{
	
	int i;
	int j;
	int z;
	
	for (i=0 ; i<=5 ; i++)
	{
		
		for (j=0 ; j<=9 ; j++)
		{
			
			for (z=0 ; z<=300 ; z++)
			{
				
				
				seg_write(CC_Normal , SEGC_PORT , i , SEG1_EN);
				_delay_ms(10);
				seg_write(CC_Normal , SEGC_PORT , j , SEG2_EN);
				_delay_ms(10);
			
			
			}
			
			
		}
		
	}
	
}




void minutes()
{
	
	int x;
	int y;
	int u;
	
	for (x=0 ; x<=5 ; x++)
	{
		
		for (y=0 ; y<=9 ; y++)
		{
			       
			  seconds();
			  
			  for (u=0 ; u<=50 ; u++)
			  {
				  	  	    
					  seg_write(CC_Normal , SEGA_PORT , x , SEG11_EN);
					  _delay_ms(5);
					  
					  seg_write(CC_Normal , SEGA_PORT , y , SEG22_EN);
					  _delay_ms(5);
				  
			  }
			  
			 
		}
		
	}
	
	
}






void HOURES()
{
	
	int n;
	int m;
	int p;
	
	for (n=0 ; n<=2 ; n++)
	{
		
		for (m=1 ; m<=9 ; m++)
		{
			
			minutes();
			
			for (p=0 ; p<=300 ; p++)
			{
				
				seg_write(CC_Normal , SEGB_PORT , n , SEG111_EN);
				_delay_ms(10);
				seg_write(CC_Normal , SEGB_PORT , m , SEG222_EN);
				_delay_ms(10);
				
				if (n==2 && m==4)
				{
					break;
				}
				if (n==2 && m==5)
				{
					break;
				}
				if (n==2 && m==6)
				{
					break;
				}
				if (n==2 && m==7)
				{
					break;
				}
				if (n==2 && m==8)
				{
					break;
				}
				if (n==2 && m==9)
				{
					break;
				}
				
			}
			
			
		}
		
	}
	
	
}








