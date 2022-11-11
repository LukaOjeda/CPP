#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cfenv>
#include <sstream>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

using namespace std;

void program();

void frame(int x, int y, int x2, int y2);

void gotoxy(int x, int y);

void stringsComparison();

void minorMajor();

void calculator();

void clearLine(int lines);



int main(){
	system("title Calculadora");
	system("color C0");
	
	char choice[1];
	string yes = "S";
	string no = "N";
	
	do{
		system("cls");
		
		frame(0, 0, 74, 24); 
		frame(1, 1, 117, 3);
		
		frame(0, 0, 118, 24);
		
		gotoxy(30, 2); cout << "CALCULADORA" << endl;
		gotoxy(94, 2); printf("DI%CLOGOS\n", 181);
		
		program();

		do{
			gotoxy(77, 6); printf("%cDesea realizar otra operaci%cn?", 168, 162);
			gotoxy(77, 8); printf("S/N: ");
			scanf("%s", &choice);
			strupr(choice);
		
			if(choice != yes && choice != no){
				gotoxy(77, 10); printf("Por favor, responda con S o N.");
			}
		}while(choice != yes && choice != no);
	}while(choice == yes);
	
	gotoxy(77, 4); clearLine(40);
	gotoxy(77, 4); printf("%cMuchas gracias po usar este programa!", 173); 
	gotoxy(77, 6); clearLine(40);
	gotoxy(77, 16); clearLine(40);
	gotoxy(77, 18); clearLine(40);
	getch();
	
	return 0;
}



void program(){
	char number[8];
	int choice;
	int cont = 0;
	
	gotoxy(2, 4); printf("Ingrese la opci%cn que desee ejecutar: ", 162);
	gotoxy(2, 6);printf("1: comparar dos palabras ingresadas.");
	gotoxy(2, 8);printf("2: hallar el menor y mayor.");
	gotoxy(2, 10);printf("3: calcular potencias.");
	
	do{
		gotoxy(77, 4); printf("Ingrese una opci%cn dependiendo del", 162); 
		gotoxy(77, 6); printf("n%cmero de la operaci%cn (1, 2, 3).", 163, 162);
		gotoxy(2, 12); printf("Opci%cn a elegir: ", 162);
		cin >> choice;
		
		switch(choice){
			case 1:
				stringsComparison();
			break;
			
			case 2:
				minorMajor();
			break;
			
			case 3:
				calculator();
			break;
			
			default:
				gotoxy(77, 16); printf("La opci%cn no es v%clida.", 162, 160);
				gotoxy(77, 18); printf("Por favor, use opciones entre 1 y 3."); 
				Sleep(2);	
		}
	} while(choice > 4 or choice < 1);
}



void gotoxy(int x, int y){   
	HANDLE hcon;    
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}



void frame(int x, int y, int x2, int y2){
	for(int i = x; i < x2; i++){
		gotoxy(i, y); cout << "\304";
		gotoxy(i, y2); cout <<"\304";
	}
	
	for(int i = y; i < y2; i++){
		gotoxy(x, i); cout << "\263";
		gotoxy(x2, i); cout << "\263";
	}
	
	gotoxy(x, y); cout << "\332"; 
    gotoxy(x, y2); cout << "\300";
    gotoxy(x2, y); cout << "\277";
    gotoxy(x2, y2); cout << "\331";
	
}



void stringsComparison(){
	string firtstWord;
	string secondWord;
	gotoxy(2, 14); printf("Ingrese las palabras.");
	gotoxy(2, 16); cout <<": "; cin >> firtstWord;
	gotoxy(2, 18); cout << ": "; cin >> secondWord;
				
	if(strcasecmp(firtstWord.c_str(), secondWord.c_str()) == 0){
		gotoxy(2, 20); printf("Las cadenas son iguales.");
	}
	
	else{
		gotoxy(2, 20); printf("Las cadenas NO son iguales.");
	}
}



void minorMajor(){
	int vec[10];
	int x = 2, y = 16, minor = 1410065407, major = -1410065407;
	
	gotoxy(2, 14); printf("Ingrese 10 n%cmeros.", 163);
	for(int i = 0; i < 10; i++){
		gotoxy(x, y+i); cout << ":"; cin >> vec[i];
		if(i == 4){
			x = 6;
			y = 11; 
		}
		
		if(vec[i] < minor){
			minor = vec[i];
		}
		
		if(vec[i] > major){
			major = vec[i];
		}
	}
	
	gotoxy(12, 16); printf("El valor mayor es: %i", major);
	gotoxy(12, 18); printf("El valor menor es: %i", minor);
}



void calculator(){
	int number = 0;
	int exponent = 0;
	int result;
	
	gotoxy(2, 14); printf("Ingrese un n%cmero.", 163);
	gotoxy(2, 16); cin >> number;
	
	gotoxy(2, 18); printf("Ingrese un exponente.");
	gotoxy(2, 20); cin >> exponent;

	result = pow(number, exponent);
	
	gotoxy(2, 22); printf("El resultado del n%cmero elevado a %i es de: %i", 163, exponent, result);
}



void clearLine(int lines){
	for(int i = 1; i <= lines; i++){
		printf("%c", NULL);
	}
}
