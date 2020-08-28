#include <stdio.h>
#define MAX 10

static int contador;
static int listaVisitados[MAX];

typedef struct grafo{ 
	int qtdVertices;  // a ordem do grafo
	int qtdArestas;  //
	int matrizAdj[MAX][MAX]; 
} tipo_grafo;


typedef struct lista { 
	int valor;
	struct lista *proximo;
}tipo_lista;

typedef struct no { 
   int vertice; 
   tipo_lista *adj; 
   struct no *proximo;
} tipo_no;

typedef struct grafo_dinamico {
   int V; 
   int A; 
   tipo_no *inicio; 
} tipo_grafoDinamico;



void inicializaGrafo(tipo_grafo *g,int qtdVertices){

	g->qtdArestas=0;
	g->qtdVertices = qtdVertices;
	for(int i=0;i<qtdVertices;i++){
		for(int j=0;j<qtdVertices;j++)
			g->matrizAdj[i][j] = 0;
	}
	printf("Grafo inicializado com sucesso!\n");
	return;
}

int insereAresta(tipo_grafo *G, int u, int v){
	if(G->matrizAdj[u][v] == 1)
		return -1;
	else{
		G->matrizAdj[u][v] = 1;
		G->qtdArestas++;
		printf("Aresta inserida com sucesso\n");
		return 1;
	}
}

int removeAresta(tipo_grafo *G, int u, int v){
	if(G->matrizAdj[u][v] == 0)
		return -1;
	else{
		G->qtdArestas--;
		G->matrizAdj[u][v] = 0;
		return 1;
	}
}





int existeCaminho(tipo_grafo G, int origem, int destino){

	if (origem == destino) return 1; // encontrado
	listaVisitados[origem] = 1;

	for (int vertice = 0; vertice < G.qtdVertices; vertice++)
		if (G.matrizAdj[origem][vertice] == 1)
			if (listaVisitados[vertice] == 0)
				if (existeCaminho(G, vertice, destino)) 
					return 1;
	return 0;
}



 void zeraVisitados(){
 	for (int i = 0; i < MAX; i++)
 	{
 		listaVisitados[i] =0;
 	}
 
 }



int dsf(tipo_grafo G, int v){
	listaVisitados[v] = contador++;

	for (int vertice = 0; vertice < G.qtdVertices; vertice++)
		if (G.matrizAdj[v][vertice] == 1)
			if (listaVisitados[vertice] == 0)
				if (dsf(G, vertice)) 
					return 1;
	return 0;
}
 

 void buscaProfundidade(tipo_grafo G, int origem){
 	zeraVisitados();
 	contador =0;
	 for (int i = 0; i < G.qtdVertices; i++){
	 	if(listaVisitados[origem] == 0)
	 		dsf(G,origem);
	 }
 }


void imprimeGrafo(tipo_grafo G){

	for(int i=0; i<G.qtdVertices;i++){
		printf("\n");
		for(int j=0; j<G.qtdVertices; j++)
			printf(" %d ", G.matrizAdj[i][j]);
	}
}

int main(){
	tipo_grafo G;
 

	inicializaGrafo(&G,10);	
	insereAresta(&G,1,2);
	insereAresta(&G,1,3);
	insereAresta(&G,1,5);
	insereAresta(&G,2,3);
	insereAresta(&G,3,4);
	insereAresta(&G,3,5);
	insereAresta(&G,6,5);
	insereAresta(&G,7,1);
	imprimeGrafo(G);
	

	if(existeCaminho(G,2,5))
		printf("Caminho encontrado\n");

	buscaProfundidade(G,1);

	for (int i = 0; i < MAX; ++i){
		printf("%d. \n",listaVisitados[i] );	
	}
	
	return 0;
}

