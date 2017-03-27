/**
   @file main.c

   @brief Plantilla Keil 5 para la placa STM32F$Discovery
   Más detalles en el archivo leeme.txt
   
   @author Equipo ARM Power http://armpower.blogs.upv.es/
   @date 2017/03/06
*/

#include <stdio.h>
#include <stm32f4xx.h>


uint16_t display[10] = {0xFFC0,0xFFF9,0xFFA4,0xFFB0,0xFF99,0xFF92,0xFF82, 0xFFF8, 0xFF80,0xFF98};
uint8_t i = 0;
uint8_t enable_button = 0; //Valores TRUE, FALSE

void led_config(){

   GPIO_InitTypeDef GPIO_InitStructure;
   
   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(GPIOD, &GPIO_InitStructure);
}



void button_config(){
   
   GPIO_InitTypeDef GPIO_InitStructure;  

   RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA ,ENABLE);
          
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
   
   GPIO_Init(GPIOA, &GPIO_InitStructure);
   
}




uint8_t read_button(){

   return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);   

}



void delay (uint32_t ms){

	uint32_t j;
	
	for (j=0;j< 32000*ms;j++) {};

}



int main(void)
{
	
	 led_config();
   button_config();

   while (1) {
	
/*
   //Contador de pulsos
		 
  		if(read_button() == 1 && enable_button == 1){
        
				delay(400); //Se añade un delay para evitar el rebote del pulsador
				i++;
				enable_button = 0;
			}
	
			if(read_button() == 0 && enable_button == 0){
	
				enable_button = 1;
		
			}

      GPIO_Write(GPIOD, display[i]);      
			
			if(i > 9){ i = 0; } //Se resetea el contador
 
	*/	 
	
   // Contador temporizado	
		 
		for(i = 0; i <=9; i++){ 
		
			GPIO_Write(GPIOD, display[i]);
      delay(1000);
		}
	
				
	}         

   return(0);
}




