#include <stdint.h>
#include <stdio.h>
#include "tasca.h"
#include <string.h>

t_comentari llegeix_nou_comentari(){

    t_comentari comentari;
    printf("\nText del nou comentari: ");
    
    fgets(comentari.text, MAX_C, stdin);
    
    if (strlen(comentari.text) > MAX_C){
        printf("Masses caracters (Màxim 100)\n");
    }else{
        return comentari;
    }
}


void mostra_comentari(t_comentari com){
    printf("Comentaris: ");
    printf("%s\n",com.text); 
}

t_tasca llegeix_nova_tasca(){
    t_tasca tasca;
    printf("\nTitol de la nova tasca: ");
    fgets(tasca.titol,MAX_C,stdin); // NEWLINE ES QUEDA AL FINAL DE EL STRING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    printf("\nPrioritat de la nova tasca (entre [1,3]): ");
    scanf("%d%*c",&tasca.prioritat);
    while (tasca.prioritat <= 0 || tasca.prioritat >= 4){
        printf("\nValor incorrecte\n");
        scanf("%d%*c",&tasca.prioritat);
        
    }
    tasca.ncomentaris = 0;
    printf("Tasca inserida correctament. \n");
    return(tasca);
}

void mostra_tasca(t_tasca tas){
    
    int i; 
    printf("Nom de la tasca: %s\n",tas.titol);
    printf("Prioritat de la tasca: %d\n",tas.prioritat);
    if (tas.ncomentaris > 0){
        for (i = 0; i < tas.ncomentaris; i++)
            printf("%d. %s\n",i+1,tas.comentaris[i].text);
        
        
    }

}

int insereix_comentari(t_tasca *tas, t_comentari com){
    if (tas->ncomentaris < MAX_COM) {
        tas->comentaris[tas->ncomentaris] = com;
        tas->ncomentaris++;
        printf("Comentari inserit correctament. \n");
        return (0);
    }
    else{
        printf("No s'ha pogut inserir el comentari");
        return(-1); 
    }
}

int elimina_comentari(t_tasca *tas, int num){ //tasca.comentaris --> array de comentaris 

    if (num >= 0 && num < MAX_COM) {
        
        int i=0;
        
        for (i = num; i < MAX_COM-1; i++)
            tas->comentaris[i-1] = tas->comentaris[i];        
        
        tas->ncomentaris--;
        printf("Comentari eliminat correctament. \n");
        return(0);
    }
    else{
        printf("No s'ha pogut inserir");
        return(-1);
 
    }

}
