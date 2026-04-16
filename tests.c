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



void tests_carpeta1(){
    t_carpeta carpeta;
    t_data data1, data2, data3;
    carpeta = llegeix_nova_carpeta();
    data1 = llegeix_nova_data();
    data2 = llegeix_nova_data();
    data3 = llegeix_nova_data();
    
    insereix_nova_data(&carpeta,data1);
    insereix_nova_data(&carpeta,data2);
    insereix_nova_data(&carpeta,data3);
    
    mostra_carpeta(carpeta);
}

void tests_carpeta2() {
    t_carpeta carpeta;
    t_data data1;
    t_tasca tasca1,tasca2,tasca3;
    carpeta = llegeix_nova_carpeta();
    data1 = llegeix_nova_data();
    insereix_nova_data(&carpeta, data1);
    tasca1 = llegeix_nova_tasca();
    tasca2 = llegeix_nova_tasca();
    tasca3 = llegeix_nova_tasca();
    insereix_nova_tasca(&data1,tasca1);
    insereix_nova_tasca(&data1,tasca2);
    insereix_nova_tasca(&data1,tasca3);
    mostra_carpeta(carpeta);
  
}

void tests_carpeta2_1() {
    char titol[MAX_C];
    int estat;
    t_carpeta carpeta;
    t_data data1;
    t_tasca tasca1,tasca2,tasca3;
    carpeta = llegeix_nova_carpeta();
    data1 = llegeix_nova_data();
    insereix_nova_data(&carpeta, data1);
    tasca1 = llegeix_nova_tasca();
    tasca2 = llegeix_nova_tasca();
    tasca3 = llegeix_nova_tasca();
    insereix_nova_tasca(&data1,tasca1);
    insereix_nova_tasca(&data1,tasca2);
    insereix_nova_tasca(&data1,tasca3);
    
    fgets(titol, MAX_C ,stdin);
    estat = elimina_tasca(&data1,titol); //recordar, que el fgets manté el \n al final, llavors si no compara bé pot ser perque el titol de la tasca no té el \n llavors no són iguals els strings
    
    if (estat == 0)
        printf("Eliminat amb éxit\n");
    else
        printf("Error al eliminar\n")  
    mostra_carpeta(carpeta);

}

void tests_carpeta3(){
    
    t_carpeta carpeta;
    t_data data1, data2, data3;
    carpeta = llegeix_nova_carpeta();
    data1 = llegeix_nova_data();
    data2 = llegeix_nova_data();
    data3 = llegeix_nova_data();
    
    insereix_nova_data(&carpeta,data1);
    insereix_nova_data(&carpeta,data2);
    insereix_nova_data(&carpeta,data3);
    
    mostra_carpeta(carpeta);    
    
    neteja_dates_buides(&carpeta);
    mostra_carpeta(carpeta);    

    
    
    
    
}