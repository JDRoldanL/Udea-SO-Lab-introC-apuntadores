/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int obtenerIndice(char *array, char ch);
void test();

int main(){
    char array;
    char ch;
    printf("Ingrese un String: \n");
    //scanf("%s", array);
    gets(array);
    printf("Ingrese el caracter que desea buscar dentro del String: \n");
    scanf(" %c", &ch);
    printf("car : %c \n", ch);
    int res = encontrarCaracter(array, ch);
    if(res == -1){
        printf("No existe ningún caracter %c dentro del %s", ch, array);
    }else{
        printf("El caracter %c aparece en el índice %d dentro del string \" %s \"", ch, res, array);
    }
    //test();
}

/**
 *   @brief  Obtiene el indice de la primera aparicion de un caracter en un array
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a ingresa
 *   @return el indice del primer ch en la cadena array
 */
 
int obtenerIndice(char *array, char ch) {
    int i = 0;
    while(*(array+i) != '\0'){
        //printf("caracter: %c \n index: %d \n", *(array+i), i);
        if(*(array+i) == ch){
            return i;
        }
        i++;
    }
    return -1;
}

void test(){
    char array[]="nasdfas";
    char ch='f';
    int res = obtenerIndice(array, ch);
    if(res == -1){
        printf("No existe ningún caracter %c dentro del string %s", ch, array);
    }else{
        printf("El caracter %c aparece en el índice %d dentro del string \" %s \"", ch, res, array);
    }
    ch='x';
    res = obtenerIndice(array, ch);
    if(res == -1){
        printf("No existe ningún caracter %c dentro del string %s", ch, array);
    }else{
        printf("El caracter %c aparece en el índice %d dentro del string \" %s \"", ch, res, array);
    }
}


