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
    char op='\0';
    
    printf("***********************************************\n");
    printf("*      ORGANITZADOR DE TASQUES PENDENTS       *\n");
    printf("*   Programacio i Estructures de Dades (PRD)  *\n");
    printf("*       ETSETB-GREELEC: Curs 2025/2026        *\n");
    printf("***********************************************\n\n");
    
    /* Completar codi de la funció main() */
    t_organitzador org = {0};
    mostrar_ajuda();


    while ((op != 'F') && (op != 'f')){
        printf("Introdueix una nova opcio: ");
        scanf("%c%*c",&op);
        if ((op=='N')||(op=='n'))
            processa_opcio_nova_carpeta(&org);
        else if ((op=='d')||(op=='D'))
            processa_opcio_nova_data(&org);
        else if ((op=='t')||(op=='T'))
            processa_opcio_nova_tasca(&org);
        else if ((op=='i')||(op=='I'))
            processa_opcio_insereix_comentari(&org);
        else if ((op=='s')||(op=='S'))
            processa_opcio_mostra_carpetes(&org);
        else if ((op=='m')||(op=='M'))
            processa_opcio_mostra_carpeta(&org);
        else if ((op=='e')||(op=='E'))
            processa_opcio_elimina_tasca(&org);
        
        else if ((op=='b')||(op=='B'))
            processa_opcio_neteja_dates_buides(&org);
        
        else if ((op=='c')||(op=='C'))
            processa_opcio_elimina_carpeta(&org);
        
        else if ((op=='a')||(op=='A'))
            mostrar_ajuda();
                
    }
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

void processa_opcio_nova_carpeta(t_organitzador *org){  /*FUNCIONA*/
    
    t_carpeta carpeta;
    carpeta = llegeix_nova_carpeta();
    
    if (!cerca_carpeta(org, carpeta.titol)){
        if (insereix_nova_carpeta(org, carpeta) == 0){
            printf("Carpeta inserida correctament.\n");
        }else{
            printf("L'organitzador està ple.\n");
        }
    }else{
        printf("Ja existeix la carpeta amb aquest titol.");
    }  
}

void processa_opcio_nova_data (t_organitzador *org){    /*FUNCIONA*/

    t_data data;
    t_carpeta *carpeta;
    char titol[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol);
    carpeta = cerca_carpeta(org, titol);
    
    if (carpeta == NULL){
        printf("Carpeta no trobada.\n");
    }else{
        data = llegeix_nova_data();
        
        if (insereix_nova_data(carpeta, data) == 0){
            printf("Data inserida correctament.\n");
        }else{
            printf("La carpeta esta plena.\n");
        }
    }
    
}

void processa_opcio_nova_tasca(t_organitzador *org){    /*FUNCIONA*/
    
    t_data data;
    t_data *p_data = NULL;
    t_tasca tasca;
    t_carpeta *carpeta;
    char titol[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol);
    
    carpeta = cerca_carpeta(org, titol);
    
    if (carpeta == NULL){
        printf("Carpeta no trobada.\n");
    }else{
        
        while (p_data == NULL){
            data = llegeix_nova_data();

            p_data = cerca_data(carpeta, data);


            if (p_data == NULL){
                printf("Data no trobada.\n");

            }else{
                tasca = llegeix_nova_tasca();
                if (insereix_nova_tasca(p_data, tasca) == 0){
                    printf("Tasca inserida correctament.\n");
                }else{
                    printf("La data esta plena.\n");
                }
            }
        }
    }

    
    
}

void processa_opcio_insereix_comentari(t_organitzador *org){    /*FUNCIONA*/

    t_data data;
    t_data *p_data = NULL;
    t_comentari comentari;
    t_tasca *tasca = NULL;
    t_carpeta *carpeta;
    char titol_t[MAX_C];
    char titol_c[MAX_C];
    
    printf("Titol de la carpeta: ");
    llegeix_text(titol_c);
    carpeta = cerca_carpeta(org, titol_c);
    
    if (carpeta == NULL){
        printf("Carpeta no trobada.\n");
    }else{
        
        while (p_data == NULL){
            data = llegeix_nova_data();
            p_data = cerca_data(carpeta, data);

            if (p_data == NULL){
                printf("Data no trobada.\n");
            }else{
                while (tasca == NULL){
                    printf("Titol de la tasca: ");
                    llegeix_text(titol_t);

                    tasca = cerca_tasca(p_data, titol_t);

                    if (tasca == NULL){
                        printf("Tasca no trobada.\n");
                    }else{
                        comentari = llegeix_nou_comentari();
                        if (insereix_comentari(tasca, comentari) == 0){
                            printf("Comentari inserit correctament.\n");
                        }else{
                            printf("La tasca esta plena.\n");
                        }
                    }
                }
            }
        }
    }

    
    
}



void processa_opcio_mostra_carpetes(t_organitzador *org){   /*FUNCIONA*/
    int i=0;    
    if (org->ncarpetes>0){
        for (i=0;i<org->ncarpetes;i++)
            printf("%s\n",org->carpetes[i].titol);
        
    }    
}

void processa_opcio_mostra_carpeta(t_organitzador *org) { /*PER PROVAR*/
    char nom[MAX_C];
    t_carpeta *car = NULL;
    printf("Titol de la carpeta: ");
    llegeix_text(nom);
    car = cerca_carpeta(org, nom);
    if (car == NULL)
        printf("Carpeta no trobada.\n");
    else
        mostra_carpeta(*car);



}



void processa_opcio_elimina_tasca(t_organitzador *org){ /*PER PROVAR*/
    t_data data;
    t_data *p_data;
    t_tasca *tasca;
    t_carpeta *carpeta;
    char titolc[MAX_C],titolt[MAX_C];
    printf("Titol de la carpeta: ");
    llegeix_text(titolc);
    carpeta = cerca_carpeta(org,titolc);
    if (carpeta == NULL){
        printf("\nCarpeta no trobada\n");
    }
    else{
        data = llegeix_nova_data();
        p_data = cerca_data(carpeta,data);
        if (p_data == NULL)
            printf("Data no trobada\n");
        else{
            printf("Nom de la tasca: ");
            llegeix_text(titolt);
            tasca = cerca_tasca(p_data,titolt);
            if (tasca == NULL)
                printf("Tasca no trobada\n");
            else{
                if (elimina_tasca(p_data,titolt) == 0)
                    printf("Tasca eliminada correctament\n");
                
            }
        } 
        
    }
}
void processa_opcio_neteja_dates_buides(t_organitzador *org){

    neteja_dates_buides_carpetes(org);
    
    
}
void processa_opcio_elimina_carpeta(t_organitzador *org) {/*PER PROBAR*/
    t_carpeta *carpeta;
    char titolc[MAX_C];
    printf("Titol de la carpeta: ");
    llegeix_text(titolc);
    carpeta = cerca_carpeta(org, titolc);
    if (carpeta == NULL) {
        printf("\nCarpeta no trobada\n");
    } else {
        if (elimina_carpeta(org, titolc) == 0)
            printf("Carpeta eliminada correctament.");

    }
}


