#include <stdio.h>
#include "proc/defs.h" 
#include "cli.h"
#include <string.h>
#include <stdlib.h>






command_status do_md(int argc, char *argv[]) {
	//Todo: input handling

	int i;
	char* address = (char*) malloc( 9 * sizeof(char)); 
   
	for(i = 0; i < 8; i++)
		address[i] = argv[1][i+2];
	
    address[8] = '\0';

	unsigned char* mem_ptr = (unsigned char *) strtol(address, NULL, 16);
    
	int length = atoi(argv[2]);
	char* ascii_content = (char*) malloc(17*sizeof(char));
	ascii_content[16] = '\0';
	char content;
	int temp;
      
	for(i=0; i<length; i++)
	{
		content = (char) mem_ptr[i];
 
		if(i % 16 == 0) //new line
		{
 		
			printf("%8p:", &mem_ptr[i]);
		};
		if(i % 4 == 0) //space
		{
			printf(" ");
		}
		
		if(content >= 16)
			printf("%x", content);
		else 
			printf("0%x", content);
		ascii_content[i % 16] = (content >= 0x20 && content <= 0x7e) ? content : '.' ;
	
		if(i%16 == 15) printf(" %s\r\n", ascii_content);
	}

	if(length % 16 != 0) 
	{	
		temp = 16 - length%16;
		
		for(i = 0; i < temp; i++)
			ascii_content[length%16 + i] = ' ';

		temp = 2*temp + temp / 4;
		for(i = 0; i < temp; i++ )
			printf(" ");

		printf(" %s\r\n", ascii_content);
	}

	return USAGE;
}

COMMAND_ENTRY("md", "md <addr> <count>", "View raw memory contents.", do_md)

command_status do_mw(int argc, char *argv[])
{
	printf("mw not implemented\r\n");
	return USAGE;
}

COMMAND_ENTRY("mw", "mw <addr> <value> <count>", "Write data memory contents.", do_mw)


command_status do_memmap(int argc, char*argv[]) {
	printf("Physical     		 \t Target \t Size \r\n");
 
	/* AHB1 Start */

<<<<<<< HEAD
	printf("USB OTG HS   		 \t %x \t %d bytes \r\n",USB_OTG_HS_PERIPH_BASE,  0x4007ffff - USB_OTG_HS_PERIPH_BASE);
	printf("DMA2D_BASE        	 \t %x \t %d bytes \r\n",DMA2D_BASE,       0x4002BBFF - DMA2D_BASE);
	printf("Ethernet MAC 		 \t %x \t %d bytes \r\n",0x40029000, 0x400293FF - 0x40029000);
	printf("Ethernet MAC 		 \t %x \t %d bytes \r\n",0x40028C00, 0x40028FFF - 0x40028C00);
	printf("Ethernet MAC 		 \t %x \t %d bytes \r\n",0x40028800, 0x40028BFF - 0x40028800);
	printf("Ethernet MAC 		 \t %x \t %d bytes \r\n",0x40028400, 0x400287FF - 0x40028400);
	printf("Ethernet MAC 		 \t %x \t %d bytes \r\n",0x40028000, 0x400283FF - 0x40028000);
=======
	printf("USB OTG HS   		 \t %x \t %d bytes \r\n",USB_OTG_HS,  0x4007ffff - (int)USB_OTG_HS);
	printf("DMA2D        		 \t %x \t %d bytes \r\n",DMA2D_BASE,       0x4002BBFF - DMA2D_BASE);
	//printf("Ethernet MAC \t %x \t %d bytes \n", 
>>>>>>> b058e9889cefba732057b024270dc99c0516e238
	printf("DMA2	     		 \t %x \t %d bytes \r\n",DMA2_BASE,   0x400293FF - DMA2_BASE);
	printf("DMA1	     		 \t %x \t %d bytes \r\n",DMA1_BASE,   0x400263FF - DMA1_BASE); 
	printf("BKPSRAM	     		 \t %x \t %d bytes \r\n",BKPSRAM_BASE,0x40024FFF - BKPSRAM_BASE);
	printf("Flash interface register \t %x \t %d bytes \r\n",FLASH_R_BASE,0x40023FFF - FLASH_R_BASE); 
	printf("RCC			 \t %x \t %d bytes \r\n",RCC_BASE	   ,0x40023BFF - RCC_BASE);
	printf("CRC                      \t %x \t %d bytes \r\n",CRC_BASE        ,0x400233FF - CRC_BASE);
	printf("GPIOK                    \t %x \t %d bytes \r\n",GPIOK_BASE      ,0x40022BFF  - GPIOK_BASE);
	printf("GPIOJ                    \t %x \t %d bytes \r\n",GPIOJ_BASE      ,0x400227FF  - GPIOJ_BASE);
	printf("GPIOI                    \t %x \t %d bytes \r\n",GPIOI_BASE      ,0x400223FF  - GPIOI_BASE);
	printf("GPIOH                    \t %x \t %d bytes \r\n",GPIOH_BASE      ,0x40021FFF  - GPIOH_BASE); 
	printf("GPIOG                    \t %x \t %d bytes \r\n",GPIOG_BASE      ,0x40021BFF  - GPIOG_BASE);
	printf("GPIOF                    \t %x \t %d bytes \r\n",GPIOF_BASE     ,0x400217FF  - GPIOF_BASE);
	printf("GPIOE                    \t %x \t %d bytes \r\n",GPIOE_BASE      ,0x400213FF  - GPIOE_BASE);
	printf("GPIOD                    \t %x \t %d bytes \r\n",GPIOD_BASE      ,0x40020FFF  - GPIOD_BASE);
	printf("GPIOC                    \t %x \t %d bytes \r\n",GPIOC_BASE      ,0x40020BFF  - GPIOC_BASE);
	printf("GPIOB                    \t %x \t %d bytes \r\n",GPIOB_BASE      ,0x400207FF  - GPIOB_BASE);
	printf("GPIOA                    \t %x \t %d bytes \r\n",GPIOA_BASE      ,0x400203FF  - GPIOA_BASE); 
	
	/* END */
	
<<<<<<< HEAD
	/*APB2*/	
	printf("MDIOS                    \t %x \t %d bytes \r\n",MDIOS_BASE,      ,0x400103FF  - MDIOS_BASE); 
	printf("DFSDM1                   \t %x \t %d bytes \r\n",DFSDM1_BASE,     ,0x400177FF  - DFSDM1_BASE); 
 	printf("DSI Host                 \t %x \t %d bytes \r\n",,0x40016C00     ,0x400273FF  - 0x40016C00); 
	printf("LCD-HOST                 \t %x \t %d bytes \r\n",LTDC_BASE,       ,0x40016BFF  - LTDC_BASE);
	printf("SAI2                 	 \t %x \t %d bytes \r\n",SAI2_BASE,       ,0x40015FFF  - SAI2_BASE);
	printf("SAI1                 	 \t %x \t %d bytes \r\n",SAI1_BASE,       ,0x40015BFF  - SAI1_BASE);
	printf("SPI6                 	 \t %x \t %d bytes \r\n",SPI6_BASE,       ,0x400157FF  - SAI6_BASE);
	printf("SPI5                 	 \t %x \t %d bytes \r\n",SPI5_BASE,       ,0x400153FF  - SAI5_BASE);
	printf("TIM11                 	 \t %x \t %d bytes \r\n",TIM11_BASE,      ,0x40014BFF  - TIM11_BASE);
	printf("TIM10                 	 \t %x \t %d bytes \r\n",TIM10_BASE,      ,0x400147FF  - TIM10_BASE);
	printf("TIM9                 	 \t %x \t %d bytes \r\n",TIM9_BASE,       ,0x400143FF  - TIM9_BASE);
	printf("EXTI                 	 \t %x \t %d bytes \r\n",EXTI_BASE,      ,0x40013FFF   - EXTI_BASE);
	printf("SYSCFG                 	 \t %x \t %d bytes \r\n",SYSCFG_BASE,      ,0x40013BFF   - SYSCFG_BASE);
	printf("SPI4                 	 \t %x \t %d bytes \r\n",SPI4_BASE,      ,0x400137FF   - SPI4_BASE);
	printf("SPI1/I2S1                \t %x \t %d bytes \r\n",SPI1_BASE,      ,0x400133FF   - SPI1_BASE);
	printf("SDMMC1                 	 \t %x \t %d bytes \r\n",SDMMC1_BASE,      ,0x40012FFF   - SDMMC1_BASE);
	printf("ADC1-ADC2-ADC3           \t %x \t %d bytes \r\n",ADC1_BASE,      ,0x400123FF   - ADC1_BASE);
	printf("SDMMC2           	 \t %x \t %d bytes \r\n",SDMMC2_BASE,      ,0x40011FFF   - SDMMC2_BASE);
	printf("USART6           	 \t %x \t %d bytes \r\n",USART6_BASE,      ,0x400117FF   - USART6_BASE);
	printf("USART1           	 \t %x \t %d bytes \r\n",USART1_BASE,      ,0x400113FF   - USART1_BASE);
	printf("TIM8           	 	 \t %x \t %d bytes \r\n",TIM8_BASE,      ,0x400107FF   - TIM8_BASE);
	printf("TIM1           	 	 \t %x \t %d bytes \r\n",TIM1_BASE,      ,0x400103FF   - TIM1_BASE);

	/*APB1*/
	
	printf("UART8           	 \t %x \t %d bytes \r\n",USART8_BASE,      ,0x40007FFF   - UART8_BASE);
	printf("UART7           	 \t %x \t %d bytes \r\n",UART7_BASE,      ,0x40007BFF   - UART7_BASE);
	printf("DAC           	 	 \t %x \t %d bytes \r\n",DAC_BASE,      ,0x400077FF   - DAC_BASE);
	printf("PWR           	 	 \t %x \t %d bytes \r\n",PWR_BASE,      ,0x400073FF   - PWR_BASE);
	printf("HDMI-CEC           	 \t %x \t %d bytes \r\n",0x40006C00,      ,0x40006FFF   - 0x40006C00);
	printf("CAN2           	 	 \t %x \t %d bytes \r\n",CAN2_BASE,      ,0x40006BFF   - CAN2_BASE);
	printf("CAN1           	 	 \t %x \t %d bytes \r\n",CAN1_BASE,      ,0x400067FF   - CAN1_BASE);
	printf("I2C4           	 	 \t %x \t %d bytes \r\n",I2C4_BASE,      ,0x400063FF   - I2C4_BASE);
	printf("I2C3           	 	 \t %x \t %d bytes \r\n",I2C3_BASE,      ,0x40005FFF   - I2C3_BASE);
	printf("I2C2          	 	 \t %x \t %d bytes \r\n",I2C2_BASE,      ,0x40005BFF   - I2C2_BASE);
	printf("I2C1           	 	 \t %x \t %d bytes \r\n",I2C1_BASE,      ,0x400057FF   - I2C1_BASE);
	printf("UART5           	 \t %x \t %d bytes \r\n",UART5_BASE,      ,0x400053FF   - UART5_BASE);
	printf("UART4           	 \t %x \t %d bytes \r\n",UART4_BASE,      ,0x40004FFF   - UART4_BASE);
	printf("USART3           	 \t %x \t %d bytes \r\n",USART3_BASE,      ,0x40004BFF   - USART3_BASE);
	printf("USART2           	 \t %x \t %d bytes \r\n",USART2_BASE,      ,0x400047FF   - USART2_BASE);
	printf("SPDIFRX           	 \t %x \t %d bytes \r\n",SPDIFRX_BASE,      ,0x400043FF   - SDIFRX_BASE);
	printf("SPI3/I2S3           	 \t %x \t %d bytes \r\n",SPI3_BASE,      ,0x40003FFF   - SPI3_BASE);
	printf("SPI2/I2S2           	 \t %x \t %d bytes \r\n",SPI2_BASE,      ,0x40003BFF   - SPI2_BASE);
	printf("CAN3           	 	 \t %x \t %d bytes \r\n",CAN3_BASE,      ,0x400037FF   - CAN3_BASE);
	printf("IWDG           	 	 \t %x \t %d bytes \r\n",IWDG_BASE,      ,0x400033FF   - IWDG_BASE);
	printf("WWDG           	 	 \t %x \t %d bytes \r\n",WWDG_BASE,      ,0x40002FFF   - WWDG_BASE);
=======
	
	printf("MDIOS                    \t %x \t %d bytes \r\n",MDIOS_BASE      ,0x40017BFF  - MDIOS_BASE); 
	printf("DFSDM1                   \t %x \t %d bytes \r\n",DFSDM1_BASE     ,0x400177FF  - DFSDM1_BASE); 
 //	printf("DSI Host                 \t %x \t %d bytes \n",DFSDM1_BASE,     ,0x400203FF  - DFSDM1_BASE); 
	printf("LCD-HOST                 \t %x \t %d bytes \r\n",LTDC_BASE       ,0x40016BFF  - LTDC_BASE);
	printf("SAI2                 	 \t %x \t %d bytes \r\n",SAI2_BASE       ,0x40015FFF  - SAI2_BASE);
	printf("SAI1                 	 \t %x \t %d bytes \r\n",SAI1_BASE       ,0x40015BFF  - SAI1_BASE);
	printf("SPI6                 	 \t %x \t %d bytes \r\n",SPI6_BASE       ,0x400157FF  - SPI6_BASE);
	printf("SPI5                 	 \t %x \t %d bytes \r\n",SPI5_BASE       ,0x400153FF  - SPI5_BASE);
	printf("TIM11                 	 \t %x \t %d bytes \r\n",TIM11_BASE      ,0x40014BFF  - TIM11_BASE);
	printf("TIM10                 	 \t %x \t %d bytes \r\n",TIM10_BASE      ,0x400147FF  - TIM10_BASE);
	printf("TIM9                 	 \t %x \t %d bytes \r\n",TIM9_BASE       ,0x400143FF  - TIM9_BASE);
	printf("EXTI                 	 \t %x \t %d bytes \r\n",EXTI_BASE      ,0x40013FFF   - EXTI_BASE);
>>>>>>> b058e9889cefba732057b024270dc99c0516e238
	
	printf("RTC & BKP rgstrs         \t %x \t %d bytes \r\n",0x40002800,      ,0x40002BFF   - 0X40002800);
	printf("LPTIM1           	 \t %x \t %d bytes \r\n",LPTIM1_BASE,      ,0x400027FF   - LPTIM1_BASE);
	printf("TIM14          	 	 \t %x \t %d bytes \r\n",TIM14_BASE,      ,0x400023FF   - TIM14_BASE);
	printf("TIM13           	 \t %x \t %d bytes \r\n",TIM13_BASE,      ,0x40001FFF   - TIM13_BASE);
	printf("TIM12           	 \t %x \t %d bytes \r\n",TIM12_BASE,      ,0x40001BFF   - TIM12_BASE);
	printf("TIM7           	 	 \t %x \t %d bytes \r\n",TIM7_BASE,      ,0x400017FF   - TIM7_BASE);
	printf("TIM6           	 	 \t %x \t %d bytes \r\n",TIM6_BASE,      ,0x400013FF   - TIM6_BASE);
	printf("TIM5           	 	 \t %x \t %d bytes \r\n",TIM5_BASE,      ,0x40000FFF   - TIM5_BASE);
	printf("TIM4           	 	 \t %x \t %d bytes \r\n",TIM4_BASE,      ,0x40000BFF   - TIM4_BASE);
	printf("TIM3           	 	 \t %x \t %d bytes \r\n",TIM3_BASE,      ,0x400007FF   - TIM3_BASE);
	printf("TIM2           	 	 \t %x \t %d bytes \r\n",TIM2_BASE,      ,0x400003FF   - TIM2_BASE);
	return SUCCESS; 
}
 
<<<<<<< HEAD
COMMAND_ENTRY("memmap", "memmap", "Display where different physical hardware peripherals", do_memmap); 
=======
COMMAND_ENTRY("memmap", "memmap", "Display memory map of physical hardware peripherals", do_memmap) 




>>>>>>> b058e9889cefba732057b024270dc99c0516e238













