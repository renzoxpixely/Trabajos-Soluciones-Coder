#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


/*******************************************************************************
*                         GRAPH Abstract Data Type                             *
*******************************************************************************/

typedef struct {
    int v;
    int w;
    int peso;
} Edge;

typedef struct {
	struct node* vertice;
    int peso;   /*peso dos links que vai criar*/
} *link;

struct node{
    int v;
    link next;
} ;

typedef struct node Node;

struct graph {
    int V;
    int E;
    link *adj;
};

typedef struct graph *Graph;

struct uni{    /*unidade do vector info que contém as onformações sobre cada cidade (nó)*/
    short q;   /*flag para saber se está em Q ou não, q=1 está, q=0 não está */
    short a;  /*flag para saber se tem aeroporto ou não: -2 -> não pode ter, -1 -> pode mas não tem, 0 -> tem mas ainda está na fila Q, 1 -> tem definitivamente 2 -> tem mesmo de ter independentemente de estar na fila ou não*/
    int custoa; /*preço do aeroporto*/   
    int pai; /*pai do nó*/
};

typedef struct uni *Uni;

Uni info;   /*vector que irá conter as informações de cada nó*/


Edge newEDGE(int v, int w, int peso) {
    Edge e;
    e.v = v;
    e.w = w;
    e.peso = peso;
    return e;
}

link newLINK(int v, link next, int peso) {
    link x = malloc(sizeof(link));
    x -> peso = peso;
    x->vertice=malloc(sizeof(Node));
    x -> vertice -> v = v;
    x -> vertice -> next = next;
    return x;
}

/* Initialization of the graph.
Memory allocation and NULL initialization of V vertices.
Operation complexity: O(V) */


Graph GRAPHinit(int V) {
    int v;
    Graph G = malloc(sizeof(*G));
    G -> V = V;
    G -> E = 0;
    G -> adj = malloc(V*sizeof(link));
    for (v = 0; v < V; v++) { /* Complexity O(V) */
        G->adj[v] = malloc(sizeof(link));
        G->adj[v]->peso=INT_MAX;
        G->adj[v]->vertice = malloc(sizeof(Node));
        G->adj[v]->vertice->v=v;
        G->adj[v]->vertice->next= NULL;
        
        info[v].pai=-1;
        info[v].custoa=0;
        info[v].q=1;
        info[v].a=-2;

    }
    return G;
}

/* Insert an edge: O(1)*/
void GRAPHinsertE(Graph G, Edge e) {
    int v = (e.v), w = (e.w), peso =(e.peso);
    G -> adj[v]->vertice->next = newLINK(w, G -> adj[v]->vertice->next, peso);
    G -> adj[w]->vertice->next = newLINK(v, G -> adj[w]->vertice->next, peso);
    G -> E++;
}

/*******************************************************************************
*                         MinHeap Abstract Data Structures                           *
*******************************************************************************/
typedef struct {
    int v;
    int key;
} heapNode;


heapNode* Q; 
/*******************************************************************************
*                         MinHeap Functions                          *
*******************************************************************************/
static int numberOfElements;

/* This function initializes the priorityQueue for maxN elements,
with 0 elements */
void queueInit(int V) {

    Q = malloc((V+1)*sizeof(heapNode));
    int v;
    for (v = 1; v <= V; v++) {          /* Complexity O(V) */
        Q[v].v= v - 1;
        Q[v].key=INT_MAX;
    }
    
    numberOfElements = V;

}


/* It receives an index of the heap and pushes it up to it's final position */
void minheapifyUP(int index) {

    heapNode temp;

    while (index > 1 && Q[index/2].key> Q[index].key) {
        temp = Q[index];
        Q[index] = Q[index/2];
        Q[index/2] = temp;
        index = index/2;
    }
}


/*It receives an index of the heap and builds a min heap, assuming it's children
are already a min heap */
void minheapifyDOWN(int index) {

    int j;
    heapNode temp;

    while (2*index <= numberOfElements) {

        j = 2*index;

        if (j < numberOfElements && Q[j].key > Q[j+1].key)
            j++;

        if (Q[index].key <= Q[j].key)
            break;

        temp = Q[index];
        Q[index] = Q[j];
        Q[j] = temp;
        index = j;
    }
}

/* It returns a boolean to say if the heap is empty or not */
int emptyQ() {
    return numberOfElements==0;
}

/* This function returns and deremoves the first (minimum) element of the heap,
and rearanges it*/
heapNode extractMin() {

    if (info[Q[1].v].a==0){
        int i=2;
        while (i<=numberOfElements){
            if (Q[i].key==Q[1].key){
                if (info[Q[i].v].a!=0){
                    heapNode temp=Q[1];
                    Q[1]=Q[i];
                    Q[i]=temp;
                    break;
                }
            }
            if (Q[i+1].key==Q[1].key){
                if (info[Q[i].v].a!=0){
                    heapNode temp=Q[1];
                    Q[1]=Q[i];
                    Q[i]=temp;
                    break;
                }
            }
            i=i*2;
        }
    }

    heapNode min = Q[1];

    Q[1] = Q[numberOfElements];
    Q[numberOfElements] = min;

    numberOfElements--;
    minheapifyDOWN(1);

    return min;
}



/*******************************************************************************
*                   PRIM                                                       *
*******************************************************************************/
int ap;
int custo=0;
int aeroportos=0;
int estradas=0;
int* central;

int sem_pai (Graph G) {
	int u;
	int a=0;
	for (u=0; u<G->V; u++){
		if (info[u].pai == -1) 
			a=a+1;
	}
	return a;
}

void relaxAeroporto(Graph G,int a,int b,int peso){

	int i;

    for(i = 1; i <= numberOfElements; i++) {
        if(Q[i].v == b) {
			if (peso<Q[i].key){
				Q[i].key=peso;
				info[b].pai=a;
		        minheapifyUP(i);
				if (info[b].a==-1)
					info[b].a=0;
			}
		}
	}
}

void relaxEstrada(Graph G,int a,int b,int peso){    /*A diferença é que neste damos prioridade pondo o <= em vez de apenas <*/

	int i;

    for(i = 1; i <= numberOfElements; i++) {
        if(Q[i].v == b) {
        	if (peso<=Q[i].key){
				Q[i].key=peso;
				info[b].pai=a;
		        minheapifyUP(i);
				if (info[b].a==0)
					info[b].a=-1;
			}
		}
	}
}


void reavaluate (Graph G, int u){

    int* ponteiro;
    int ar;
    link t=G->adj[u];
    ponteiro=central;
    for(ar = ap ;ar>0;ar--){
        link f=G->adj[(*ponteiro)];
        if (f->vertice->v!=t->vertice->v && info[(*ponteiro)].q==1){
            if (info[(*ponteiro)].a==2){                
                relaxAeroporto(G, u,*ponteiro,0);
            }
            else{  /*podem estar na lista nos não visitados com a=0 ou a=-1*/
                relaxAeroporto(G, u,*ponteiro,info[(*ponteiro)].custoa);
            }
        }
        ponteiro++;
    }
}

void prim (Graph G, int raiz)
{
	int aero;
	int* pi;
	Q[raiz+1].key=0;
    minheapifyUP(G->V);

    while (!emptyQ()){
    	custo=custo+Q[1].key;
    	int u=(extractMin().v);    /*u = indice v do nó que sai*/
        link t=G->adj[u];
    	info[u].q=0;
    	
    	if (u!=raiz && info[u].a!=0){
    		estradas=estradas+1;
    	}
    	if (info[u].a==0){
    		info[u].a=1;
    		aeroportos=aeroportos+1;
    		if (info[info[u].pai].a==-1){
				info[info[u].pai].a=1;
				aeroportos=aeroportos+1;
                reavaluate(G, info[u].pai);
	        }
    	}
        
    	if (info[u].a==2){    /*os futuros nós c a=1 não terão melhores ofertas a fazer*/
    		pi=central;
    		for(aero = ap ;aero>0;aero--){
				link f=G->adj[(*pi)];
                if (f->vertice->v!=t->vertice->v && info[(*pi)].q==1){
					if (info[(*pi)].a==2){                
						relaxAeroporto(G, u,*pi,0);
						
					}
					else{  /*podem estar na lista nos não visitados com a=0 ou a=-1*/
						relaxAeroporto(G, u,*pi,info[(*pi)].custoa);
					}
				}
				pi++;
			}
		}
		if (info[u].a!=2){
			if (info[u].a!=-2){
				pi=central;
				for(aero = ap ;aero>0;aero--){
					link f=G->adj[(*pi)];
	                if (f->vertice->v!=t->vertice->v && info[(*pi)].q==1){
						if (info[u].a==-1 && info[(*pi)].a==-1){                
							relaxAeroporto(G, u,*pi,info[u].custoa+info[(*pi)].custoa);
						}
						if (info[u].a==1 && info[(*pi)].a==-1){
							relaxAeroporto(G, u,*pi,info[(*pi)].custoa);
						}
						if (info[u].a==-1 && info[(*pi)].a==1){
							relaxAeroporto(G, u,*pi,info[u].custoa);
						}
					}
					pi++;
				}
			}
			link h=G->adj[u]->vertice->next;
			for (; h!= NULL ; h=h->vertice->next){
            	if (info[h->vertice->v].q==1){
                    relaxEstrada(G, u, h->vertice->v, h->peso);
                }
        	}
        }
    } 
}


/*******************************************************************************
*                                Main function                                 *
*******************************************************************************/
int main() {

     
    int v, e, u, peso, c;

    /* First we read from stdin the number of vertices to initialize the
    graf */
    scanf("%d", &v);
    info=malloc(v*sizeof(struct uni));
    Graph obras = GRAPHinit(v);
    queueInit(v);
    
    /* Associamos a cada cidade um potencial aeroporto a construir*/
    scanf ("%d", &ap);
    central=malloc(ap*sizeof(int));
    int* pi=central;
    int aero=ap;
    for ( ;aero>0;aero--){
    	scanf("%d %d", &u, &c);  	
    	*pi=(u-1);                              /*coincide com indice v*/                                              
    	info[u-1].custoa=c;
    	info[u-1].a=2;
    	custo=custo+c;
    	aeroportos=aeroportos+1;
    	pi++;
    }

    /* We proceed to read all the connections from the input */
    scanf ("%d", &e);
    for (; e>0; e--) {
        scanf("%d %d %d", &u, &v, &peso);
        Edge edge = newEDGE(u-1, v-1, peso);
        GRAPHinsertE(obras, edge);
        if (info[u-1].a==2){    /*se uma cidade que tem aeroporto tiver estrada também então o aeroporto deixa de ser obrigatório*/
        	info[u-1].a=-1;
       		custo=custo-info[u-1].custoa;
       		aeroportos=aeroportos-1;                   /*contabilizamos apenas aerop. obrigatorios*/ 
        }
       	if (info[v-1].a==2){    
        	info[v-1].a=-1;
       		custo=custo-info[v-1].custoa;
       		aeroportos=aeroportos-1;
       	}                   
    }
    /* The graph order funtion analyses the minimum cost pathway*/
    
    int raiz=0;
    int valor;
    for (valor=0 ; valor<obras->V ; valor++){
    	if (info[valor].a==2){
    		raiz=valor;
    		break;
    	}
    }

    prim(obras, raiz);


    if (sem_pai(obras)>1)
    	printf("Insuficiente\n");
    else 
    	printf("%d\n%d %d\n", custo, aeroportos, estradas);

    free(Q);
    free(obras);

    return 0;
}
