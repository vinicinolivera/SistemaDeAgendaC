#ifndef menu_h
#define menu_h

void paginaInicial();

//PAGINA INICIAL PROGRAMA (OP�OES)
void paginaInicial(){
    int i;
    // system("clear");

    for (i=0; i<80; i++){
        printf("*");
    }
    printf("\n\tAgenda de Contatos\n");
    for (i=0; i<80; i++){
        printf("*");
    }
    printf("\n");
    for (i=0; i<80; i++){
        printf("*");
    }
    printf("\n\tOPERACOES\n");
    for (i=0; i<80; i++){
        printf("*");
    }
    printf("\n(1)Cadastro novo contato\n");
    printf("(2)Remover contato\n");
    printf("(3)Visualizar contato\n");
    printf("(4)Visualizar todos os contatos\n");
    printf("(0)Para sair\n");
    for (i=0; i<80; i++){
        printf("*");
    }
    printf("\n");

}

#endif
