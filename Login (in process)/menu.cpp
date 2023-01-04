#include <iostream>
#include <fstream>
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

void frame(int x, int y, int x2, int y2);

void gotoxy(int x, int y);

void clearLine(int lines);

void menuFrames();

void sing_in();

void sing_up();


int main(){
	system("title MANAGER");
	system("color C0");

    sing_in();

	getch();
	
	return 0;
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



void clearLine(int lines){
	for(int i = 1; i <= lines; i++){
		printf("%c", NULL);
	}
}



void menuFrames(){
    frame(0, 0, 74, 24); 
	frame(1, 1, 117, 3);
		
	frame(0, 0, 118, 24);
		
	gotoxy(30, 2); printf("BIENVENIDO\n");
	gotoxy(94, 2); printf("ASISTENTE\n", 181);
}

void sing_in(){
    menuFrames();

    string user;
    string password;

    gotoxy(78, 5); printf("Ingrese su usuario, por favor.");
    gotoxy(78, 8); printf("Si no tiene cuenta, ingrese un 0 (cero)");
    gotoxy(78, 9); printf("para registrarse.");

    gotoxy(4, 5); printf("Usuario: "); cin >> user;

    if(user == "0"){
        system("cls");

        sing_up();
    }
}



void sing_up(){
    menuFrames();
	
	ofstream accounts_file;
	
	accounts_file.open("accounts.txt", fstream::app);
	    
    string user;
    string password;

    gotoxy(78, 5); printf("Ingrese un nuevo usuario, por favor.");
    gotoxy(78, 8); printf("El mismo no debe de repetirse con otro");

    gotoxy(4, 5); printf("Usuario: "); cin >> user;
    
    accounts_file << user << endl;

    gotoxy(4, 7);  printf("Contrase%ca: ", 164); cin >> password;
    
    accounts_file << password << endl << endl;
    
    accounts_file.close();
    
    getch();
    
    sing_in();
}