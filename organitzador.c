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
        printf("Nom de la carpeta %d: %s\n",i,org->carpetes[i].titol);
    }

}
void mostra_contingut_carpeta(t_organitzador *org, char titol[MAX_C]){

    int i,j,k,co=0;
    
    for (i=0 ;i < org->ncarpetes;i++){
        if (strcmp(org->carpetes[i].titol, titol) == 0){
            printf("%s\n",titol);
            printf("Dates: \n");
            for (j=0; j< org->carpetes[i].ndates;j++){
                mostra_data(org->carpetes[i].dates[j]);
  
            }
        }  
        
    }
    for (k=0; k < org->ncarpetes;k++){ 
        if (strcmp(org->carpetes[k].titol, titol) == 0)
            co++;
    }
    if (co == 0)
        printf("No s'ha trobat la carpeta\n");

}
void neteja_dates_buides_carpetes(t_organitzador *org){
    int i,counter=0;
    
    for (i=0;i<org->ncarpetes;i++){
        counter = neteja_dates_buides(&org->carpetes[i]);
        printf("Nombre de dates eliminades a %s: %d\n",org->carpetes[i].titol,counter);
        
        
    }
    
    
    
}




int elimina_carpeta(t_organitzador *org, char titol[MAX_C]){
    int j,i=0,index = -1;
    
    for (i=0; i < org->ncarpetes;i++){ /*Troba el index de eliminar */
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
