#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 5

struct fila
{
    int numeroelementos;
    int inicio;
    float elementos[TAMANHO];
    char descricao[20];
    int quantidade;
};

typedef struct fila Fila;

Fila *criarFila()
{
    Fila *f= (Fila*) malloc(sizeof(Fila));
    f->numeroelementos = 0;
    f->inicio = 0;
    return f;
}

void inserir(Fila *f, float valor,char nam[20],int qtd)
{
    if(f->numeroelementos == TAMANHO)
    {
        printf("Fila cheia.\n");
        return;
    }
    int fim = (f->inicio + f->numeroelementos) % TAMANHO;
    f->elementos[fim] = valor;
    f->descricao[fim]descricao= nam; 
  //aqui dá o erro de f->descricao[fim]= nam;
  //Warning: assignment makes integer from pointer without a cast [-Wint-conversion]
    f->quantidade[fim]=qtd; 
  //aqui da o erro: subscripted value is neither array nor pointer nor vector
   
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
    valor =f->elementos[f->inicio];
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
    printf("Conteúdo da fila\n");
    int i;
    for(i = 0; i < f->numeroelementos; i++)
        printf("%0.f\n",f->elementos[(f->inicio + i) % TAMANHO]);
    printf("\n");
}

int main()
{
    Fila *fila=criarFila();
    int opcao = -1;
    float item;
    int qtd;
    char nome[20];

    while(opcao != 0)
    {
        system("cls");
        printf("Escolha a opção desejada: \n");
        printf("1. Enfilera\n");
        printf("2. Retira \n");
        printf("3. Mostra a fila\n");
        printf("0. Fim\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1 : //insere
            printf("Digite o codigo: ");
            scanf("%f", &item);
            printf("Digite a descricao da peca: ");
            fflush(stdin);
            gets(nome);
            printf("Digite a quantidade de pecas: ");
            scanf("%d", &qtd);
            inserir(fila,item,nome,qtd);
            break;
        case 2 : //retira
            retirar(fila);
            break;
        case 3 : //mostra
            mostrarFila(fila);
            break;
        }//switch
        printf("\n");
        system("pause");
    }
    destruirFila(fila);
}
