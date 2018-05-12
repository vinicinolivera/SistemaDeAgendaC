#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "menu.h"

int main() {
  Lista* l;
  l = inicializa();

  paginaInicial();

  int opcao, desejaVoltar;
  char nome[101];
  char telefone[15];
  char endereco[101];
  int cep;
  char dataNascimento[15];

  FILE *contatos;
  contatos = fopen ("contatos.txt","a+b");
  if (contatos == NULL) {
     printf ("Houve um erro ao abrir o arquivo.\n");
     return 1;
  }
  printf ("Arquivo INFORMACOESRU criado com sucesso.\n");

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
        fprintf(contatos, "%s", nome);
        printf("Telefone: ");
        getchar();
        fgets(telefone, 15, stdin);
        fprintf(contatos, "%s", telefone);
        printf("Endereço: ");
        getchar();
        fgets(endereco, 101, stdin);
        fprintf(contatos, "%s", endereco);
        printf("CEP: ");
        scanf("%d", &cep);
        fprintf(contatos, "%d\n", cep);
        printf("Data de Nascimento: ");
        getchar();
        fgets(dataNascimento, 15, stdin);
        fprintf(contatos, "%s", dataNascimento);
        fprintf(contatos, "$\n");

        l = insere(contatos, l, nome, telefone, endereco, cep, dataNascimento);
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

      case 0:

        break;
    }

    for (int i=0; i<80; i++){
        printf("*");
    }
    printf("\nDeseja voltar para o menu? 1(Sim), 2(Não): ");
    scanf("%d", &desejaVoltar);
    if(desejaVoltar == 1){
        paginaInicial();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    }

    else{
    }
  }
  return 0;
}
