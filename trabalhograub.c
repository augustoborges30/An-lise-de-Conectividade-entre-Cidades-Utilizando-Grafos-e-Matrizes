#include <stdio.h>

//matriz 4x4

int main(){
    int cidade;
    int entrada = 0;
    int saida = 0;

    int matriz [4][4] = {{1, 1, 1, 0},
                         {0, 1, 1, 0},
                         {1, 0, 1, 1},
                         {0, 0, 1, 1}};

    printf("Qual cidade? ");
    scanf("%d", &cidade);

    //questao A

    for(int i = 0; i < 4; i++) {
        if(matriz[cidade-1][i] == 1){
            saida++;
        }
    }

    for(int i = 0; i < 4; i++) {
        if(matriz[i][cidade-1] == 1){
            entrada++;
        }
    }

    printf("Entradas: %d, Saídas: %d", entrada,saida);


    //questao B

    int maiorEntrada = 0;
    int maiorCidade;

    for( int j = 0; j < 4; j++){
        int entradas = 0;
        for(int i = 0; i < 4; i++) {
            if(matriz[j][i] == 1){
                entradas++;
            }
        }

        for(int i = 0; i < 4; i++) {
            if(matriz[i][j] == 1){
                entradas++;
            }
        }    
        if(entradas > maiorEntrada){
            maiorEntrada = entradas;
            maiorCidade = j+1;
        }
    }           

    printf("A cidade com mais entradas é a cidade %d, com %d entradas", maiorCidade, maiorEntrada-1);


    //questao C (rever a lógica)

    int diferenca = 0;
    int cidadeC;

    printf("Qual cidade? ");
    scanf("%d", &cidadeC);   

    for(int i = 0; i < 4; i++){
        if(matriz[cidadeC-1][i] == matriz[i][cidadeC-1]){

        }else{
            diferenca++;
        }
    }

    if(diferenca == 0){
        printf("As entradas e saídas são de mão dupla.");
    }else{
        printf("As entradas e saídas NÃO são de mão dupla.");
    }
    

    //questao D

    int cidade 

    printf("Qual cidade? \n");   
    scanf("%d", &cidade);

    printf("As cidades que possuem saídas diretas para a cidade %d são: ", cidade);

    for(int i = 0; i < 4; i++){
        if(matriz[i][cidade-1] == 1){
            printf("%d ", i+1);
        }
    }

    //questao E

    // i. Cidades sem saída
    printf("As cidade que não possuem saídas diretas para nenhuma outra cidade são:\n");

    for(int i = 0; i < 4; i++){
        int temSaida = 0;
        for(int j = 0; j < 4; j++){
            if(matriz[i][j] == 1){
                temSaida = 1;
                break;
            }
        }
        if(!temSaida){
            printf("%d ", i+1);
        }
    }

    //questao F



    //questao G
    
    int cidadeG1;
    printf("Qual cidade que quer partir? ");
    scanf("%d", &cidadeG1);   

    int cidadeG2;
    printf("Qual cidade que quer chegar? ");
    scanf("%d", &cidadeG2);   

    if(matriz[cidadeG1-1][cidadeG2-1] == 1){
        printf("É possível ir da cidade %d para a cidade %d pelas rotas existentes", cidadeG1, cidadeG2);
    }else{
        printf("Se fudeu");
    } 



    //Atividade H
    
    return 0; 
}