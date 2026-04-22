/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include "organitzador.h"
#include "carpeta.h"
#include "tasca.h"
#include <stdio.h>
#include <string.h>


t_carpeta * cerca_carpeta(t_organitzador *org, char titol[MAX_C]){
    int i;

    
    for (i=0 ;i < org->ncarpetes;i++){
        if (strcmp(org->carpetes[i].titol, titol) == 0){
            return(&org->carpetes[i]);
        }  
        
    }    
    
    return NULL;
    
}

/* strcmp (A,B) <0 VA ABANS AL DICCIONARI PERO strcmp (B,A) >0
 * si retorna 1 en la posició 3, sabem que el seguent és mes gran
  
  
  
 */
int insereix_nova_carpeta(t_organitzador *org, t_carpeta car) {

    int i,j, pos = org->ncarpetes;

    if (org->ncarpetes >= MAX_CAR)
        return (-1);
    else {
        for (i = 0; i < org->ncarpetes; i++) {
            if (strcmp(org->carpetes[i].titol, car.titol) > 0) { /* Quan el primer deixi de ser mes petit que el segon */
                pos = i;
                break;
            }
            
        }
        for (j=org->ncarpetes-1;j>=pos;j--){
            org->carpetes[j+1] = org->carpetes[j];
            
        }
        org->carpetes[pos] = car;
        org->ncarpetes++;
        return(0);


    }
}

void mostra_carpetes(t_organitzador *org){
    int i;
    for (i=0;i < org->ncarpetes;i++){
        printf("%s\n", org->carpetes[i].titol);
    }

}
void mostra_contingut_carpeta(t_organitzador *org, char titol[MAX_C]){

    int i,j,k,co=0;
    t_carpeta *car;
    
    car = cerca_carpeta(org,titol);
    
    if (car == NULL)
        printf("Carpeta no trobada.\n");
    else
        mostra_carpeta(*car);

}
void neteja_dates_buides_carpetes(t_organitzador *org){
    int i,counter=0;
    
    for (i=0;i<org->ncarpetes;i++){
        counter = neteja_dates_buides(&org->carpetes[i]);
        printf("Carpeta: %s\n", org->carpetes[i].titol);
        printf("%d dates eliminades.\n", counter);
        
        
    }
    
    
    
}




int elimina_carpeta(t_organitzador *org, char titol[MAX_C]){
    int j,i=0,index = -1;
    
    for (i=0; i < org->ncarpetes;i++){ /*troba el index de eliminar */
        if (strcmp(org->carpetes[i].titol, titol) == 0)
            index = i;
    }
    if (index == -1)
        return(-1);
    
    for (j= index; j<org->ncarpetes-1;j++){
        org->carpetes[j] = org->carpetes[j+1];
        
    }
    org->ncarpetes --;
    return(0);
    
    
    
}
