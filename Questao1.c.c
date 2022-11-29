//Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.

#include<stdio.h>
#include<stdlib.h>

struct alunos {
 char matricula[10];
 char nome[50];
 float nota[3];
};


int main(){

 struct alunos a[5];
 int i,  maiornota1_indice, maiormedia_indice, menormedia_indice;
 float maiornota1=0, media[5], maiormedia=0, menormedia;

 printf("\n------Cadastro de alunos do IESB-----\n\n");
 //Permite ao usuário entrar com os dados de 5 alunos
 for(i=0; i<5; i++){

    //Entrada de dados
    printf("\nDigite a matricula do Aluno:\n");
    scanf("%s",&a[i].matricula);
    printf("Nome do %d Aluno: ",i+1);
    scanf("%s",&a[i].nome);
    printf("Nota 1: ");
    scanf("%f",&a[i].nota[0]);
    printf("Nota 2: ");
    scanf("%f",&a[i].nota[1]);
    printf("Nota 3: ");
    scanf("%f",&a[i].nota[2]);
    
    //media
    media[i] = a[i].nota[0]+a[i].nota[1]+a[i].nota[2];

    //Encontra o aluno com maior nota da primeira prova
    if(maiornota1<a[i].nota[0]){

        maiornota1 = a[i].nota[0];

        maiornota1_indice = i;

    }
    // Encontra o aluno com maior média 
    if(media[i]>maiormedia){
        maiormedia = media[i];
        maiormedia_indice = i;

    }
    // Encontra o aluno com menor média
    if(media[i]<menormedia){
        menormedia = media[i];
        menormedia_indice = i;

    }

 };
    //Saida de dados
    printf("\nAluno com maior Nota 1: %s",a[maiornota1_indice].nome);
    printf("\nAluno com maior média: %s",a[maiormedia_indice].nome);
    printf("\nAluno com menor média: %s",a[menormedia_indice].nome);

    // Para cada aluno diz se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação
    int j=0;
    for(j=0; j<5; j++){
        //Caso a media do aluno seja menor que 6, ele está reprovado
        if(media[j]<=6){

            printf("\nAluno %s foi reprovado\n",a[j].nome);
        }else {
            printf("Aluno %s foi aprovado\n",a[j].nome);
        }

    }

system("pause");
return 0;
}