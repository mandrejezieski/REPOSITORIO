#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 5

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
}FILA;

void menu();
void inicializaFila(FILA *f);
void enfileira(char *nomeLivro, char *nomeAutor, int codigo, float preco, FILA *f);
void desenfileira(FILA *f);
void imprimeFila(FILA *f);
void limpaFila(FILA *f);

int main(){
    int sel=0, codigo=0;
    char nomeLivro[20];
    char nomeAutor[30];
    float preco;
    FILA *f1 = (FILA*) malloc(sizeof(FILA));

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
				printf("\nCodigo: ");
                scanf("%d",&codigo);
                printf("\nNome do livro: ");
                scanf("%s",nomeLivro);
                printf("\nNome do autor: ");
                scanf("%s",nomeAutor);
                printf("\nPreco do livro: ");
                scanf("%f",&preco);
                

                enfileira(nomeLivro, nomeAutor, codigo, preco, f1);
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
                //limpaFila(f1);
                printf("\nPrograma finalizado =)");
                exit(0);
                break;

            default: 
                printf("\nOpcao Invalida!");
                break;
            }
        }
    }

    return 0;
}



void menu(){
	int op = 9;
	printf("\nDigite 0 para iniciar: \n");
	scanf("%d",&op);
	while(op == 9){
	printf("\n-----------------------------------");
	printf("\n             M.A.P.A. ");
	printf("\nAluno: Misael Andrejezieski");
	printf("\nR.A.: 2018609-5");
    
    printf("\n-----------------------------------");
	void imprimeFila(FILA *f);
	
    printf("\n---- ---- ---- MENU ---- ---- ----");
    printf("\n\t1. Insere livro");
    printf("\n\t2. Deleta livro");
    printf("\n\t3. Imprime lista de livros");
    printf("\n\t4. Esvaziar a Fila");
    printf("\n\t5. Sair");
    printf("\n-----------------------------------");
	}
	
}

void inicializaFila(FILA *f){
    
    f->ini = NULL;
    f->fim = NULL;	
	
}

void enfileira(char *nomeLivro, char *nomeAutor, int codigo,float preco,  FILA *f){
    NO *ptr = (NO*) malloc (sizeof(NO));
    if(ptr == NULL){
        printf("\nErro de Alocacao!");
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
    }
    system("cls");
}

void desenfileira(FILA *f){
    NO *ptr = f->ini;
    if(ptr != NULL){
        f->ini = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
        printf("Livro deletado!!!");
        if(f->ini == NULL){
            f->fim = NULL;
        }
    } else{
        printf("\nFila Vazia!");
    }

}

void imprimeFila(FILA *f){
    NO *ptr = f->ini;
    if(ptr != NULL){
        while(ptr != NULL){
            printf("\n*****************************");
            printf("\nCodigo do livro: %d", ptr->codigo);
            printf("\nNome do livro: %s", ptr->nomeLivro);
            printf("\nNome do autor: %s", ptr->nomeAutor);
            printf("\nPreco do livro: R$ %.2f", ptr->preco);
            printf("\n*****************************");
            ptr = ptr->prox;
        }

    }else{
        printf("\nFila Vazia!");
    }
    
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

    } else {
        printf("\nFila Vazia!");
    }
}
