#include "tasca.h"
#include <stdio.h>
#include <stdint.h>


void tests_tasca1(){
    t_comentari comentari;
    comentari = llegeix_nou_comentari();
    
    mostra_comentari(comentari);
    
    t_tasca tasca;
    tasca = llegeix_nova_tasca();
    
    mostra_tasca(tasca);
}

void tests_tasca2(){

    t_tasca tasca;
    t_comentari comentari;
    int i, el = 0, estat = 0;
    tasca = llegeix_nova_tasca();
    
    for (i = 0; i < 3; i++){
        comentari = llegeix_nou_comentari();
        insereix_comentari(&tasca, comentari);
    }
    
    printf("\nQuin comentari vols eliminar (1,2 o 3): ");
    scanf("%d", &el);
    
    estat = elimina_comentari(&tasca, el);
    
    if (estat == 0){
        printf("\nComentari eliminat satisfactoriament");
    }else if (estat == -1){
        printf("\nEl comentari no s'ha pogut eliminar");
    }
    
    mostra_tasca(tasca);
}

