#include <stdio.h>

int main(){
    int array1[] = {-1, 5, 12, 7, 19, 3, -4, 8, 15, 0};
	int array2[] = {26, 6, 13, -5, 20, 11, -20, 2, 17, 9};
    
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    
    int menorDistancia = 10000000; 
    int num1, num2;

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            int distancia = array1[i] - array2[j];
            if(distancia < 0){
                distancia = -distancia;
            }
            if (distancia < menorDistancia) {
                menorDistancia = distancia;
                num1 = array1[i];
                num2 = array2[j];
            }
        }
    }

    printf("A menor distancia eh %d entre os numeros %d e %d.\n", menorDistancia, num1, num2);

    return 0;
}
