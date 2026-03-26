/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef MAIN_H
#define MAIN_H

#include "organitzador.h"

void mostrar_ajuda();
void llegeix_text(char text[MAX_C]);
void processa_opcio_nova_carpeta(t_organitzador *org);
void processa_opcio_nova_data(t_organitzador *org);
void processa_opcio_mostra_carpetes(t_organitzador *org);
void processa_opcio_nova_tasca(t_organitzador *org);
void processa_opcio_insereix_comentari(t_organitzador *org);
void processa_opcio_mostra_carpeta(t_organitzador *org);
void processa_opcio_elimina_tasca(t_organitzador *org);
void processa_opcio_neteja_dates_buides(t_organitzador *org);
void processa_opcio_elimina_carpeta(t_organitzador *org);

#endif /* MAIN_H */

