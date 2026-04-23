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
    t_organitzador org;
    processa_opcio_nova_carpeta(&org);
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
    
    if (!cerca_carpeta(org, titol)){
        printf("Carpeta no trobada.");
    }else{
        carpeta = cerca_carpeta(org, titol);
        
        data = llegeix_nova_data();
        
        if (insereix_nova_data(carpeta, data) == 0){
            printf("Data inserida correctament.");
        }else{
            printf("La carpeta esta plena.");
        }
    }
    
}

void processa_opcio_nova_tasca(t_organitzador *org){
    
    t_data data;
    t_tasca tasca;
    t_carpeta *carpeta;
    char titol[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol);
    
    if (!cerca_carpeta(org, titol)){
        printf("Carpeta no trobada.");
    }else{
        printf("Data (format: dd/mm/aaaa): ");
        data = llegeix_nova_data();
    
        if (!cerca_data(carpeta, data)){
            printf("Data no trobada.");
        }else{
            tasca = llegeix_nova_tasca();
            if (insereix_nova_tasca(data, tasca) == 0){
                printf("Tasca inserida correctament.");
            }else{
                printf("La data esta plena.");
            }
        }
    }

    
    
}

void processa_opcio_insereix_comentari(t_organitzador *org){

    t_data data;
    t_comentari comentari;
    t_tasca *tasca;
    t_carpeta *carpeta;
    char titol[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol);
    
    if (!cerca_carpeta(org, titol)){
        printf("Carpeta no trobada.");
    }else{
        carpeta = cerca_carpeta(org, titol);
        printf("Data (format: dd/mm/aaaa): ");
        data = llegeix_nova_data();
    
        if (!cerca_data(carpeta, data)){
            printf("Data no trobada.");
        }else{
            printf("Titol de la tasca: ");
            llegeix_text(titol);
            
            
            if (!cerca_tasca(*data, titol)){
                printf("Tasca no trobada.");
            }else{
                tasca = cerca_tasca(*data, titol);
                comentari = llegeix_nou_comentari();
                if (insereix_comentari(tasca, comentari) == 0){
                    printf("Comentari inserit correctament.");
                }else{
                    printf("La tasca esta plena.");
                }
            }
        }
    }

    
    
}



void processa_opcio_mostra_carpetes(t_organitzador *org){
    int i=0;    
    if (org->ncarpetes>0){
        for (i=0;i<org->ncarpetes;i++)
            printf("%s",org->carpetes[i].titol);
        
    }    
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

