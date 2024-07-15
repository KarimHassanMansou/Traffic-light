






int main(void)
{
  
    int i;
    int j;
    int z;
  
  
	LCD_INIT();
	seg_init(CC_Normal , SEGD_PORT);
	
	initialize_pin(GPIO_C , 0 , OUTPUT);//red
    initialize_pin(GPIO_C , 1 , OUTPUT);//yellow
	initialize_pin(GPIO_C , 2 , OUTPUT);//green	
	
    while(1)
    {    
		
		  LCD_WRITE_COMMAND(0x0C);
		  
		  LED_ON(GPIO_C , 0);
		  LCD_WRITE_STRING("vehicles: stop");
		  LCD_WRITE_COMMAND(0xC0);
		  LCD_WRITE_STRING("People: move");
		
		  for (i=6 ; i>=0 ; i--)
		  {
			  
			  if (i==3)//yellow
			  {
				  
				   LED_OFF(GPIO_C , 0);//red off
				   LED_ON(GPIO_C , 1);//yellow on
				   
				   LCD_CLEAR();
				   _delay_ms(300);
				   
				   LCD_WRITE_STRING("Ready..");
				  
			  }
			  
			  if (i==2)//green
			  {
				  
				   LED_OFF(GPIO_C , 1);//yellow off
				   LED_ON(GPIO_C , 2);//green on
				   
				   LCD_CLEAR();
				   _delay_ms(300);
				   
				   LCD_WRITE_STRING("People: stop");
				   LCD_WRITE_COMMAND(0xC0);
				   LCD_WRITE_STRING("Vehicles: move");
				  
			  }
			  
			 
			
			  
			  for (j=9 ; j>=0 ; j--)
			  {
				  
				
				  
				  for (z=400 ; z>=0 ; z--)
				  {
					  
					  seg_write(CC_Normal , SEGD_PORT , i , SEG1_EN);
					  _delay_ms(10);
					  seg_write(CC_Normal , SEGD_PORT , j , SEG2_EN);
					  _delay_ms(10);    
					   
				  }
				  
				  
				   			   				  
				  
			  }
			  
		  }

	
	 	  LED_OFF(GPIO_C , 2);
	 	  
	 	  LCD_CLEAR();
	 	  _delay_ms(300);
	 	  
	 
	}	
	
}

