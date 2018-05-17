#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "menu.h"

int main() {
  Lista* l;

  int opcao, desejaVoltar;
  char dolar[2];
  char nome[101];
  char telefone[15];
  char endereco[101];
  int cep;
  char caracter[2];
  char cepString[20];
  char dataNascimento[15];
  char* variavel[1001];
  l = inicializa();
  int i = 1;

  FILE *contatos;
  contatos = fopen ("contatos.txt","a+r");
  if (contatos == NULL) {
    printf ("Houve um erro ao abrir o arquivo.\n");
    return 1;
  }
  printf ("Arquivo Agenda criado com sucesso.\n");

  while(fgets(nome, sizeof(nome), contatos)!=NULL){
    variavel[i] = strdup(nome);
    i++;
  }
  i--;
  // printf("%d\n",i);
  // printf("(%d)\n", i/6);

  for(int j = 1; j <= i; j+=6){
    // printf("%s", variavel[j]);
    l = insere(l, variavel[j], variavel[j+1], variavel[j+2], variavel[j+3], variavel[j+4]);
    listaOrdenada(l);
  }

  paginaInicial();

  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  while(opcao != 0){
    switch (opcao) {
      case 1:
        //Cadastrando contato
        system("clear");
        printf("Nome: ");
        getchar();
        fgets(nome, 101, stdin);
        printf("Telefone: ");

        fgets(telefone, 15, stdin);
        printf("Endereço: ");

        fgets(endereco, 101, stdin);
        printf("CEP: ");
        fgets(cepString, 20, stdin);

        printf("Data de Nascimento: ");
        fgets(dataNascimento, 15, stdin);

        l = insere(l, nome, telefone, endereco, cepString, dataNascimento);
        listaOrdenada(l);
        printf("\n");
        break;

      case 2:
        system("clear");
        printf("Qual o nome do contato que deseja excluir: ");
        getchar();
        fgets(nome, 101, stdin);
        l = retira(l, nome);

        break;

      case 3:
        system("clear");
        printf("Qual o nome que deseja procurar: ");
        getchar();
        fgets(nome, 101, stdin);
        busca(l, nome);
        break;

      case 4:
        system("clear");
        imprime(l);
        break;

    }

    for (int i=0; i<80; i++){
        printf("*");
    }
    printf("\nDeseja voltar para o menu? 1(Sim), 2(Não): ");
    scanf("%d", &desejaVoltar);
    while (desejaVoltar != 1 && desejaVoltar !=2) {
      printf("ATENÇÃO* Opção invalida");
      printf("\nDeseja voltar para o menu? 1(Sim), 2(Não): ");
      scanf("%d", &desejaVoltar);
     }

     if(desejaVoltar == 1){
         paginaInicial();
         printf("Escolha uma opcao: ");
         scanf("%d", &opcao);
         // system("clear");
     }
     else if(desejaVoltar == 2){
       //deixar criar mais
     }

  }

  contatos = fopen("contatos.txt", "w");
  insereArquivo(l, contatos);
  fclose(contatos);
  libera(l);

  return 0;
}
