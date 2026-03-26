/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(int argc, char** argv)
{
    
    printf("***********************************************\n");
    printf("*      ORGANITZADOR DE TASQUES PENDENTS       *\n");
    printf("*   Programacio i Estructures de Dades (PRD)  *\n");
    printf("*       ETSETB-GREELEC: Curs 2025/2026        *\n");
    printf("***********************************************\n\n");
    
    /* Completar codi de la funció main() */
    
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

