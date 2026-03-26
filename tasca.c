#include <stdint.h>
#include <stdio.h>
#include "tasca.h"

t_comentari llegeix_nou_comentari(){

    t_comentari comentari;
    printf("Text del nou comentari: ");
    
    fgets(comentari.text, MAX_C, stdin);
    
    if (strlen(comentari.text) > MAX_C){
        printf("Masses caracters (Màxim 100)");
    }else{
        return comentari;
    }
}


void mostra_comentari(t_comentari com){
    printf("Comentaris: ");
    printf("%s\n",com.text); 
}

t_tasca llegeix_nova_tasca(){

}

void mostra_tasca(t_tasca tas){

}

int insereix_comentari(t_tasca *tas, t_comentari com){

}

int elimina_comentari(t_tasca *tas, int num){

}
