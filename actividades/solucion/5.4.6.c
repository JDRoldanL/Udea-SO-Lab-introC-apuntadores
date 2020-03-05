#include <stdio.h>
#include <stdlib.h>

float mediana(float array[],int size);
void testMediana(void);
void ordenacionShell(float a[], int n);

int main(){
    //testMediana();
    int size;
    int flag=0;
    while(flag==0){
        printf("Ingrese el tamaño de array (debe ser impar): \n");
        scanf("%d", &size);
        
        if(size%2==0){
            flag=0;
        }else{
            flag=1;
        }
    }
    printf("tamaño: %d \n", size);
    float array[size];
    for (int i=0 ; i<size ; i++) {
        printf("Ingrese el número en la posición %d: \n",i);
        scanf("%f",array+i);
    }
    ordenacionShell(array,size);
    for (int i=0 ; i<size ; i++) {
        printf("%.2f , ",*(array+i));
    }
    float median=mediana(array,size); 
    printf("la mediana es %f \n", median);
}

float mediana(float array[],int size) {
    printf("tamaño: %d \n", size);

    return *((array+(size+1)/2)-1);
}

void testMediana(void) {
    float array[]={ 3,11, 1, 6, 7, 3, 12, 8, 9};
    int size = sizeof(array)/sizeof(array[0]);  
    ordenacionShell(array,size);
    float median=mediana(array,size); 
    for (int i=0 ; i<size ; i++) {
        printf("%.2f , ",*(array+i));
    }

    printf("tamaño: %d \n", (int)sizeof(array));
    printf("la mediana es %f \n", median);
}

void ordenacionShell(float a[], int n){
	int intervalo, i, j, k;
	intervalo = n / 2;
	while (intervalo > 0){
		for (i = intervalo; i < n; i++){
			j = i - intervalo;
			while (j >= 0){
				k = j + intervalo;
				if (a[j] <= a[k]){
					j = -1;
				}else{
					float temp;
					temp = a[j];
					a[j] = a[k];
					a[k] = temp;
					j -= intervalo;
				}
			}
		}
		intervalo = intervalo / 2;
	}
}




