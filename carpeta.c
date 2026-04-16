#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "tasca.h"
#include "carpeta.h"

t_data llegeix_nova_data(){

    int dia, mes, any, data;
    t_data c_data;
    printf("\nData (format: dd/mm/aaaa): ");
    scanf("%d/%d/%d%*c", &dia, &mes, &any);
    
    data = any*10000 + mes*100 + dia;
    
    c_data.data = data;
    return c_data;
}

void mostra_data(t_data data){

    int any, mes, dia, i;
    any = data.data/10000;
    mes = (data.data / 100) % 100;
    dia = data.data % 100;
    
    printf("%d/%d/%d\n", dia, mes, any);
    
    for (i = 0; i < data.ntasques; i++){
        mostra_tasca(data.pendents[i]);
    }
}

t_carpeta llegeix_nova_carpeta(){
    t_carpeta carpeta;
    char titol[MAX_C];
    printf("Introdueix el titol de la nova carpeta: ");
    fgets(titol, MAX_C, stdin);
    
    strcpy(carpeta.titol, titol);
    
    return carpeta;
}

void mostra_carpeta(t_carpeta car){
    int i;
    
    printf("\nTitol de la carpeta: %s", car.titol);
    
    
    for (i = 0; i < car.ndates; i++){
        mostra_data(car.dates[i]);
    }
}

t_data * cerca_data(t_carpeta *car, t_data data){

    int i;
    
    for (i = 0; i < car->ndates; i++){
        
        if (car->dates[i].data == data.data){
            return (&car->dates[i]);
            
        }
    }
    
    return NULL;
    
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

