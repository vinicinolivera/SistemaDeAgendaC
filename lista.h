#ifndef lista_h
#define lista_h

struct contato{
  char nome[101];
  char telefone[15];
  char endereco[101];
  int cep;
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



/*inserção no inicio: retorna a lista atualizada*/
Lista* insere(Lista* l, char nome[101], char telefone[15],
              char endereco[101], int cep, char dataNascimento[15]){

  Lista* novo = (Lista*) malloc(sizeof(Lista));
  Contato* c = (Contato*) malloc(sizeof(Contato));
  //Cria nome
  strcpy(c->nome, nome);
  strcpy(c->telefone, telefone);
  strcpy(c->endereco, endereco);
  c->cep = cep;
  strcpy(c->dataNascimento, dataNascimento);

  //insere na lista
  novo->contato = c;
  novo->prox = l;
  return novo;
}

/*funçao imprime: imprime valores dos elementos*/
void imprime(Lista* l){
  Lista* p;
  for(p = l; p != NULL; p = p->prox){
    printf("Nome: %s\n", p->contato->nome);
    printf("Telefone: %s\n", p->contato->telefone);
    printf("Endereço: %s\n", p->contato->endereco);
    printf("CEP: %d\n", p->contato->cep);
    printf("Data de Nascimento: %s\n", p->contato->dataNascimento);
  }
}

void insereArquivo(Lista* l, FILE* contatos){
  Lista* p;
  for(p = l; p != NULL; p = p->prox){
    fprintf(contatos, "%s", p->contato->nome);
    fprintf(contatos, "%s", p->contato->telefone);
    fprintf(contatos, "%s", p->contato->endereco);
    fprintf(contatos, "%d", p->contato->cep);
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
      printf("CEP: %d\n", p->contato->cep);
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

  /*procura elemento na lista, guardando anterior*/
  while(p != NULL && strcmp(p->contato->nome, nome) != 0){
    ant = p;
    p = p->prox;
  }

  /*verifica se achou elemento*/
  if(p == NULL){
    return l; // não achou: retorna lista original
  }

  /*retira elemento*/
  if(ant == NULL){
    //retira primeiro elemento
    l = p->prox;
  }
  else{
      //retira elemento do meio da lista
      ant->prox = p->prox;
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
