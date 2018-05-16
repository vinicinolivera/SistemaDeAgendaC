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
  char cepString[10];
  char dataNascimento[15];
  l = inicializa();

  FILE *contatos;
  contatos = fopen ("contatos.txt","a+");
  if (contatos == NULL) {
    printf ("Houve um erro ao abrir o arquivo.\n");
    return 1;
  }
  printf ("Arquivo Agenda criado com sucesso.\n");

  setbuf(stdin, NULL);
  while((fscanf(contatos,"%s\n%s\n%s\n%d\n%s\n%s", nome, telefone, endereco, &cep, dataNascimento, dolar))!=EOF){
    setbuf(stdin, NULL);
    l = insere(l, nome, telefone, endereco, cep, dataNascimento);
  }
  // insereDoArquivo(l, contatos);

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
        getchar();
        fgets(telefone, 15, stdin);
        printf("Endereço: ");
        getchar();
        fgets(endereco, 101, stdin);
        printf("CEP: ");
        scanf("%d", &cep);
        printf("Data de Nascimento: ");
        getchar();
        fgets(dataNascimento, 15, stdin);

        l = insere(l, nome, telefone, endereco, cep, dataNascimento);
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
      case 9:
        system("clear");
        insereArquivo(l, contatos);
        fclose(contatos);
        libera(l);
        printf("Dados salvos com sucesso!");
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

  //contatos = fopen("contatos.txt", "a+");
  //insereArquivo(l, contatos);
  //fclose(contatos);

  return 0;
}
