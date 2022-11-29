//Crie um programa usando vetores e alocação dinâmica que permita as seguintes operações:

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho;
    int i;
    int j;
    int n;
    int simetrica=1;
    float escalar;
    float **matriz1; 
    float **matriz2;
    float **matriz3;
    float **matriz4;
    
    //O usuário pode escolher o tamanho da matriz, invariavelmente quadrada.
    printf("Insira a quantidade de elementos da matriz 1:\n");
    scanf("%d", &tamanho);

    matriz1 = (float **) malloc(tamanho * sizeof(float *));
    matriz2 = (float **) malloc(tamanho * sizeof(float *));
    matriz3 = (float **) malloc(tamanho * sizeof(float *));
    matriz4 = (float **) malloc(tamanho * sizeof(float *));

    for (i= 0; i < tamanho; i++){
        matriz1[i] = (float *) malloc(tamanho * sizeof(float *));
    }
    for (i= 0; i < tamanho; i++){
        matriz2[i] = (float *) malloc(tamanho * sizeof(float *));
    }
    for (i= 0; i < tamanho; i++){
        matriz3[i] = (float *) malloc(tamanho * sizeof(float *));
    }
    for (i= 0; i < tamanho; i++){
        matriz4[i] = (float *) malloc(tamanho * sizeof(float *));
    }

    printf("Insira os elementos da matriz 1:\n");

    for (i = 0; i < tamanho; i++){
                for (j=0; j < tamanho; j++) {
                    printf("matriz1[%d][%d] = ",i,j);
                    scanf("%f", &matriz1 [i][j]);
                }
    }

    for (i = 0; i < tamanho; i++) {
        printf("\n\n\n");
        for (j=0; j < tamanho; j++) {
            printf("%0.2f\t", matriz1[i][j]);
        }
        printf("\n");
    }
    //Realiza a multiplicação da matriz por um número escalar
    printf("Insira o escalar para multiplicar a matriz: \n");
    scanf("%f", &escalar);

    for (i = 0; i < tamanho; i++){
                for (j=0; j < tamanho; j++) {
                    matriz1[i][j] = matriz1[i][j] * escalar;
                }
    }
    
    printf("Matriz multiplicada pelo escalar: \n");

    for (i = 0; i < tamanho; i++) {
        printf("\n\n\n");
        for (j=0; j < tamanho; j++) {
            printf("%0.2f\t", matriz1[i][j]);
        }
        printf("\n");
    }
  
    // Calcula a matriz transposta
    for (i = 0; i < tamanho; i++){
                for (j=0; j < tamanho; j++) {
                    matriz2[j][i] = matriz1[i][j];
                }
    }
    
    printf("Matriz Transposta: \n");

    for (i = 0; i < tamanho; i++) {
        printf("\n\n\n");
        for (j=0; j < tamanho; j++) {
            printf("%0.2f\t", matriz2[i][j]);
        }
        printf("\n");
    }
  // Calcula a matriz Oposta
   for (i = 0; i < tamanho; i++){
                for (j=0; j < tamanho; j++) {
                    matriz3[i][j] = -matriz1[i][j];
                    //Não deixa o 0 ser negativo
                    if (matriz3[i][j] == -0.00) {
                      matriz3[i][j] = 0;}
                }
    }
    
    printf("Matriz Oposta: \n");

    for (i = 0; i < tamanho; i++) {
        printf("\n\n\n");
        for (j=0; j < tamanho; j++) {
            printf("%0.2f\t", matriz3[i][j]);
        }
        printf("\n");
    }
       
    // Realiza a multiplicação entre duas matrizes
    for (i = 0; i < tamanho; i++){
                for (j=0; j < tamanho; j++) {
                    matriz4[i][j] = matriz1[i][j] * matriz2[i][j];
                }
    }
    
    printf("Matriz resultante da multiplicação entre matriz1 e matriz 2: \n");

    for (i = 0; i < tamanho; i++) {
        printf("\n\n\n");
        for (j=0; j < tamanho; j++) {
            printf("%0.2f\t", matriz4[i][j]);
        }
        printf("\n");
    }         
//Verifica Simetria
    for(i = 1; i <= n; i++)
    {
          for(j = 1; j <= n; j++)
          {
                if(matriz3[i][j] != matriz2[i][j])
                {
                      simetrica = 0;          
                }
          }
    }
    if(simetrica == 0)
    {
                 printf("\nA matriz fornecida não é antisimetrica.\n\n");
    }
    else
    {
        printf("\nA matriz fornecida é antisimetrica.\n\n");
    }
    system("pause");
}