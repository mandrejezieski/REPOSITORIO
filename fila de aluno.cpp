#include <stdio.h>
#include <string.h>

struct escola
{
   char nome[50];
   int n1,n2,n3,n4;
}*m2,*m3;

int i=0,y=0;

typedef struct escola fila;
void menu1(void);
void menu(void);
int insere(fila *emp, int c);
int retira(int c);
void status(int c);
void imptopo(fila *imp, int c);
void lista(fila *list, int c);
int cria(void);
int libera(void);
fila * copia_fila(fila *p);
int filas_iguais(fila *p1, fila *p2);
void show(fila *p);

int main()
{
   fila aluno[10];

   int j=0,op,igual;
   for(i=0;i<10;i++)
   {
      aluno[i].n1=0;
      aluno[i].n2=0;
      aluno[i].n3=0;
      aluno[i].n4=0;
      aluno[i].nome[0]='{FONTE}';
   }
   i=0;
      
   for(;;)
   {
      menu();
      scanf("%i",&op);
      //system("cls");

      switch(op)
      {
         case 0:
           // exit(0);
            break;
         case 1:
            cria();
            break;
         case 2:
            i=insere(aluno,i);
            break;
         case 3:
            i=retira(i);
            break;
         case 4:
            status(i);
            break;
         case 5:
            lista(aluno,i-1);
            break;
         case 6:
            imptopo(aluno,i-1);
            break;
         case 7:
            libera();
            break;
         case 8:
            m3=copia_fila(aluno);
            //free(m2);
            break; 
         case 9:
            igual=filas_iguais(aluno,m3);
            //system("cls");
            if(igual==1)
               printf("As filas sao identicas\n");
            else
               printf("As filas sao diferentes\n");
            //sleep(4);
            break;
         default:
            printf("comando (%i) desconhecido\n",op);
            //sleep(4);
            break;
      }
   }
};

void menu1(void)
{
   //system("cls");
   printf("*******************MENU*******************\n\n");
   printf("1 - retira 1 dado\n");
   printf("2 - retira 2 dados\n");
   printf("3 - retira n dados\n");
   printf("4 - retira todos os dados da fila\n");
   printf("\n*****************************************\n");
   printf("Digite sua opcao: ");
};

void menu(void)
{
  // system("cls");
   printf("*******************MENU*********************\n\n");
   printf("0 - sai do programa\n");
   printf("1 - cria uma fila\n");
   printf("2 - insere um elemento na fila\n");
   printf("3 - chama menu de retira\n");
   printf("4 - verifica se a fila esta vazia\n");
   printf("5 - lista o conteudo da fila\n");
   printf("6 - imprime o ultimo elemento da fila\n");
   printf("7 - libera espaco de memoria alocado\n");
   printf("8 - faz uma copia indentica da fila aluno\n");
   printf("9 - compara filas\n");
   printf("\n********************************************\n");
   printf("Digite sua opcao: ");
};

int insere(fila *emp, int c)
{
   int a;
   if(c<=9)
   {  
      getchar();
      for(a=c;a>=0;a--)
      {
         strcpy(emp[a+1].nome,emp[a].nome);
         emp[a+1].n1=emp[a].n1;
         emp[a+1].n2=emp[a].n2;
         emp[a+1].n3=emp[a].n3;
         emp[a+1].n4=emp[a].n4;
      }
      printf("Digite o nome do aluno\n");  
      fgets(emp[0].nome,50,stdin);
      printf("Digite a nota do 1 bimestre\n");
      scanf("%i",&emp[0].n1);  
      printf("Digite a nota do 2 bimestre\n");
      scanf("%i",&emp[0].n2); 
      printf("Digite a nota do 3 bimestre\n");
      scanf("%i",&emp[0].n3); 
      printf("Digite a nota do 4 bimestre\n");
      scanf("%i",&emp[0].n4); 
      c++;
   }
   else
   {
      printf("A fila esta cheia!!!\n");
      //sleep(4);
   }
   return c;
};

int retira(int c)
{
   int k,a;
   if(c>0)
   {
      menu1();
      scanf("%i",&k);
      switch(k)
      {
         case 1:
            c--;
            return c;
         case 2:
            if(c>=2)
          c=c-2;
       else
       {
          printf("Impossivel retirar!!!\n");
          //sleep(3);
       }
            return c;
         case 3:
           // system("cls");
            printf("Digite a quantidade de elementos a ser retirados: ");
            scanf("%i",&a);
            if(a>c)
            {
               printf("\n\nImpossivel retirar!!!\n");
              // sleep(4);
            }
            else
               c=c-a;
            return c;
         case 4:
            c=0;
            return c;
         default:
            return c;
      }
   }
   else
   {
      printf("Verifique se a fila foi criada ou se ela esta vazia!!\n");
      //sleep(4);
   }
   return c;
};

void status(int c)
{ 
   if(c==0)
      printf("A fila esta vazia\n");
   else
      printf("A fila contem dados\n");
   //sleep(4);
};

void imptopo(fila *imp, int c)
{
   if(c>=0)
   {
      printf("Ultimo dado contido na fila e:\n\n");
      printf("Nome do aluno: %s\n",imp[c].nome);
      printf("Nota 1 bimestre: %i\n",imp[c].n1);
      printf("Nota 2 bimestre: %i\n",imp[c].n2);
      printf("Nota 3 bimestre: %i\n",imp[c].n3);
      printf("Nota 4 bimestre: %i\n",imp[c].n4);
   }
   else
      printf("Verifique se a fila foi criada ou se ela esta vazia!!\n");
  // sleep(4);
};

void lista(fila *list, int c)
{

   int m=0;
   while(m<=c)
   {
      printf("Nome do aluno: %s\n",list[m].nome);
      printf("Nota 1 bimestre: %i\n",list[m].n1);
      printf("Nota 2 bimestre: %i\n",list[m].n2);
      printf("Nota 3 bimestre: %i\n",list[m].n3);
      printf("Nota 4 bimestre: %i\n\n\n",list[m].n4);
      m++;
   }  
   if(c==-1)
      printf("Verifique se a fila foi criada ou se ela esta vazia!!\n");
  // sleep(4);   
};

int cria(void)
{
 //  m3=(fila *) calloc(10,sizeof (fila));   
  // system("cls");
   printf("Foi alocado um espaco em memoria para outra fila\n"); 
  // sleep(4);
   return 0;
};

int libera(void)
{
  // free(m3);
   //system("cls");
   printf("Foi liberado da memoria o espaco de m3\n");
   //sleep(4);
   return 0;
};

fila * copia_fila(fila *p)
{
   int c;
  // m2=(fila *) calloc(10,sizeof (fila));
   for(c=0;c<i;c++)
   {
      strcpy(m2->nome,p->nome);
      m2->n1=p->n1;
      m2->n2=p->n2;
      m2->n3=p->n3;
      m2->n4=p->n4;
      m2++;
      p++;
   }
   y=i;
   m2=m2-c;
   return m2;
};

int filas_iguais(fila *p1, fila *p2)
{
   int c=0,a=0;
   char f;
   
   while(a<10)
   {
      if((y==i)&&(p1->n1==p2->n1)&&(p1->n2==p2->n2)&&(p1->n3==p2->n3)&&(p1->n4==p2->n4)&&(strcmp(p1->nome,p2->nome)==0))
      ;
      else
      {
         return 0;
      }
      p1++;
      p2++;
      a++;
   }
   return 1;
};

void show(fila *p)
{
   int c;
   for(c=0;c<i;c++)
   {
      printf("%s\n",p->nome);
      printf("%i\n",p->n1);
      printf("%i\n",p->n2);
      printf("%i\n",p->n3);
      printf("%i\n",p->n4);
      p++;
      //sleep(4);
   }
};
