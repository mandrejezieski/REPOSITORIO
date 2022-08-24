#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
# define SIZE 5
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int fim = - 1;
int inicio = - 1;

typedef struct NO{
	char nomeLivro[20];
    char nomeAutor[30];
    int codigo;
    float preco;
    struct NO *prox;
 }NO;

main()
{
	setlocale(LC_ALL, "Portuguese");
    int ch;
    while (1)
    {
    	 printf("\n--------- M.A.P.A. --------\n");
        printf("1.Enfileirar\n");
        printf("2.Desenfileirar\n");
        printf("3.Mostrar\n");
        printf("4.Limpar\n");
        printf("5.Sair\n");
        printf("Digite um opção: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            limpa();
            case 5:  
            exit(0);
            default:
            printf("Escolha uma opção válida...\n");
        }   
    }
     
} 
 
void enqueue()
{
    int insert_item;
    if (fim == SIZE - 1)
       printf("Lista cheia \n");
    else
    {
        if (inicio == - 1)
      
        inicio = 0;
        printf("\n-----------------------\n");
        printf("\nDigite o código: \n");
        scanf("%d", &insert_item);
        fim = fim + 1;
        inp_arr[fim] = insert_item;
        printf("Elemento inserido: %d",inp_arr[SIZE]);
        printf("\n-----------------------\n");
        system("pause");
    	system("cls");
    }
} 
 
void dequeue()
{
    if (inicio == - 1 || inicio > fim)
    {
        printf("Lista vazia. -001- \n");
        
        
        system("pause");
    	system("cls");
    }
    else
    {
        printf("Elemento deletado: %d\n", inp_arr[inicio]);
        inicio = inicio + 1;
        system("pause");
    	system("cls");
    }
} 
 
void show()
{
    
    if (inicio == - 1)
        printf("Lista vazia \n");
    else
    {
    	
        printf(" -------- Lista --------- \n");
        for (int i = inicio; i <= fim; i++)
            printf("%d ", inp_arr[i]);
        printf("\n----------------------------\n");
        system("pause");
        system("cls");
    }
}

void limpa(){
	if (inicio == - 1)
        printf("Lista vazia \n");
    else
    {
    	
        printf(" -------- Lista --------- \n");
        for (int i = inicio; i <= fim; i++)
            inicio = NULL;
            fim = NULL;
        printf("\n----------------------------\n");
        system("pause");
        system("cls");
    }
}
