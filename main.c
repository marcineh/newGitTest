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


// GITHUB TEST


////MIGOCZĄCA DIODA - OPIS BITOWY
//#include <avr/io.h>
//#include <util/delay.h>
//
//int main(void){
//	DDRB = 0b00000100;  //ustawienie bitu nr 2 rejestru kierunku DDR portu B na wyjście
//						//1 - wyjście, 0 - wejście, domyślnie cały rejestr ustawiony jako wejście
//	while(1){
//		PORTB = 0b00000000;	//ustaw bity rejestru wyjściowego PORT portu B na stan niski (0)
//							//domyślnie cały rejestr ustawiony na 0, podanie stanu niskiego (0)
//							//przy podłączeniu diody katodą do GND spowoduje jej zapalenie
//							//podanie stanu wyskokiego (1) zgaśnięcie
//		_delay_ms(1000);	//czas świecenia diody
//		PORTB = 0b00000100; //ustaw bit nr 2 rejestru wyjściowego PORT portu B na stan wysoki (1)
//							//- zgaś diodę
//		_delay_ms(1000);	//czas zgaszenia diody
//	}
//}


////OBSŁUGA KLAWISZA - OPIS BITOWY
//#include <avr/io.h>
//#include <util/delay.h>
//#include <stdbool.h>
//
//int main(void)
//{
//	DDRB = 0b00000100;  	//ustawienie bitu nr 2 rejestru kierunku DDR portu B jako wyjście (dioda),
//							//a bit nr 3 i pozostałe bity jako wejście (przycisk)
//							//1 - wyjście, 0 - wejście, domyślnie cały rejestr ustawiony jako wejście
//	PORTB = 0b11111111;		//ustawnienie początkowych wartości rejestru wyjściowego - dioda zgaszona na
//							//bice nr 2 - stan wysoki 1 i podciągnięcie lini wejściowej na pozostałych
//							//bitach - wymuszenie stanu wysokiego 1 (VCC) na wejściu (podciąganie do VCC)
//
////	PINB = 0b11111111;		//po podciągnięciu do VCC tak wygląda rejestr wejściowy PINB
//
////	LED_ON = 0b00001000;	//ustawienie bitu nr 2 wyjściowego PORT portu B na stan niski - załączenie diody
////							//oraz ustawienie bitu nr 3 na stan wysoki - podciągnięcie lini wejściowej za
////							//pomocą wewnętrznego rezystora do VCC
////							//dioda świeci
////	LED_OFF = 0b00001100; 	//dioda zgaszona
//
//	bool A = 1; //zmienna boolowska, która ma za zadanie pamiętac czy dioda jest zapalona 1 = tak
//
//	while(1)
//	{
//		//sprawdzenie jaki stan panuje na bicie nr 3 rejestru wyjściowego - jeśli 0 - stan niski
//		//przycisk jest wciśnięty i dioda zgaszona
//		if ((PINB == 0b11110111) & (A == 1))
//		{
//			_delay_ms(80);	//czas drgań styków
//			if ((PINB == 0b11110111) & (A == 1))
//			{
//				PORTB = 0b11111011; //zapal diode
////				_delay_ms(1000);	//czas świecenia diody
//				A = 0;
//			}
//		}
//
//		//sprawdzenie jaki stan panuje na bicie nr 3 rejestru wyjściowego - jeśli 0 - stan niski
//		//przycisk jest wciśnięty i dioda zapalona
//		if ((PINB == 0b11110011) & (A == 0))
//		{
//			_delay_ms(80);	//czas drgań styków
//			if ((PINB == 0b11110011) & (A == 0))
//			{
//				PORTB = 0b11111111;  //zgaś diodę
////				_delay_ms(100);	//czas zgaszenia diody
//				A = 1;
//			}
//		}
//
//	}
//}


////MIGOCZĄCA DIODA - MAKRA
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define LED_PIN1 (1<<PB0 | 1<<PB2) 	//definicja pinu, do którego podłączona jest dioda
//#define LED_PIN2 (1<<PB1) 			//definicja pinu, do którego podłączona jest dioda
//#define LED_ON PORTB &= ~LED_PIN1 	//ustaw stan niski na pine - zapal diodę
//#define LED_OFF PORTB |= LED_PIN1	//ustaw stan wysoki na pinie - zgaś diodę
//#define LED_TOG PORTB ^= LED_PIN2 	//zmien stan na pinie
//
//int main(void)
//{
//	DDRB |= (LED_PIN1 | LED_PIN2); 	//ustaw stan wysoki na pinach - ustaw pin jako wyjścia
//	while(1)
//	{
//		LED_TOG;
//		LED_ON;
//		_delay_ms(1000);
//		LED_OFF;
//		_delay_ms(1000);
//	}
//}


////OBSŁUGA KLAWISZA - MAKRA
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define LED_PIN (1<<PB0) 			//definicja pinu, do którego podłączona jest dioda
//#define KEY_PIN (1<<PB1)			//definicja pinu, do którego podłączony jest przycisk
//#define KEY_DOWN !(PINB & KEY_PIN) 	//makro sprawdzające czy przycisk jest wcisniety - czy jest stan niski na pinie
//#define LED_TOG PORTB ^= LED_PIN	//zmien stan na diodzie
//
//
//int main(void)
//{
//	//inicjalizacja
//	DDRB |= LED_PIN;				//ustaw na wyjscie pin z dioda
//	PORTB |= LED_PIN;				//zgaś diodę
//
//	DDRB &= ~KEY_PIN;				//ustaw na wejście pin z przyciskiem
//	PORTB |= KEY_PIN;				//podciągnij pod VCC
//
//	while(1)
//	{
//		if(KEY_DOWN)				//jesli klawisz wcisniety - stan niski na pinie w rejesrze PINB
//		{
//			_delay_ms(80);			//czas drgań styków
//			if(KEY_DOWN)
//			{
//				LED_TOG;
//				_delay_ms(80);
//			}
//		}
//	}
//}


////OBSŁUGA KLAWISZA - Z FUNKCJA
//#include <avr/io.h>
//#include <util/delay.h>
//
//#define LED_PIN (1<<PB0) 			//definicja pinu, do którego podłączona jest dioda
//#define KEY_PIN1 (1<<PB1)			//definicja pinu, do którego podłączony jest przycisk 1
//#define KEY_PIN2 (1<<PB2)			//definicja pinu, do którego podłączony jest przycisk 2
//#define KEY_PIN3 (1<<PB3)			//definicja pinu, do którego podłączony jest przycisk 3
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
//	PORTB |= LED_PIN;				//zgaś diodę
//
//	DDRB &= ~(KEY_PIN1 | KEY_PIN2 | KEY_PIN3);
//	//ustaw na wejście pin z przyciskiem
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
