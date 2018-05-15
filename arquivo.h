#ifndef arquivo_h
#define arquivo_h

int get_size(FILE* contatos);

int get_size(FILE* contatos){

    if(contatos == NULL)
        return 0;

    fseek(contatos, 0, SEEK_END);
    int size = ftell(contatos);
    fclose(contatos);

    return size;
}

#endif
