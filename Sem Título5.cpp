#include  <stdio.h>
#include  <stdlib.h>
#include <locale.h>
#define TRUE 1 
#define FALSE 0 
#define FULL 10

struct  node 
{ 
    int  data ; 
    struct  node  * next ; 
}; 
typedef  struct  node  node ;

 struct fila_de_estrutura { 
    int contagem = 0; 
    no  * frente ; 
    no  * traseiro ; 
}; 
typedef  struct  queue  queue ;

void  inicializar ( fila  * q ) 
{ 
    q -> contagem  =  0 ; 
    q -> frente  =  NULL ; 
    q -> traseira  =  NULL ; 
}

int  isempty ( fila  * q ) 
{ 
    return  ( q -> traseiro  ==  NULL ); 
}

void  enqueue ( queue  * q ,  int  value ) 
{ 
    if  ( q -> count  <  FULL ) 
    { 
        node  * tmp ; 
        tmp  =  malloc ( sizeof ( no )); 
        tmp -> dados  =  valor ; 
        tmp -> proximo  =  NULL ; 
        if ( ! isempty ( q )) 
        { 
            q -> traseiro-> proximo  =  tmp ; 
            q -> traseira  =  tmp ; 
        } 
        else 
        { 
            q -> frente  =  q -> traseira  =  tmp ; 
        } 
        q -> contagem ++ ; 
    } 
    else 
    { 
        printf ( "Lista cheia \n " ); 
    } 
}

int  dequeue ( fila  * q ) 
{ 
    node  * tmp ; 
    int  n  =  q -> frente -> dados ; 
    tmp  =  q -> frente ; 
    q -> frente  =  q -> frente -> proximo ; 
    q -> contagem - ; 
    livre ( tmp ); 
    retorno ( n ); 
}

void  display ( node  * head ) 
{ 
    if ( head  ==  NULL ) 
    { 
        printf ( "NULL \n " ); 
    } 
    else 
    { 
        printf ( "%d \n " ,  head  ->  data ); 
        display ( head -> next ); 
    } 
}

int  main () 
{ 

 setlocale(LC_ALL, "Portuguese");
 
    fila  * q ; 
    q  =  malloc ( sizeof ( fila )); 
    inicializar ( q ); 
    enfileirar ( q , 10 ); 
    enfileirar ( q , 20 ); 
    enfileirar ( q , 30 ); 
    printf ( "Fila antes da fila \n " ); 
    display ( q -> frente ); 
    desenfileirar ( q); 
    printf ( "Fila após desenfileiramento \n " ); 
    display ( q -> frente ); 
    retorna  0 ; 
}
