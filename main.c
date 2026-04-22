/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "carpeta.h"
#include "organitzador.h"
#include "tasca.h"
#include "tests.h"

int main(int argc, char** argv)
{
    
    printf("***********************************************\n");
    printf("*      ORGANITZADOR DE TASQUES PENDENTS       *\n");
    printf("*   Programacio i Estructures de Dades (PRD)  *\n");
    printf("*       ETSETB-GREELEC: Curs 2025/2026        *\n");
    printf("***********************************************\n\n");
    
    /* Completar codi de la funció main() */
    t_organitzador *org;
    processa_opcio_nova_data(&org);
    
    printf("Finalitzant l'aplicacio... Adeu!\n");
    return (EXIT_SUCCESS); 
}

void mostrar_ajuda()
{
    printf("Opcions disponibles:\n");
    printf("\t[N]ova carpeta\n");
    printf("\tNova [D]ata\n");
    printf("\tNova [T]asca\n");
    printf("\t[I]nsereix comentari\n");
    printf("\tMostra carpete[S]\n");
    printf("\t[M]ostra carpeta\n");
    printf("\t[E]limina tasca\n");
    printf("\tNeteja dates [B]uides\n");
    printf("\tElimina [C]arpeta\n");
    printf("\t[A]juda\n");
    printf("\t[F]inalitza\n");
}

void llegeix_text(char text[MAX_C])
{
    fgets(text, MAX_C, stdin);
    if (strlen(text) > 0)
        text[strlen(text)-1] = '\0';
}

void processa_opcio_nova_carpeta(t_organitzador *org){
    
    t_carpeta carpeta;
    carpeta = llegeix_nova_carpeta();
    
    if (!cerca_carpeta(org, carpeta.titol)){
        if (insereix_nova_carpeta(org, carpeta) == 0){
            printf("Carpeta inserida correctament.");
        }else{
            printf("L'organitzador està ple.");
        }
    }else{
        printf("Ja existeix la carpeta amb aquest titol.");
    }  
}

void processa_opcio_nova_data (t_organitzador *org){

    t_data data;
    t_carpeta *carpeta;
    char titol[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol);
    
    if(!cerca_carpeta(org, titol))
    carpeta = cerca_carpeta(org, titol);
    
}



void processa_opcio_mostra_carpetes(t_organitzador *org){
    int i=0;    
    if (org->ncarpetes>0){
        for (i=0;i<org->ncarpetes;i++)
            printf("%s",org->carpetes[i].titol);
        
    }    
}
void processa_opcio_nova_tasca(t_organitzador *org){
    
    

    
    
}
void processa_opcio_insereix_comentari(t_organitzador *org){

    
    
}
void processa_opcio_mostra_carpeta(t_organitzador *org){
    char nom[MAX_C];
    llegeix_text(nom);
    mostra_carpeta(*cerca_carpeta(org, nom));

        
    
}
void processa_opcio_elimina_tasca(t_organitzador *org){



}
void processa_opcio_neteja_dates_buides(t_organitzador *org){

    
    
    
}
void processa_opcio_elimina_carpeta(t_organitzador *org){

    
    
    
}

