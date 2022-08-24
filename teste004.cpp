#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
# define SIZE 5
void enqueue();
void dequeue();
void show();
int inp_arr[SIZE];
int Rear = - 1;
int Front = - 1;
main()
{
	setlocale(LC_ALL, "Portuguese");
    int ch;
    while (1)
    {
        printf("1.Enfileirar\n");
        printf("2.Desenfileirar\n");
        printf("3.Mostrar\n");
        printf("4.Sair\n");
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
            exit(0);
            default:
            printf("Escolha uma opção válida...\n");
        } 
    } 
} 
 
void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
       printf("Lista cheia \n");
    else
    {
        if (Front == - 1)
      
        Front = 0;
        printf("Digite o código: ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
        printf("Elemento inserido: %d",inp_arr[SIZE]);
        printf("\n-----------------------\n");
        system("pause");
    	system("cls");
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Lista vazia. -001- \n");
        
        
        system("pause");
    	system("cls");
    }
    else
    {
        printf("Elemento deletado: %d\n", inp_arr[Front]);
        Front = Front + 1;
        system("pause");
    	system("cls");
    }
} 
 
void show()
{
    
    if (Front == - 1)
        printf("Lista vazia \n");
    else
    {
        printf("Lista: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}
