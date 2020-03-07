#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NROASIGNATURAS 5
#define NROALUMNOS 3

float *mediaAlumno(float array[][NROASIGNATURAS],int nroAlumnos);
float *mediaAsignatura(float array[][NROASIGNATURAS],int nroAlumnos);
float mediaClase(float array[][NROASIGNATURAS],int nroAlumnos);
void orderPorNotas(float notas[][NROASIGNATURAS],int nroAlumnos);
void ordenacionShell(float a[], float indices[], int n);
void testMediaAlumno();
void testMediaAsignatura();
void testMediaClase();

int main(){
    float notas[3][5] = {{4.2,2.7,3,2.1,4},{3,2,5,1,4.5},{4.2,3,1.8,5,3}};
    testMediaAsignatura();
    testMediaAlumno();
    testMediaClase;
    orderPorNotas(notas,NROALUMNOS);
    return 0;
}

float *mediaAlumno(float array[][NROASIGNATURAS],int nroAlumnos){
    float *sums=malloc(nroAlumnos);
    float sum=0;
    for(int i = 0; i < nroAlumnos;i++){
        for(int j = 0; j < NROASIGNATURAS;j++){
            //sum[j]+=*(array+i*(NROASIGNATURAS)+j);
            sums[i]+=array[i][j];
        }
    }
    for(int i = 0; i < nroAlumnos;i++){
        sums[i]=sums[i]/NROASIGNATURAS;
    }
    return sums;
}

float *mediaAsignatura(float array[][NROASIGNATURAS],int nroAlumnos){
    float *sums=malloc(NROASIGNATURAS);
    for(int i = 0; i < nroAlumnos;i++){
        for(int j = 0; j < NROASIGNATURAS;j++){
            //sum[j]+=*(array+i*(NROASIGNATURAS)+j);
            sums[j]+=array[i][j];
        }
    }
    for(int i = 0; i < NROASIGNATURAS; i++){
            sums[i]=sums[i]/nroAlumnos;
            //printf("promedio asignatura %d es: %.2f \n",i,sums[i]);
    }
    return sums;
}

float mediaClase(float notas[][NROASIGNATURAS],int nroAlumnos){
    float *medias=malloc(NROASIGNATURAS);
    medias=mediaAsignatura(notas,nroAlumnos);
    float sum=0;
    for(int i = 0; i < NROASIGNATURAS; i++){
            sum+=medias[i];
    }
    printf("el promedio de la clase es: %.2f", sum/NROASIGNATURAS);
    return sum/NROASIGNATURAS;
}

void orderPorNotas(float notas[][NROASIGNATURAS],int nroAlumnos){
    float *medias=malloc(nroAlumnos);
    float *indices=malloc(nroAlumnos);
    for(int i = 0; i < nroAlumnos; i++){
            indices[i]=i;
    }
    medias=mediaAlumno(notas,nroAlumnos);
    ordenacionShell(medias,indices,nroAlumnos);
    printf("alumnos ordernados desc. por notas: \n");
    for(int i = 0; i < NROALUMNOS; i++){
            printf("alumno %.f, nota: %.2f \n",indices[i],medias[i]);
    }
}

void ordenacionShell(float a[], float indices[], int n){
	int intervalo, i, j, k;
	intervalo = n / 2;
	while (intervalo > 0){
		for (i = intervalo; i < n; i++){
			j = i - intervalo;
			while (j >= 0){
				k = j + intervalo;
				if (a[j] >= a[k]){
					j = -1;
				}else{
					float temp1;
					temp1 = a[j];
					a[j] = a[k];
					a[k] = temp1;
					float temp2;
					temp2 = indices[j];
					indices[j] = indices[k];
					indices[k] = temp2;
					j -= intervalo;
				}
			}
		}
		intervalo = intervalo / 2;
	}
}

void testMediaAlumno(){
    float *sums=malloc(NROALUMNOS);
    float notas[3][5] = {{4.2,2.7,3,2.1,4},{3,2,5,1,4.5},{4.2,3,1.8,5,3}};
    sums=mediaAlumno(notas,NROALUMNOS);
    for(int i = 0; i < NROALUMNOS; i++){
            printf("promedio alumno %d es: %.2f \n",i,sums[i]);
    }
}

void testMediaAsignatura(){
    float *sums=malloc(NROASIGNATURAS);
    float notas[3][5] = {{4.2,2.7,3,2.1,4},{3,2,5,1,4.5},{4.2,3,1.8,5,3}};
    sums=mediaAsignatura(notas,NROALUMNOS);
    for(int i = 0; i < NROASIGNATURAS; i++){
            printf("promedio asignatura %d es: %.2f \n",i,sums[i]);
    }
}
    
void testMediaClase(){
    float *sums=malloc(NROASIGNATURAS);
    float notas[3][5] = {{4.2,2.7,3,2.1,4},{3,2,5,1,4.5},{4.2,3,1.8,5,3}};
    mediaClase(notas,NROALUMNOS);
}



