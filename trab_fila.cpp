#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*prot�tipos e estruturas para manipula��o
do tipo fila*/

typedef struct filano FilaNo;
struct filano{
	int matricula;
	FilaNo* prox;
};

typedef struct fila Fila;
struct fila{
	FilaNo* ini;
	FilaNo* fim;
};

Fila* fila_cria(void);
void fila_insere(Fila* f, int n);
int fila_retira(Fila* f);
int fila_vazia(Fila* f);
void imprime_fila(Fila* f);
void liberar_fila(Fila* f);

/*prot�tipos e estruturas para manipula��o
do tipo lista*/

typedef struct no No;
struct no{
	int ano;
	char* autor;
	char* titulo;
	int quant;

	
	Fila* alunos;
	No* prox;
};

typedef struct lista Lista;
struct lista{
	No* ini;
	No* fim;
};

Lista* criar_lista(void);
void adicionar_livro(Lista* l);
void inserir_inicio(Lista* l,No* liv);
void inserir_fim(Lista* l,No* liv);
void inserir_ordenado(Lista* l,No* liv);
void insere_apos(No* liv, No* ref);
int verifica_ordem_alfabetica(No* a, No* b);
void imprimir_lista(Lista* l);

/*prot�tipos e estruturas que auxiliam
emprestimos e devolu��es*/

typedef struct noem NoEm;
struct noem{
	int matricula;
	char* livro;
	int exemplar;
	NoEm* prox;
};

typedef struct emprestados Emprestados;
struct emprestados{
	NoEm* ini;
	NoEm* fim;
};

Emprestados* criar_emprestimos();
char* ler_livro();
void emprestar_livro(Lista* l,Emprestados* e, int mat, char* livro);
void devolver_livro(Lista* l,Emprestados* e, int mat, char* livro);
void retira_emprestimo(Emprestados* e, NoEm* retirar);

//fun��o main

int main(void){
	Lista* lis = criar_lista();
	Emprestados* emp = criar_emprestimos();
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		adicionar_livro(lis);
	}
	int mat;
	scanf("%d\n",&mat);
	while(mat!=-1){
		char* livro=ler_livro();
		char comando=getchar();
		switch(comando){
			case 'E':
				emprestar_livro(lis,emp,mat,livro);
				break;
			case 'D':
				devolver_livro(lis,emp,mat,livro);
				break;
			default:
				break;
		}
		scanf("%d\n",&mat);
	}
	imprimir_lista(lis);
	return 0;
}

/*********************************************
 *fun��es para manipula��o da lista de Livros*
 *********************************************/

/*cria uma nova lista com
inicio e fim aponatndo para NULL*/
Lista* criar_lista(void){
	Lista* nova = (Lista*)malloc(sizeof(Lista));
	if(nova == NULL) exit(1);
	nova->ini = NULL;
	nova->fim = NULL;
	return nova;
}

/*adiciona um novo livro na lista
contendo as informa��es lidas na
fun��o*/
void adicionar_livro(Lista* l){
	No* novo_livro=(No*)malloc(sizeof(No));

	int novo_ano, nova_quant;
	int dim_aut=20, dim_tit=20, cont1=0, cont2=0;
	char letra;

	/* Realiza leituras para preencher
	as informa��es do novo livro a ser
	inserido*/
	scanf("%d\n",&novo_ano);
	novo_livro->ano=novo_ano;

	novo_livro->autor=(char*)malloc(dim_aut*sizeof(char));
	while((letra=getchar())!='\n'){
		if(cont1==dim_aut){
			dim_aut=dim_aut*2;
			novo_livro->autor=(char*)realloc(novo_livro->autor,dim_aut*sizeof(char));
		}
		novo_livro->autor[cont1]=letra;
		cont1++;
	}
	novo_livro->autor=(char*)realloc(novo_livro->autor,(cont1+1)*sizeof(char));
	novo_livro->autor[cont1]='\0';

	novo_livro->titulo=(char*)malloc(dim_tit*sizeof(char));
	while((letra=getchar())!='\n'){
		if(cont2==dim_tit){
			dim_tit=dim_tit*2;
			novo_livro->titulo=(char*)realloc(novo_livro->titulo,dim_tit*sizeof(char));
		}
		novo_livro->titulo[cont2]=letra;
		cont2++;
	}
	novo_livro->titulo=(char*)realloc(novo_livro->titulo,(cont2+1)*sizeof(char));
	novo_livro->titulo[cont2]='\0';

	scanf("%d",&nova_quant);
	novo_livro->quant=nova_quant;

	
	novo_livro->alunos=fila_cria();
	
	/*verfifica em qual posi��o da lista
	o novo livro deve ser inserido*/
	if(l->ini == NULL || novo_livro->ano < l->ini->ano)
		inserir_inicio(l,novo_livro);
	else if(novo_livro->ano > l->fim->ano)
		inserir_fim(l,novo_livro);
	else{
		inserir_ordenado(l,novo_livro);
	}
}

//insere um livro no inicio da lista
void inserir_inicio(Lista* l,No* liv){
	if(l->ini!=NULL)
		liv->prox=l->ini;
	else
		l->fim=liv;
	l->ini=liv;
}

//insere um livro no final da fila
void inserir_fim(Lista* l,No* liv){
	l->fim->prox=liv;
	liv->prox=NULL;
	l->fim=liv;
}

/*busca uma posi��o adequada para o novo livro e
o insere na devida posi��o*/
void inserir_ordenado(Lista* l,No* liv){
	No* ref=l->ini;
	No* ant=ref;
	while(liv->ano > ref->ano && ref->prox != NULL){
		ant=ref;
		ref=ref->prox;
	}
	ref=ant;
	if(ref->ano != liv->ano && ref->prox->ano != liv->ano){
		insere_apos(liv,ref);
	}else{
		if(ref->ano==liv->ano && (ref->prox==NULL || ref->prox->ano!=liv->ano)){
			if(verifica_ordem_alfabetica(liv,ref)){
				inserir_inicio(l,liv);
			}else{
				insere_apos(liv,ref);
			}
		}else{
			int loops=0;
			while(ref->prox != NULL && ref->prox->ano == liv->ano && verifica_ordem_alfabetica(ref->prox,liv)){
				ref=ref->prox;
				loops++;
			}
			if(loops==0 && ref==l->ini) inserir_inicio(l,liv);
			else insere_apos(liv,ref);
		}
	}
}

/*insere um livro apos um endere�o
especifico*/
void insere_apos(No* liv, No* ref){
	liv->prox=ref->prox;
	ref->prox=liv;
}

/* fun��o auxiliar para inserir livros em
ordem alfabetica*/
int verifica_ordem_alfabetica(No* a, No* b){
	int i=0;
	while(a->autor[i]==b->autor[i])
		i++;
	if(a->autor[i]<b->autor[i])
		return 1; // retorna verdadeiro se No* a vier antes de No* b
	else
		return 0;
}

/*imprime na tela a lista de livros e suas
respectivas informa��es*/
void imprimir_lista(Lista* l){
	No* p=l->ini;
	while(p!=NULL){
		printf("\n%d\n",p->ano);
		printf("%s\n",p->autor);
		printf("%s\n",p->titulo);
		
		imprime_fila(p->alunos);
		p=p->prox;
	}
}

/********************************************
 *fun��es para manipula��o da fila de Alunos*
 ********************************************/

//cria uma nova fila
Fila* fila_cria(void){
	Fila* nova = (Fila*)malloc(sizeof(Fila));
	nova->ini=NULL;
	nova->fim=NULL;
	return nova;
}

//insere um elemnto no final da fila
void fila_insere(Fila* f, int n){
	FilaNo* no = (FilaNo*)malloc(sizeof(FilaNo*));
	no->matricula=n;
	no->prox=NULL;

	if(f->fim!=NULL) f->fim->prox=no;
	else f->ini=no;
	f->fim=no;
}

//retira um elememto do come�o da fila
int fila_retira(Fila* f){
	FilaNo* p=f->ini;
	int v=p->matricula;
	if(f->ini==f->fim)
		f->ini=f->fim=NULL;
	else
		f->ini=p->prox;
	free(p);
	return v; //retorna o elemento retirado
}

//retorna verdadeiro se a fila estiver vazia
int fila_vazia(Fila* f){
	if(f->ini==NULL) return 1;
	else return 0;
}

//imprime na tela o estado atual da fila
void imprime_fila(Fila* f){
	if(fila_vazia(f))
		printf("fila vazia");
	else{
		FilaNo* p=f->ini;
		while(p!=NULL){
			printf("%d",p->matricula);
			if(p->prox!=NULL) printf(",");
			p=p->prox;
		}
	}
}

//libera a memoria da fila
void liberar_fila(Fila* f){
	FilaNo* p=f->ini;
	while(p!=NULL){
		FilaNo* aux=p->prox;
		free(p);
		p=aux;
	}
	free(f);
}

/**********************************************************
 *fun��es para auxiliar emprestimos e devolu��es de livros*
 **********************************************************/

Emprestados* criar_emprestimos(){
	Emprestados* novo=(Emprestados*)malloc(sizeof(Emprestados));
	novo->ini=NULL;
	novo->fim=NULL;
	return novo;
}

char* ler_livro(){
	char letra;
	int dim_aut=20,cont1=0;
	char* livro=(char*)malloc(dim_aut*sizeof(char));
	while((letra=getchar())!='\n'){
		if(cont1==dim_aut){
			dim_aut=dim_aut*2;
			livro=(char*)realloc(livro,dim_aut*sizeof(char));
		}
		livro[cont1]=letra;
		cont1++;
	}
	livro=(char*)realloc(livro,(cont1+1)*sizeof(char));
	livro[cont1]='\0';
	return livro;
}

void emprestar_livro(Lista* l,Emprestados* e, int mat, char* livro){
	No* p=l->ini;
	while(p!=NULL && strcmp(livro,p->titulo)){
		p=p->prox;
	}
	if(p!=NULL){
		if(pilha_vazia(p->livros)){
			fila_insere(p->alunos,mat);
		}else{
			NoEm* n=(NoEm*)malloc(sizeof(NoEm));
			n->matricula=mat;
			int tam=strlen(livro);
			n->livro=(char*)malloc(tam*sizeof(char));
			strcpy(n->livro,livro);
			n->exemplar=pilha_pop(p->livros);
			n->prox=NULL;
			if(e->ini!=NULL) e->fim->prox=n;
			else e->ini=n;
			e->fim=n;
		}
	}
}

void devolver_livro(Lista* l,Emprestados* e, int mat, char* livro){
	No* p=l->ini;
	while(p!=NULL && strcmp(livro,p->titulo)){
		p=p->prox;
	}
	if(p!=NULL){
		NoEm* n=e->ini;
		while(n!=NULL && (mat!=n->matricula || strcmp(livro,n->livro))){
			n=n->prox;
		}
		if(n!=NULL){
			pilha_push(p->livros,n->exemplar);
			retira_emprestimo(e,n);
			if(!fila_vazia(p->alunos)){
				emprestar_livro(l,e,p->alunos->ini->matricula,livro);
				fila_retira(p->alunos);
			}
		}
	}
}

void retira_emprestimo(Emprestados* e, NoEm* retirar){
	if(e->ini==e->fim){
		e->ini=e->fim=NULL;
	}else if(retirar==e->ini){
		e->ini=retirar->prox;
	}else{
		NoEm* ant=e->ini;
		while(ant->prox != retirar){
			ant=ant->prox;
		}
		ant->prox=retirar->prox;
		if(retirar==e->fim){
			e->fim=ant;
		}
	}
	free(retirar);
}
