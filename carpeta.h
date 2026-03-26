/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef CARPETA_H
#define CARPETA_H

#include "tasca.h"

#define MAX_TAS 10      /* Nombre màxim de tasques */
#define MAX_DAT 10      /* Nombre màxim de dates   */

typedef struct
{
   int data;                    /* Data representada en format aaaammdd  */
   int ntasques;                /* Nombre de tasques pendents afegides   */
   t_tasca pendents[MAX_TAS];   /* Tasques afegides a la data            */
}t_data;

typedef struct
{
    char titol[MAX_C];          /* Títol de la carpeta                    */
    int ndates;                 /* Nombre de dates afegides a la carpeta  */
    t_data dates[MAX_DAT];      /* Dates afegides a la carpeta            */ 
}t_carpeta;

t_data llegeix_nova_data();
void mostra_data(t_data data);
t_carpeta llegeix_nova_carpeta();
void mostra_carpeta(t_carpeta car);
t_data * cerca_data(t_carpeta *car, t_data data);
int insereix_nova_data(t_carpeta *car, t_data data);
int insereix_nova_tasca(t_data *data, t_tasca tas);
t_tasca * cerca_tasca(t_data *data, char titol[MAX_C]);
int elimina_tasca(t_data *data, char titol[MAX_C]);
int neteja_dates_buides(t_carpeta *car);

#endif /* CARPETA_H */
