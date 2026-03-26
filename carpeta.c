#include <stdio.h>
#include <stdint.h>
#include "carpeta.h"

t_data llegeix_nova_data(){

    int dia, mes, any;
    
    printf("\nData (format: dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &any);
}

void mostra_data(t_data data){

}

t_carpeta llegeix_nova_carpeta(){

}

void mostra_carpeta(t_carpeta car){

}

t_data * cerca_data(t_carpeta *car, t_data data){

}

int insereix_nova_data(t_carpeta *car, t_data data){

}

int insereix_nova_tasca(t_data *data, t_tasca tas){

}

t_tasca * cerca_tasca(t_data *data, char titol[MAX_C]){

}

int elimina_tasca(t_data *data, char titol[MAX_C]){

}

int neteja_dates_buides(t_carpeta *car){

}

