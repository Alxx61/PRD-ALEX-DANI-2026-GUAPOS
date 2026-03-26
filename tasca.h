/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef TASCA_H
#define TASCA_H

#define MAX_C   100     /* Nombre màxim de caràcters  */
#define MIN_PRI 1       /* Valor mínim de prioritat   */
#define MAX_PRI 3       /* Valor màxim de prioritat   */
#define MAX_COM 5       /* Nombre màxim de comentaris */

typedef struct
{
    char text[MAX_C];       /* Text del comentari */
}t_comentari;

typedef struct
{
    char titol[MAX_C];                  /* Títol de la tasca             */
    int prioritat;                      /* Prioritat de la tasca         */
    int ncomentaris;                    /* Nombre de comentaris afegits  */
    t_comentari comentaris[MAX_COM];    /* Comentaris afegits a la tasca */
}t_tasca;

t_comentari llegeix_nou_comentari();
void mostra_comentari(t_comentari com);
t_tasca llegeix_nova_tasca();
void mostra_tasca(t_tasca tas);
int insereix_comentari(t_tasca *tas, t_comentari com);
int elimina_comentari(t_tasca *tas, int num);

#endif /* TASCA_H */

