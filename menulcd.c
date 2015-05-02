/**
	Taller NT Menu 1.0
	
	Pines digitales:
		LCD: 
			12, 11, 5, 4, 3, 2
		Pulsadores:
			8 opcion -
			9 opcion +
			10 Aceptar
			13 Volver
			
		
	Inicio:
		About
		Menu:
			1) Encender led 
				Working LED...
				
			2) Parpadeo led
				Parpadeando ...
				
			3) About
				About
		
**/

#define Opciones 3 // Para determinar el numero de opciones y saber los limites del contador
#include <LiquidCrystal.h>



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

// Tama�o del LCD
	lcd.begin(16, 2);

// Configuracion de los pines
	/*int BotMas 9;
	int BotMen 8;
	int BotSel 10; 
	int BotRet 13;
/*
	pinMode(BotMen, INPUT);  // Opcion -
	pinMode(BotMas, INPUT);  // Opcion +
	pinMode(BotSel, INPUT); // Seleccionar
	pinMode(BotRet, INPUT); // Volver*/

	pinMode(8, INPUT);  // Opcion -
	pinMode(9, INPUT);  // Opcion +
	pinMode(10, INPUT); // Seleccionar
	pinMode(13, INPUT); // Volver
	
	
	
/** Introduccion del display **/ 
	lcd.setCursor(0,0);
	lcd.print("-->Taller NT<--");
	lcd.setCursor(0,1);
	lcd.print("    D4rkh0s7");
	delay(1600);
	
	lcd.clear();
	lcd.print("-->Taller NT<--");
	lcd.setCursor(0,1);
	lcd.print("    Menu 1.0");
	delay(1600);
	lcd.clear();
/** Fin display **/
}
int i;

int op=1;
//boolean select=false;
void loop() {

	lcd.print("Seleccione... ");
	lcd.blink();
	lcd.setCursor(0,1);
	
	

	if(digitalRead(9)==HIGH)
	{
		op++;
	}
	if(digitalRead(8)==HIGH)
	{
		op--;
	}

	if(digitalRead(10)==HIGH)
	{

		while(digitalRead(13)==LOW)
		{
			switch (op)
			{
                                float v;
				case 1:
					lcd.print("Opcion 1 ...");
					lcd.blink();
					delay(300);
					lcd.clear();
					break;
				case 2:
                                        lcd.print("Opcion 2...");
					/*                                       
                                        v=analogRead(1);
                                        v=(v/1024);
                                        v=v*5;
                    
                                        if(v<2)
                                        {
                                           lcd.print(" _");
                                        }                                   
                                        
                                        if(v>2&&v<4)
                                        {
                                           lcd.print(" /"); 
                                        }
                                        if(v>4)
                                        {
                                           lcd.print(" ¬"); 
                                          
                                        }
                                        lcd.scrollDisplayLeft();
                                        */
					
					delay(300);
					break;
				case 3:
					/*lcd.print("Opcion 3 ...");
                                        delay(300);
                                        lcd.clear();*/
                                        lcd.print("Voltimetro");
                                        lcd.setCursor(0,1);
                                        
                                        v=analogRead(1);
                                        v=(v/1024);
                                        v=v*5;
                                        
                                        lcd.print(v);
                                        lcd.print(" V");
					lcd.blink();
					delay(300);
					lcd.clear();
					break;
				default:
					lcd.print("ERROR!!!!");
					lcd.blink();		
			}
		}
	}
	
	switch(op)
	{
		case 1:
			lcd.print("1) LED");
			break;
		case 2:
			lcd.print("2) Reloj");
			break;
		case 3:
			lcd.print("3) Voltimetro");
			break;
		default:
			op=1;
				
	}
	delay(300);
	lcd.clear();
}


