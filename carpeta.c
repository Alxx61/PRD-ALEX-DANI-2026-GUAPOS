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
    
    printf("%02d/%02d/%04d\n", dia, mes, any);
    
    for (i = 0; i < data.ntasques; i++){
        mostra_tasca(data.pendents[i]);
    }
}

t_carpeta llegeix_nova_carpeta(){
    t_carpeta carpeta;
    char titol[MAX_C];
    printf("\nIntrodueix el titol de la nova carpeta: ");
    llegeix_text(titol);
    
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

    int i, pos = 0;
    
    if (car->ndates >= MAX_DAT){
        return -1;
    }else{
        
        while(pos < car->ndates && car->dates[pos].data < data.data){
            pos++;
        }
    
    for (i = car->ndates; i > pos; i--){
        car->dates[i] = car->dates[i - 1];
    }
    car->dates[pos] = data;
    car->ndates++;
    return 0;
    
    }
}

int insereix_nova_tasca(t_data *data, t_tasca tas){

    int i, pos = 0;
    
    if (data->ntasques > MAX_TAS){
        return -1;
    }else{
        
        while(pos < data->ntasques && data->pendents[pos].prioritat > tas.prioritat){
            pos++;
        }
    
        for (i = data->ntasques; i > pos; i--){
            data->pendents[i] = data->pendents[i - 1];
        }
        data->pendents[pos] = tas;
        data->ntasques++;
        return 0;
        }
}

t_tasca * cerca_tasca(t_data *data, char titol[MAX_C]){

    int i;
    
    for (i = 0; i < data->ntasques; i++){
        if (strcmp(data->pendents[i].titol, titol) == 0){
            return (&data->pendents[i]);
        
        }
    }
    return NULL;
}

int elimina_tasca(t_data *data, char titol[MAX_C]){

    int i, pos, estat = 0;
    for (i = 0; i < data->ntasques; i++){
    
        if (strcmp(cerca_tasca(data, titol)->titol, titol) == 0){
            pos = i;
            estat = 1;
        }
    }
    if (estat == 0){
        return -1;
    }else{
    
    for (i = pos - 1; i < data->ntasques; i++){
        data->pendents[i] = data->pendents[i+1];
    }
    data->ntasques--;
    return 0;
    }  
}

int neteja_dates_buides(t_carpeta *car){
    int i, j, elim = 0;
    
    for (i = 0; i < car->ndates; i++){
        if (car->dates[i].ntasques == 0){
        
            for (j = i - 1; j < car->ndates; j++){
                car->dates[j] = car->dates[j+1];
            }
            
            elim++;
        }
    }
    
    car->ndates = car->ndates - elim;
    
    return elim;
}

