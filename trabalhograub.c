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

    int cidade;

    printf("Qual cidade? \n");   
    scanf("%d", &cidade);

    printf("As cidades que possuem saídas diretas para a cidade %d são: ", cidade);

    for(int i = 0; i < 4; i++){
        if(matriz[i][cidade-1] == 1){
            printf("%d ", i+1);
        }
    }

    //questao E

    // i. Cidades isoladas
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

    // ii. Cidades sem saída (mas com entrada)

    printf("As cidades que possuem entradas, mas não possuem saídas são: \n");

    int temSemSaida = 0; // Variável para verificar se encontrou pelo menos uma cidade sem saída
    for(int i = 0; i < 4; i++){
        int temEntrada = 0; 
        int temSaida = 0;  // Variável para verificar se tem saída e entrada

        for(int j = 0; j < 4; j++){ 
            if(matriz[i][j] == 1){ 
                temSaida = 1; // Se encontrar uma saída, marca que tem saída
            }
            if(matriz[j][i] == 1){
                temEntrada = 1; // Se encontrar uma entrada, marca que tem entrada
            }
        }

        if(temEntrada && !temSaida){ 
            printf("%d ", i+1); 
            temSemSaida = 1; // Marca que encontrou pelo menos uma cidade sem saída
        }
    }

    if(!temSemSaida){
        printf("Nenhuma"); // Se não encontrou nenhuma cidade sem saída, imprime "Nenhuma"  
    }

    // iii. Cidades com saída mas sem entrada

    printf("As cidades que possuem saídas, mas não possuem entradas são: \n");

    int TemsaidaSemEntrada = 0; 

    for(int i = 0; i < 4; i++) {
            int tem_saida = 0;
            int sem_entrada = 0;
 
            for(int j = 0; j < 4; j++) {
                if(i != j && matriz[i][j] == 1) {
                    tem_saida = 1;  // Tem saída
                }
                if(matriz[j][i] == 1) {
                    sem_entrada = 1;  // Tem entrada
                }
            }

            if(tem_saida && !sem_entrada) {
                printf("%d ", i+1); 
                TemsaidaSemEntrada = 1; //tem saida, mas não tem entrada 
            }
        }   

         if(!TemsaidaSemEntrada){
             printf("Nenhuma");  
         }


    //questao F



    //questao G
    
     int cidadeG1;
    printf("Qual cidade que quer partir? ");
    scanf("%d", &cidadeG1);   

    int caminho = 0;

    int cidadeG2;
    printf("Qual cidade que quer chegar? ");
    scanf("%d", &cidadeG2);   

    if(matriz[cidadeG1-1][cidadeG2-1] == 1){
        caminho++;
    }

    for(int i = 0; i < 4; i++){
        if(matriz[cidadeG1 - 1][i] == 1){
            if(matriz[i][cidadeG2 - 1] == 1){
                caminho++;
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j){
                if(matriz[cidadeG1 - 1][i] == 1){
                    if(matriz[i][j] == 1){
                        if(matriz[j][cidadeG2 - 1] == 1){
                            caminho++;
                        }
                    }
                }
            }
            
        }
    }
    

    if(caminho >= 1){
        printf("É possível ir da cidade %d para a cidade %d pelas rotas existentes", cidadeG1, cidadeG2);
    }else{
        printf("Não tem como, procura no waze. \n");
    }
    
    //Atividade H

    int cidadeH;
    printf("Qual cidade que quer partir? ");
    scanf("%d", &cidadeH);   

    int caminho = 0;

    int inicio = -1;
    int parada1 = -1;
    int parada2 = -1;
    int destino = -1;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(cidadeH - 1 != i){
                    if(matriz[cidadeH - 1][i] == 1){
                        inicio = cidadeH - 1;
                        if(i != j && i != cidadeH -1){
                            if(matriz[i][j] == 1){
                                parada1 = i;
                                if(j != k && j != i && j != cidadeH - 1){
                                    if(matriz[j][k] == 1){
                                        parada2 = j;
                                        if(k != cidadeH - 1 && k != i && k != j){
                                            if(matriz[k][cidadeH - 1] == 1){
                                                //printf("%d, %d, %d\n", i, j, k);
                                                
                                                destino = k;
                                                caminho++;
                                                //break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    //printf("\n%d\n", caminho);
    //printf("rota: %d,%d,%d,%d\n", inicio, parada1, parada2, destino);
    if(caminho >= 1){
        printf("é possível, partindo da cidade %d, passar por todas as outras cidades apenas uma vez e retornar a cidade %d", cidadeH, cidadeH);
    }else{
        printf("Se fudeu");
    }
    
    return 0;
}
    