#include <stdint.h>
#include <stdio.h>
#include "tasca.h"
#include <string.h>

t_comentari llegeix_nou_comentari(){

    t_comentari comentari;
    printf("\nText del nou comentari: ");
    
    fgets(comentari.text, MAX_C, stdin);
    
    while (strlen(comentari.text) > MAX_C){
        printf("Masses caracters (Màxim 100)\n");
        fgets(comentari.text, MAX_C, stdin);
    }
    
    comentari.text[strlen(comentari.text)-1] = '\0';
    
    return comentari;
    
}


void mostra_comentari(t_comentari com){
    printf("Comentaris: ");
    printf("%s\n",com.text); 
}

t_tasca llegeix_nova_tasca(){
    t_tasca tasca;
    printf("\nTitol de la nova tasca: ");
    fgets(tasca.titol,MAX_C,stdin); 
    tasca.titol[strlen(tasca.titol)-1] = '\0';
    printf("\nPrioritat de la nova tasca (entre [1,3]): ");
    scanf("%d%*c",&tasca.prioritat);
    while (tasca.prioritat < MIN_PRI || tasca.prioritat > MAX_PRI){
        printf("\nValor erroni, torna-hi: ");
        scanf("%d%*c",&tasca.prioritat);
        
    }
    tasca.ncomentaris = 0;  
    return(tasca);
}

void mostra_tasca(t_tasca tas){
    
    int i; 
    printf("Titol de la tasca: %s\n",tas.titol);
    printf("Prioritat de la tasca: %d\n",tas.prioritat);
    
    if (tas.ncomentaris > 0){
        printf("Comentaris: \n");
        for (i = 0; i < tas.ncomentaris; i++)
            printf("%d. %s\n",i+1,tas.comentaris[i].text);
        
        
    }

}

int insereix_comentari(t_tasca *tas, t_comentari com){
    
    int i;
    if (tas->ncomentaris < MAX_COM) {
        for (i = tas->ncomentaris - 1; i >= 0; i--)
            tas->comentaris[i+1] = tas->comentaris[i];
        tas->comentaris[0] = com;
        tas->ncomentaris++;
        return (0);
    }
    else{
        return(-1); 
    }
}

int elimina_comentari(t_tasca *tas, int num){ //tasca.comentaris --> array de comentaris 

    
    int i = 0;
    if (num <= 0 || num > tas->ncomentaris) {
        return(-1);
    }

    for (i = num; i < tas->ncomentaris; i++)
        tas->comentaris[i - 1] = tas->comentaris[i];

    tas->ncomentaris--;
    return (0);



}
