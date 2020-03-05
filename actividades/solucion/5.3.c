#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define arraySize 1000

char *obtenerSubcadena(char *array, int index);
void test();


int main(){
    char array[arraySize];
    char *p2;
    int index = 0;
    printf("Ingrese un String: \n");
    fgets(array,arraySize,stdin);
    printf("Ingrese la posicion desde la que desea copiar: \n");
    scanf("%d", &index);
    p2 = obtenerSubcadena(array, index);
    if(p2 != NULL){
        printf("String 1 es = %s\n", array);
        printf("String 2 es = %s\n", p2);    
    }else{
        printf("Numero no valido");
    }
    return 0;
}


char *obtenerSubcadena(char *array, int index) {
    char *p3 = array + index + 1;
    if(index < strlen(array)){
        return p3;    
    }else{
        return NULL;    
    }
}

void test(){
    char *p2;
	char array[] = "Hola que tal";
	int index = 4;
 	p2 = obtenerSubcadena(array, index);
	if(p2 != NULL){
		printf("String 1 es = %s\n", array);
		printf("String 2 es = %s\n", p2);    
	}else{
		printf("Numero no valido");
	}
}





