#include<iostream>
 
using namespace std;
 
int main(){
    int list[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int iDown = 0, iSuperior = 0, iCenter = 0, key = 0;
    char flag = 'F';
     
    key = 20;
     
    iInferior = 0;
    iSuperior = 9;
     
    while (iInferior <= iSuperior) {
         
        iCentro = (iInferior + iSuperior)/2;
         
        if (list[iCentro] == key){
            flag = 'V';
            break;
        } else if (list[iCenter] > key){
            iSuperior = iCenter -1;
        } else {
            iInferior = iCenter +1;
        }
    } 
     
    if (flag == 'V'){
    	printf("El n%cmero ha sido encontrado en la pósici%cn %i", 163, 162, iCenter);
    } else if (flag == 'F'){
        printf("No se ha encontrado el n%cmero en la lista.", 163);
    }
         
    return 0;
}