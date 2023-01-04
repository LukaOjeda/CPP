#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main(){
    int list[12] = {3, 2, 6, 9, 9, 7, 1, 3, 3, 2, 3, 8};
    int i = 0, search = 0;
    char result[5] = {'F', 'F', 'F', 'F', 'F'};
     
    printf("Ingrese un n%cmero: ", 163);
    cin >> search;
     
     
    for (i = 0; i <= 12; i++){
        if (list[i] == search){
            result[i] = 'V';
        }
    }
     
    i = 0;
     
    for (int j = 0; j <= 4; j++){
        if (result[j] == 'V'){
        	printf("Se encontr%c el n%cmero %i en la posici%in %i", 162, 163, search, 162, j)
            i++;
        }
    }
     
    printf ("El n%cmero se encontr%c %i veces", 163, 162, search);
     
    return 0;
}