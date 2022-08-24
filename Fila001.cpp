#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct NO{
	char nomeLivro[20];
    char nomeAutor[30];
    int codigo;
    float preco;
    struct NO *prox;
 }NO;

typedef struct FILA{
    NO *ini;
    NO *fim;
    int tam;  
}FILA;

struct NO;
void menu();
void inicializaFila(FILA *f);
void enfileira(char *nomeLivro, char *nomeAutor, int codigo, float preco, FILA *f);
void desenfileira(FILA *f);
void imprimeFila(FILA *f);
void limpaFila(FILA *f);

int main(){
	
	setlocale(LC_ALL, "Portuguese");

	
    int sel=0; int codigo=0;
    char nomeLivro[20];
    char nomeAutor[30];
    float preco;
    FILA *f1 = (FILA*) malloc(sizeof(FILA));
	
	f1->ini= NULL;
    if(f1 == NULL){
        printf("\nErro de alocacao!");
        exit(-1);
    } else{        
        inicializaFila(f1);
        
        while (sel != 5){
            menu();
            printf("\nOpcao: ");
            scanf("%d", &sel);
            switch (sel){
            case 1: 
                 
            	
            	if(codigo < 5){
            		 codigo ++;
               		 printf("\nNome do livro: ");
               		 scanf("%s",nomeLivro);
               		 printf("\nNome do autor: ");
               		 scanf("%s",nomeAutor);
               		 printf("\nPreço do livro: ");
               		 scanf("%f",&preco);
               		 enfileira(nomeLivro, nomeAutor, codigo, preco, f1);
               		 break;
				}else{
					printf("Fila Cheia. 002");
					system("pause");
					system("cls");
					break;
				}
				
				/*printf("\nCódigo: ");
                scanf("%d",&codigo);
                printf("\nNome do livro: ");
                scanf("%s",nomeLivro);
                printf("\nNome do autor: ");
                scanf("%s",nomeAutor);
                printf("\nPreço do livro: ");
                scanf("%f",&preco);*/
                

                //enfileira(nomeLivro, nomeAutor, codigo, preco, f1);
                break;

            case 2: 
                desenfileira(f1);
                break;

            case 3: 
                imprimeFila(f1);
                break;
                
            case 4:
                limpaFila(f1);
                break;

            case 5: 
                printf("\nPrograma finalizado ;) \n");
                system("pause");
                exit(0);
                break;

            default: 
                printf("\nOpção Inválida!");
                break;
            }
        }
    }

    return 0;
}



void menu(){
	
	printf("\n");
	printf("\n             M.A.P.A. ");
	printf("\nAluno: Misael Andrejezieski");
	printf("\nR.A.: 2018609-5");
    
    printf("\n");
	void imprimeFila(FILA *f);
	
    printf("\n---- ---- ---- MENU ---- ---- ----");
    printf("\n\t1. Insere livro");
    printf("\n\t2. Deleta livro");
    printf("\n\t3. Imprime lista de livros");
    printf("\n\t4. Esvaziar a Fila");
    printf("\n\t5. Sair");
    printf("\n");
}

void inicializaFila(FILA *f){
    
    f->ini = 0;
    f->fim = 0;	
}

void enfileira(char *nomeLivro, char *nomeAutor, int codigo,float preco,  FILA *f){
    NO *ptr = (NO*) malloc (sizeof(NO));
    ;
	if(ptr == NULL){
        printf("\nErro de Alocação!\n");
    } else{
    	strcpy(ptr->nomeLivro, nomeLivro);
        strcpy(ptr->nomeAutor, nomeAutor);
        ptr->codigo = codigo;
        ptr->preco = preco;
        ptr->prox = NULL;
        	if(f->ini == NULL){
           		 f->ini = ptr;
        	} else{
           		 f->fim->prox = ptr; 
        	}
   			 f->fim = ptr;
    		printf("\nLivro %s", ptr->nomeLivro);
    		printf(" insirido na fila.\n");
    	}
    	system("pause");
    	system("cls");
	}

void desenfileira(FILA *f){
    NO *ptr = f->ini;
    
    if(ptr != NULL){
    	printf("Livro %s", ptr->nomeLivro);
    	printf(" DELETADO.\n");
        f->ini = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
        
        	system("pause");
   			system("cls");
        if(f->ini == NULL){
           f->fim = NULL;
        }
    } else{
        printf("\nFila Vazia.\n");
        system("pause");
        system("cls");
    }
}

void imprimeFila(FILA *f){
    NO *ptr = f->ini;
    printf("     ----- LISTA DE LIVROS -----");
    if(ptr != NULL){
        while(ptr != NULL){
            printf("\n");
            printf("\nCódigo do livro: %d", ptr->codigo);
            printf("\nNome do livro: %s", ptr->nomeLivro);
            printf("\nNome do autor: %s", ptr->nomeAutor);
            printf("\nPreço do livro: R$ %.2f", ptr->preco);
            printf("\n\n");
            ptr = ptr->prox;
            printf("     ----- ---- ----- -----\n");
            
        }

    }else{
        printf("\nFila Vazia.\n");
        
    }
   		system("pause");
        system("cls");
}

void limpaFila(FILA *f){

    NO *ptr = f->ini;
    NO *aux;
	
	 
    if(ptr != NULL){
        while(ptr != NULL){
            aux = ptr->prox;
            free(ptr);
            ptr = aux;
        }

        f->ini = NULL;
        f->fim = NULL;
        printf("Lista envaziada.\n");
		
    } else {
        printf("\nFila Vazia!\n");
        
    }
    	system("pause");
        system("cls");
    
}
