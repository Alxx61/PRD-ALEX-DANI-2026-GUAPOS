/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef ORGANITZADOR_H
#define ORGANITZADOR_H

#include "carpeta.h"

#define MAX_CAR 5       /* Nombre màxim de carpetes */

typedef struct
{
    int ncarpetes;                  /* Nombre de carpetes creades        */
    t_carpeta carpetes[MAX_CAR];    /* Carpetes creades a l'organitzador */
}t_organitzador;

t_carpeta * cerca_carpeta(t_organitzador *org, char titol[MAX_C]);
int insereix_nova_carpeta(t_organitzador *org, t_carpeta car);
void mostra_carpetes(t_organitzador *org);
void mostra_contingut_carpeta(t_organitzador *org, char titol[MAX_C]);
void neteja_dates_buides_carpetes(t_organitzador *org);
int elimina_carpeta(t_organitzador *org, char titol[MAX_C]);

#endif /* ORGANITZADOR_H */

