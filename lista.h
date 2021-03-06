#ifndef lista_h
#define lista_h


struct contato{
  char nome[101];
  char telefone[15];
  char endereco[101];
  char cepString[20];
  char dataNascimento[15];
};
typedef struct contato Contato;

struct lista{
  Contato *contato;
  struct lista *prox;
};
typedef struct lista Lista;

/*função de inicialização: retorna uma lista vazia*/
Lista* inicializa(){
  return NULL;
}

//Pega tamanho da lista
int tamanho(Lista* l){
  Lista* p;
  int i = 0;
  for(p = l; p != NULL; p = p->prox){
    i++;
  }
  return i;
}

/*inserção no inicio: retorna a lista atualizada*/
Lista* insere(Lista* l, char nome[101], char telefone[15],
              char endereco[101], char cepString[20], char dataNascimento[15]){

  Lista* novo = (Lista*) malloc(sizeof(Lista));
  Contato* c = (Contato*) malloc(sizeof(Contato));


  //Cria nome
  strcpy(c->nome, nome);
  strcpy(c->telefone, telefone);
  strcpy(c->endereco, endereco);
  strcpy(c->cepString, cepString);
  strcpy(c->dataNascimento, dataNascimento);

  //insere na lista
  novo->contato = c;
  novo->prox = l;

  return novo;
}

void listaOrdenada(Lista* l){
  //CRIANDO ORDENACAO
  int tam = tamanho(l);
  // printf("%d\n", tam);
  int i, j;
  Lista* atual;
  Lista* p;
  Lista* aux;
  char nome[101];

  for(atual = l; atual != NULL; atual = atual->prox) {
    aux = atual;
    printf("%s\n", aux->contato->nome);
    if (strcmp(atual->contato->nome, aux->contato->nome) > 0) {
      strcpy(nome, atual->contato->nome);
      strcpy(atual->contato->nome, aux->contato->nome);
      strcpy(aux->contato->nome, nome);
    }
  }
}

/*funçao imprime: imprime valores dos elementos*/
void imprime(Lista* l){
  Lista* p;
  for(p = l; p != NULL; p = p->prox){
    printf("Nome: %s", p->contato->nome);
    printf("Telefone: %s", p->contato->telefone);
    printf("Endereço: %s", p->contato->endereco);
    printf("CEP: %s", p->contato->cepString);
    printf("Data de Nascimento: %s", p->contato->dataNascimento);
    for (int i=0; i<80; i++){
        printf("*");
    }
    printf("\n\n");
  }
}

void insereArquivo(Lista* l, FILE* contatos){
  Lista* p;
  for(p = l; p != NULL; p = p->prox){
    fprintf(contatos, "%s", p->contato->nome);
    fprintf(contatos, "%s", p->contato->telefone);
    fprintf(contatos, "%s", p->contato->endereco);
    fprintf(contatos, "%s", p->contato->cepString);
    fprintf(contatos, "%s", p->contato->dataNascimento);
    fprintf(contatos, "$\n");
  }
}

/*funçao vazia: retorna 1 se vazia ou 0 se nao vazia*/
int vazia(Lista* l){
  if(l == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

/*função busca: busca um elemento na lista*/
Lista* busca(Lista* l, char nome[101]){
  Lista* p;
  for(p = l; p != NULL; p=p->prox){
    if(strcmp(p->contato->nome, nome) == 0){
      printf("--Informações--\n");
      printf("Nome: %s", p->contato->nome);
      printf("Telefone: %s", p->contato->telefone);
      printf("Endereço: %s", p->contato->endereco);
      printf("CEP: %s", p->contato->cepString);
      printf("Data de Nascimento: %s\n", p->contato->dataNascimento);
      return p;
    }
  }

  printf("\nNão foi encontrado ninguem com o nome %s", nome);
  return NULL; //não achou o elemento
}

/*função retira: retira elemento da lista*/
Lista* retira(Lista* l, char nome[101]){
  Lista* ant = NULL; //ponteiro para elemento anterior
  Lista* p = l; //ponteiro para percorrer a lista_h
  int desejaVoltar;

  /*procura elemento na lista, guardando anterior*/
  while(p != NULL && strcmp(p->contato->nome, nome) != 0){
    ant = p;
    p = p->prox;
  }

  /*verifica se achou elemento*/
  if(p == NULL){
    printf("Não encontrei o contato %s\n\n", nome);
    return l; // não achou: retorna lista original
  }

  /*retira elemento*/
  if(ant == NULL){
    //retira primeiro elemento
    printf("Encontrei o contato %s\n\n", nome);
    busca(l, nome);
    printf("Deseja realmente excluir? (1)Sim, (2)Não\n");
    scanf("%d", &desejaVoltar);
    while (desejaVoltar != 1 && desejaVoltar !=2) {
      printf("ATENÇÃO* Opção invalida");
      printf("\nDeseja voltar para o menu? 1(Sim), 2(Não): ");
      scanf("%d", &desejaVoltar);
     }

     if(desejaVoltar == 1){
         printf("Contato Excluido!\n\n");
         l = p->prox;
         // system("clear");
     }
     else if(desejaVoltar == 2){
       return l;
     }
  }
  else{
      //retira elemento do meio da lista
      printf("Encontrei o contato %s\n\n", nome);
      busca(l, nome);
      printf("Deseja realmente excluir? (1)Sim, (2)Não\n");
      scanf("%d", &desejaVoltar);
      while (desejaVoltar != 1 && desejaVoltar !=2) {
        printf("ATENÇÃO* Opção invalida");
        printf("\nDeseja voltar para o menu? 1(Sim), 2(Não): ");
        scanf("%d", &desejaVoltar);
       }

       if(desejaVoltar == 1){
           printf("Contato Excluido!\n\n");
           ant->prox = p->prox;
           // system("clear");
       }
       else if(desejaVoltar == 2){
         return l;
       }
  }

  free(p);
  return l;
}

/*funcao libera lista*/
void libera(Lista* l){
  Lista* p = l;

  while (p != NULL){
    Lista* t = p->prox; //guarda referencia para o proximo elemento
    free(p); //libera memoria apontada por p
    p = t; //faz p apontar para o proximo
  }
}

#endif
