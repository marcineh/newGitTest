///*
// * main.c
// *
// *  Created on: 22 mar 2020
// *      Author: marci
// */


#include <avr/io.h>
#include <util/delay.h>

int main(void){
	DDRC |= (1<<PC3);
	while(1){
		PORTC ^= (1<<PC3);
		_delay_ms(1000);
	}
}


////MIGOCZ¥CA DIODA - OPIS BITOWY
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main(void){
//	DDRB = 0b00000100;  //ustawienie bitu nr 2 rejestru kierunku DDR portu B na wyjœcie
//						//1 - wyjœcie, 0 - wejœcie, domyœlnie ca³y rejestr ustawiony jako wejœcie
//	while(1){
//		PORTB = 0b00000000;	//ustaw bity rejestru wyjœciowego PORT portu B na stan niski (0)
//							//domyœlnie ca³y rejestr ustawiony na 0, podanie stanu niskiego (0)
//							//przy pod³¹czeniu diody katod¹ do GND spowoduje jej zapalenie
//							//podanie stanu wyskokiego (1) zgaœniêcie
//		_delay_ms(1000);	//czas œwiecenia diody
//		PORTB = 0b00000100; //ustaw bit nr 2 rejestru wyjœciowego PORT portu B na stan wysoki (1)
//							//- zgaœ diodê
//		_delay_ms(1000);	//czas zgaszenia diody
//	}
//}


////OBS£UGA KLAWISZA - OPIS BITOWY
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdbool.h>
//
//int main(void)
//{
//	DDRB = 0b00000100;  	//ustawienie bitu nr 2 rejestru kierunku DDR portu B jako wyjœcie (dioda),
//							//a bit nr 3 i pozosta³e bity jako wejœcie (przycisk)
//							//1 - wyjœcie, 0 - wejœcie, domyœlnie ca³y rejestr ustawiony jako wejœcie
//	PORTB = 0b11111111;		//ustawnienie pocz¹tkowych wartoœci rejestru wyjœciowego - dioda zgaszona na
//							//bice nr 2 - stan wysoki 1 i podci¹gniêcie lini wejœciowej na pozosta³ych
//							//bitach - wymuszenie stanu wysokiego 1 (VCC) na wejœciu (podci¹ganie do VCC)
//
////	PINB = 0b11111111;		//po podci¹gniêciu do VCC tak wygl¹da rejestr wejœciowy PINB
//
////	LED_ON = 0b00001000;	//ustawienie bitu nr 2 wyjœciowego PORT portu B na stan niski - za³¹czenie diody
////							//oraz ustawienie bitu nr 3 na stan wysoki - podci¹gniêcie lini wejœciowej za
////							//pomoc¹ wewnêtrznego rezystora do VCC
////							//dioda œwieci
////	LED_OFF = 0b00001100; 	//dioda zgaszona
//
//	bool A = 1; //zmienna boolowska, która ma za zadanie pamiêtac czy dioda jest zapalona 1 = tak
//
//	while(1)
//	{
//		//sprawdzenie jaki stan panuje na bicie nr 3 rejestru wyjœciowego - jeœli 0 - stan niski
//		//przycisk jest wciœniêty i dioda zgaszona
//		if ((PINB == 0b11110111) & (A == 1))
//		{
//			_delay_ms(80);	//czas drgañ styków
//			if ((PINB == 0b11110111) & (A == 1))
//			{
//				PORTB = 0b11111011; //zapal diode
////				_delay_ms(1000);	//czas œwiecenia diody
//				A = 0;
//			}
//		}
//
//		//sprawdzenie jaki stan panuje na bicie nr 3 rejestru wyjœciowego - jeœli 0 - stan niski
//		//przycisk jest wciœniêty i dioda zapalona
//		if ((PINB == 0b11110011) & (A == 0))
//		{
//			_delay_ms(80);	//czas drgañ styków
//			if ((PINB == 0b11110011) & (A == 0))
//			{
//				PORTB = 0b11111111;  //zgaœ diodê
////				_delay_ms(100);	//czas zgaszenia diody
//				A = 1;
//			}
//		}
//
//	}
//}


////MIGOCZ¥CA DIODA - MAKRA
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define LED_PIN1 (1<<PB0 | 1<<PB2) 	//definicja pinu, do którego pod³¹czona jest dioda
//#define LED_PIN2 (1<<PB1) 			//definicja pinu, do którego pod³¹czona jest dioda
//#define LED_ON PORTB &= ~LED_PIN1 	//ustaw stan niski na pine - zapal diodê
//#define LED_OFF PORTB |= LED_PIN1	//ustaw stan wysoki na pinie - zgaœ diodê
//#define LED_TOG PORTB ^= LED_PIN2 	//zmien stan na pinie
//
//int main(void)
//{
//	DDRB |= (LED_PIN1 | LED_PIN2); 	//ustaw stan wysoki na pinach - ustaw pin jako wyjœcia
//	while(1)
//	{
//		LED_TOG;
//		LED_ON;
//		_delay_ms(1000);
//		LED_OFF;
//		_delay_ms(1000);
//	}
//}


////OBS£UGA KLAWISZA - MAKRA
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define LED_PIN (1<<PB0) 			//definicja pinu, do którego pod³¹czona jest dioda
//#define KEY_PIN (1<<PB1)			//definicja pinu, do którego pod³¹czony jest przycisk
//#define KEY_DOWN !(PINB & KEY_PIN) 	//makro sprawdzaj¹ce czy przycisk jest wcisniety - czy jest stan niski na pinie
//#define LED_TOG PORTB ^= LED_PIN	//zmien stan na diodzie
//
//
//int main(void)
//{
//	//inicjalizacja
//	DDRB |= LED_PIN;				//ustaw na wyjscie pin z dioda
//	PORTB |= LED_PIN;				//zgaœ diodê
//
//	DDRB &= ~KEY_PIN;				//ustaw na wejœcie pin z przyciskiem
//	PORTB |= KEY_PIN;				//podci¹gnij pod VCC
//
//	while(1)
//	{
//		if(KEY_DOWN)				//jesli klawisz wcisniety - stan niski na pinie w rejesrze PINB
//		{
//			_delay_ms(80);			//czas drgañ styków
//			if(KEY_DOWN)
//			{
//				LED_TOG;
//				_delay_ms(80);
//			}
//		}
//	}
//}


////OBS£UGA KLAWISZA - Z FUNKCJA
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define LED_PIN (1<<PB0) 			//definicja pinu, do którego pod³¹czona jest dioda
//#define KEY_PIN1 (1<<PB1)			//definicja pinu, do którego pod³¹czony jest przycisk 1
//#define KEY_PIN2 (1<<PB2)			//definicja pinu, do którego pod³¹czony jest przycisk 2
//#define KEY_PIN3 (1<<PB3)			//definicja pinu, do którego pod³¹czony jest przycisk 3
//#define LED_TOG PORTB ^= LED_PIN	//zmien stan na diodzie
//#define LED_OFF PORTB |= LED_PIN	//zgas diode
//#define LED_ON PORTB &= ~LED_PIN	//zapal diode
//
////deklaracja funkcji sprawdzajacej czy klawisz wcisniety
//uint8_t klawisz_wcisniety(uint8_t klawisz);
//
//int main(void)
//{
//	//inicjalizacja
//	DDRB |= LED_PIN;				//ustaw na wyjscie pin z dioda
//	PORTB |= LED_PIN;				//zgaœ diodê
//
//	DDRB &= ~(KEY_PIN1 | KEY_PIN2 | KEY_PIN3);
//	//ustaw na wejœcie pin z przyciskiem
//
//	PORTB |= KEY_PIN1 | KEY_PIN2 | KEY_PIN3;
//	//podciagnij pod VCC
//
//
//	while(1)
//	{
//		if(klawisz_wcisniety(KEY_PIN1))		//zmien stan diody
//		{
//			LED_TOG;
//		}
//
//		if(klawisz_wcisniety(KEY_PIN2))		//zgas diode
//		{
//			LED_OFF;
//		}
//
//		if(klawisz_wcisniety(KEY_PIN3))		//zapal diode
//		{
//			LED_ON;
//		}
//	}
//}
//
////definicja funkcji sprawdzajacej czy klawisz wcisniety
//uint8_t klawisz_wcisniety(uint8_t klawisz)
//{
//	if(!(PINB & klawisz))
//		{
//		_delay_ms(80);
//		if(!(PINB & klawisz))
//			{
//				return 1; //jesli wcisniety zakoncz - wyniki = 1
//			}
//		}
//	return 0; //jesli nie wcisniety zakoncz - wyniki = 0
//}
