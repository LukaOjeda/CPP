#include<iostream>
#include <cstdio>
 
using namespace std;
 
int main(){
    int list[5] = {2, 6, 9, 9, 7};
    int i = 0, search = 0;
    char flag = 'F';
    
    cin >> search;
     
    while((flag == 'F') && (i<=4)){
        if(list[i] == search){
            flag = 'V';
        }
        i++;
    }
     
    if(flag == 'V'){
        printf("\nEl numero  %i ha sido encontrado en la posicion: %i", search, i - 1);
    }
	
	else{
        printf("\nEl n%cmero no se encontr%c", 163, 162);
    }
     
    return 0;
}