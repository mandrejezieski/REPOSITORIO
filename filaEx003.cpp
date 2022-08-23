#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

struct fila
{
    int numeroelementos;
    int inicio;
    float livros[TAMANHO];
    int codigo;
    
};


typedef struct fila Fila;

Fila *criarFila()
{
    Fila *f= (Fila*) malloc(sizeof(Fila));
    f->numeroelementos = 0;
    f->inicio = 0;
    return f;
}

void inserir(Fila *f, int codigo, char nomeLivro[20], char nomeAutor[30], float preco)
{
    if(f->numeroelementos == TAMANHO)
    {
        printf("Fila cheia.\n");
        return;
    }
    int fim = (f->inicio + f->numeroelementos) % TAMANHO;
    f->livros[fim] ;
   
  f->numeroelementos++;
}

void retirar(Fila *f)
{
    float valor;
    if(f->numeroelementos == 0)
    {
        printf("fila vazia.\n");
        return;
    } //retira o elemento da fila
    valor =f->livros[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO;
    f->numeroelementos--;
    printf("Elemento retirado = %.0f\n",valor);
}

void destruirFila(Fila *f)
{
    free(f);
}

void mostrarFila(Fila *f)
{
    printf("Conteudo da fila\n");
    int i;
    for(i = 0; i < f->numeroelementos; i++)
        printf("%0.f\n",f->livros[(f->inicio + i) % TAMANHO]);
        printf(f->codigo);
    printf("\n");
}

int main()
{
    Fila *fila=criarFila();
    int opcao = -1;

    int codigo;
    char nomeLivro[20];
    char nomeAutor[30];
    float preco;

    while(opcao != 0)
    {
        system("cls");
        printf("**** Escolha a opcao desejada **** \n");
        printf("1. Enfilera livros\n");
        printf("2. Retira livro\n");
        printf("3. Mostra a fila\n");
        printf("4. Destruir a fila\n");
        printf("0. Fim\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1 : //insere
            printf("Digite o codigo: ");
            scanf("%d", &codigo);
            printf("Digite o nome do livro: ");
            scanf("%s", nomeLivro);
            printf("Digite o nome do autor: ");
            scanf("%s", nomeAutor);
            printf("Digite o preco do livro: ");
            scanf("%f", &preco);
            inserir(fila,codigo,nomeLivro,nomeAutor,preco);
            break;
        case 2 : //retira
            retirar(fila);
            break;
        case 3 : //mostra
            mostrarFila(fila);
            break;
        case 4 :
        	destruirFila(fila);
        	break;
        }//switch
        printf("\n");
        system("pause");
    }
    
}
