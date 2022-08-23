#include <iostream>
#include <cstdlib>
#define tamanho 3
using namespace std;
struct Aluno{
    int mat;
    
};
struct FILA{
      int inicio;
      int fim;
      int item [tamanho];
}; 
int main(){
    Aluno a;
    FILA f;
    int op;
    cout << "-------------------------------------\n" ;
    cout << "- 1 - Inserir Aluno              ----\n" ;
    cout << "- 2 - Exibir dados do Aluno      ----\n" ;
    cout << "- 3 - Aluno aprovados            ----\n" ;
    cout << "- 4 - Remover Aluno              ----\n" ;
    cout << "- 9 - Sair                       ----\n" ;
    cout << "-------------------------------------\n" ;

    cout << "Selecione a opção desejada: ";
    cin >> op;
    system("cls");
    switch(op){
        case 1:
            system("cls");
            cout<<"\nMatricula: ";
            cin>>a.mat;
            
            void enfileira(FILA &f, int x);

                break;
        case 9: 
            system("cls");
            cout<<"\nPROGRAMA FINALIZADO !!!"<<endl;
            return 0;


    }
}
void iniciaFila(FILA &f) {
     f.inicio = 0;
     f.fim=f.inicio;
}
bool filaVazia(FILA f){
     return f.fim==0;
     printf("lista vazia.");
}
bool filaCheia(FILA f){
     return f.fim==tamanho;
     printf("lista cheia..");
}
void enfileira(FILA &f, int x){
    if(!filaCheia(f))
       f.item[f.fim++]=x;
    else
       cout<<"fila cheia\n";   
}
void desenfileiraf(FILA &f){
     if(!filaVazia(f)){
        cout<<"desenfileirou "<<f.item[f.inicio]<<endl;
        for(int i=0;i<f.fim-1;i++)
            f.item[i]=f.item[i+1];               
        f.fim--;
     }
     else
        cout<<"fila vazia\n";
} 

int desenfileira(FILA &f){
     if(!filaVazia(f)){
        int n=f.item[f.inicio];
        for(int i=0;i<f.fim-1;i++)
            f.item[i]=f.item[i+1];               
        f.fim--;
        return n;
     }
     cout<<"fila vazia\n";
     return -1; 
} 
void mostra(FILA f){
     if(!filaVazia(f)){
        for(int i=f.inicio;i<f.fim;i++)
              cout<<f.item[i]<<' ';

        cout<<endl;        
     } 
     else
     cout<<"fila vazia\n";
} 
