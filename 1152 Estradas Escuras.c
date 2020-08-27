#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

enum{FALSE,TRUE};

#define INFINITO INT_MAX

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoItem {
 TipoValorVertice Vertice;
 TipoPeso Peso; 
}TipoItem;
typedef struct TipoCelula *TipoApontador;
struct TipoCelula {
 TipoItem Item;
 TipoApontador Prox;
}TipoCelula; 
typedef struct TipoLista {
TipoApontador Primeiro, Ultimo;
}TipoLista;
typedef struct TipoGrafo {
 TipoLista Adj[200001];
 TipoValorVertice NumVertices;
 int NumArestas;
} TipoGrafo;

typedef int TipoIndice;
typedef TipoItem Vetor[200001];
TipoApontador Aux;
int FimListaAdj;
TipoValorVertice V1, V2, Adj;
int SomaPeso = 0;
TipoGrafo Grafo;
TipoPeso Peso;
TipoIndice n; 
TipoValorVertice Raiz;

struct LOC_AgmPrim {
 TipoPeso P[200001];
 TipoValorVertice Pos[200001];
};

void prim(TipoGrafo *Grafo, TipoValorVertice *Raiz);
void fazLista(TipoLista *Lista);
int listaCircular(TipoLista Lista);
void insereLista(TipoItem *celulAux, TipoLista *Lista);
void fazGraph(TipoGrafo *Grafo);
void insreAr(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *PESO, TipoGrafo *Grafo);
int ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);
void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *PESO, TipoApontador *Prox, int *FimListaAdj);
void LiberaGrafo(TipoGrafo *Grafo);
void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *Indx, TipoPeso *P, TipoValorVertice *Pos);
void Constroi(TipoItem *Indx, TipoPeso *P, TipoValorVertice *Pos);
TipoItem RetiraMinInd(TipoItem *Indx, TipoPeso *P, TipoValorVertice *Pos);
void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *Indx,TipoPeso *P, TipoValorVertice *Pos);
void prim(TipoGrafo *Grafo, TipoValorVertice *Raiz);

int main(int argc, char *argv[]){

 int V = 0, Ar = 0, i = 0, PesoInicial = 0, economia = 0;
  
 while(TRUE){
  scanf("%d%d",&V,&Ar);
  if(V==0||Ar==0) break;
  
  if((1<=V) && (V<=200000) && (V-1<=Ar) && (Ar<=200000)){
    
   Grafo.NumVertices = V;
   Grafo.NumArestas = Ar;
   fazGraph(&Grafo); 

   for(i=0; i<Ar; i++){

    scanf("%d %d %d", &V1, &V2, &Peso);

    if((V1 != V2) && (0<=V1) && (V2<V)){
     insreAr(&V1, &V2, &Peso, &Grafo); /* Grafo nao direcionado */
     insreAr(&V2, &V1, &Peso, &Grafo);
     PesoInicial += Peso;
    }
   }

   Raiz = 0;
   prim(&Grafo, &Raiz);
   economia = PesoInicial-SomaPeso;

   printf("%d\n", economia);

   PesoInicial = 0;
   economia = 0;
   SomaPeso = 0;
  }
  else break;
 }
 LiberaGrafo(&Grafo); 
 return 0;
}

void fazLista(TipoLista *Lista){
 
 Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
 Lista->Ultimo = Lista->Primeiro;
 Lista->Primeiro->Prox = NULL;
}

int listaCircular(TipoLista Lista){ return (Lista.Primeiro == Lista.Ultimo); }

void insereLista(TipoItem *celulAux, TipoLista *Lista){ /* Insere depois do ultimo item da lista */

 Lista->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
 Lista->Ultimo = Lista->Ultimo->Prox;
 Lista->Ultimo->Item = *celulAux;
 Lista->Ultimo->Prox = NULL;
}

void fazGraph(TipoGrafo *Grafo){
 long i;
 for(i = 0; i < Grafo->NumVertices; i++) fazLista(&Grafo->Adj[i]);
}

void insreAr(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *PESO, TipoGrafo *Grafo){
 TipoItem AuxX;
 AuxX.Vertice = *V2;
 AuxX.Peso = *PESO;
 insereLista(&AuxX, &Grafo->Adj[*V1]);
}
int ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo){
 return (Grafo->Adj[*Vertice].Primeiro == Grafo->Adj[*Vertice].Ultimo);
}
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo){
 return (Grafo->Adj[*Vertice].Primeiro->Prox); 
}

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, int *FimListaAdj){ /* Retorna Adj e Peso do Item apontado por Prox */

 *Adj = (*Prox)->Item.Vertice;  
 *Peso = (*Prox)->Item.Peso;
 *Prox = (*Prox)->Prox;

 if(*Prox == NULL) *FimListaAdj = TRUE;
}
void LiberaGrafo(TipoGrafo *Grafo){
 TipoApontador AuxAnterior, Aux;
 long i;

 for(i=0;i<Grafo->NumVertices; i++){ 
  Aux = Grafo->Adj[i].Primeiro->Prox;
  free(Grafo->Adj[i].Primeiro);
  Grafo->Adj[i].Primeiro=NULL;
  while(Aux != NULL){
   AuxAnterior = Aux;
   Aux = Aux->Prox;
   free(AuxAnterior);
  }
 }
 Grafo->NumVertices = 0;
}

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *Indx, TipoPeso *P, TipoValorVertice *Pos){
 TipoIndice k = Esq;
 int j = k * 2;
 TipoItem x;
 x = Indx[k];

 while(j <= Dir){ 
  if(j < Dir){ if(P[Indx[j].Peso] > P[Indx[j+1].Peso]) j++; }
  
  if(P[x.Peso] <= P[Indx[j].Peso]) goto L999;
  
  Indx[k] = Indx[j]; Pos[Indx[j].Peso] = k;
  k = j; j = k * 2;
 }
 L999: Indx[k] = x;
 Pos[x.Peso] = k;
}
void Constroi(TipoItem *Indx, TipoPeso *P, TipoValorVertice *Pos){
 TipoIndice Esq;
 Esq = (n/2) + 1;
 while(Esq > 1){ 
 Esq--; 
 RefazInd(Esq, n, Indx, P, Pos); 
 }
}
TipoItem RetiraMinInd(TipoItem *Indx, TipoPeso *P, TipoValorVertice *Pos){

 TipoItem Result;

 Result = Indx[1]; Indx[1] = Indx[n];
 Pos[Indx[n].Peso] = 1; n--;
 RefazInd(1, n, Indx, P, Pos);
 return Result;
}
void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *Indx,TipoPeso *P, TipoValorVertice *Pos){
 TipoItem x;
 P[Indx[i].Peso] = ChaveNova;

 while(i > 1 && P[Indx[i / 2].Peso] > P[Indx[i].Peso]){ 
  x = Indx[i / 2]; 
  Indx[i / 2] = Indx[i];
  Pos[Indx[i].Peso] = i / 2; 
  Indx[i] = x;
  Pos[x.Peso] = i; 
  i /= 2;
 }
}

void prim(TipoGrafo *Grafo, TipoValorVertice *Raiz){
 
 int Antecessor[Grafo->NumVertices+1];
 int Itensheap[Grafo->NumVertices+1];
 Vetor A;
 TipoPeso P[Grafo->NumVertices + 1];
 TipoValorVertice Pos[Grafo->NumVertices + 1];
 TipoValorVertice u, v;
 TipoItem TEMP;

 for(u = 0; u <= Grafo->NumVertices; u++){ 
  Antecessor[u] = -1;
  P[u] = INFINITO;
  A[u+1].Peso = u;   
  Itensheap[u] = TRUE;
  Pos[u] = u + 1;
 }
 
 n = Grafo->NumVertices; 
 P[*Raiz] = 0;
 Constroi(A, P, Pos);

 while(n >= 1){  /* Enquanto heap cheio... */
  TEMP = RetiraMinInd(A, P, Pos);
  u = TEMP.Peso; 
  Itensheap[u] = FALSE;
  if (u != *Raiz)
  SomaPeso += P[u];

  if(!ListaAdjVazia(&u, Grafo)){
   Aux = PrimeiroListaAdj(&u, Grafo);
   FimListaAdj = FALSE;
   while(!FimListaAdj){ 
    ProxAdj(&u, Grafo, &v, &Peso, &Aux, &FimListaAdj);
    if(Itensheap[v] && Peso < P[v]){ 
     Antecessor[v] = u;
     DiminuiChaveInd(Pos[v], Peso, A, P, Pos);
    }
   }
  }
 }  
}