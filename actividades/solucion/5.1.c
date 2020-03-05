#include <stdio.h>
#include <stdlib.h>

void test();
int contarCaracter(char *array, char ch);


int main(){
    char array[10];
    char ch;
    printf("Ingrese un String: \n");
    scanf("%s", array);
    printf("Ingrese el caracter que desea buscar dentro del String: \n");
    scanf(" %c", &ch);
    printf("car : %c \n", ch);
    int res = contarCaracter(array, ch);
    if(res == -1){
        printf("No existe ningun caracter %c dentro del %s", ch, array);
    }else{
        printf("Existen %d caracteres %c dentro del string \" %s \"", res,  ch, array);
    }
    //test();
    
}

/**
 *   @brief  Cuenta las veces que aparece un caracter determinado dentro de una cadena.
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a averiguar
 *   @return el numero de veces que aparece ch en array o -1 si no aparece.
 */
 
int contarCaracter(char *array, char ch) {
    int contador = 0;
    int i = 0;
    while(*(array+i) != '\0'){
        printf("caracter: %c \n index: %d \n", *(array+i), i);
        if(*(array+i) == ch){
            contador++;
        }
        i++;
    }
    if(contador == 0){
        return -1;
        
    }else{
        return contador;
    }
}

void test(){
    char array[]="nasdfas";
    char ch='a';
    int res = contarCaracter(array, ch);
    if(res == -1){
        printf("No existe ningun caracter %c dentro del %s", ch, array);
    }else{
        printf("Existen %d caracteres %c dentro del string \" %s \"", res,  ch, array);
    }    
    ch='x';
    res = contarCaracter(array, ch);
    if(res == -1){
        printf("No existe ningun caracter %c dentro del %s", ch, array);
    }else{
        printf("Existen %d caracteres %c dentro del string \" %s \"", res,  ch, array);
    }    
}

