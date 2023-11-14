#include <stdio.h>
#include <stdlib.h>
#include "djikstra.h"
#include <float.h>


/*
Pseudocódigo do Algoritmo de Dijkstra
Algoritmo Dijkstra(Grafo, Origem): 
    1. Crie um vector de valores booleanos chamado "Visitados" com tamanho igual ao número de nós. Inicialize os valores como falso e quando um nó for visitado, mude o valor para 1. 
    2. Crie uma fila de prioridade "NaoVisitados" com o nó origem e distância para a origem zero.  
    3. Crie um vector do tamanho do número de nós para armazenar o antecessor de cada no seu caminho mínimo (de onde ele veio) e o custo para o antecessor.  
    4. Enquanto houver vértices não visitados e a fila de prioridades não for vazia: 
    5. Escolha o nó não visitado U com a menor distância para a origem em "NaoVisitados" e o marque como visitado (adicione-o no conjunto "Visitados").  
    6. Para cada vizinho não visitado V de U: 
    7. Calcule a distância de V para a origem passando por U somando a distância de U para a origem e a distância entre U e V. 
    8. Adicione o par (V, distância) em "NaoVisitados". Se a distância do par  
    9. Retorne a estrutura com os caminhos mínimos.

Ele começa criando um array booleano chamado "Visitados," que possui um elemento para cada nó no grafo. Inicialmente, todos os valores são definidos como falso para indicar que nenhum nó foi visitado. Conforme o algoritmo progride, os nós visitados são marcados como verdadeiros no array.  Em seguida, é criada uma fila de prioridade chamada "NaoVisitados" que conterá os nós a serem explorados. A fila de prioridade é usada para a seleção eficiente do próximo nó a ser explorado. Um heap deverá ser utilizado para implementar a fila de prioridade. O heap organiza os nós não visitados de acordo com suas distâncias atuais em relação à origem, de modo que o nó com a menor distância esteja sempre no topo da estrutura. Isso permite ao algoritmo escolher o próximo nó a ser explorado de forma eficiente, sem ter que verificar todas as opções. As operações de inserção e extração do nó a ser visitado do heap não devem ter complexidade superior a O(log N).
Poderá deverá ser criada uma estrutura de dados para armazenar os antecessores de cada nó e os respectivos custos no melhor caminho da origem até o nó. Esta estrutura permite recuperar o melhor caminho partindo de todos iterando pelos antecessores, começando do nó e indo até a origem, sem a necessidade de armazenar cópias de trechos de caminhos. 
O loop principal do algoritmo consiste nos passos descritos a seguir. O nó de origem é adicionado ao heap (fila de prioridade) com uma distância para a origem de zero. Enquanto houver vértices não visitados no grafo e a fila de prioridades "NaoVisitados" não estiver vazia, o nó U com a menor distância à origem e que ainda não foi visitado é selecionado de "NaoVisitados." O nó U é, então, marcado como visitado e o menor caminho até ele é registrado. A seguir, o algoritmo itera sobre todos os vizinhos não visitados de U. Para cada vizinho V, o algoritmo calcula a distância de V à origem passando por U. Isso é feito somando a distância de U à origem com a distância entre U e V. O nó V é adicionado no heap usando a distância como prioridade. Note que um determinado nó pode ser inserido várias vezes no heap. Contudo, pela propriedade do heap, o caminho de menor custo para cada nó terá prioridade sobre os caminhos alternativos. O processo de visitar os nós com menor custo para a origem, marcá-los como visitados e calcular as distâncias para os vizinhos e adicionar os vizinhos no heap se repete até que todos os nós tenham sido visitados ou não haja mais nós em "NaoVisitados." Finalmente, o algoritmo retorna a estrutura de dados que contém os antecessores dos nós nos melhores caminhos e esta estrutura de dados é utilizada para exibir a saída na tela.

*/

int min_distance(float dist[], int sptSet[], int num_nodes) {
    float min = FLT_MAX; 
    int min_index;
    
    for (int v = 0; v < num_nodes; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void printSolution(float dist[], int parent[], int src, int num_nodes) {
    printf("Caminhos mais curtos a partir da origem %d:\n", src);
    for (int i = 0; i < num_nodes; i++) {
        if (i != src) {

            printPath(parent, i);
            printf(": %.2f\n", dist[i]);

        }
    }
}

void djikstra_solve(Problem *problem) {
    float dist[problem->num_nodes];
    int sptSet[problem->num_nodes];
    int parent[problem->num_nodes];

    for (int i = 0; i < problem->num_nodes; i++) {
        dist[i] = FLT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[0] = 0;

    for (int count = 0; count < problem->num_nodes - 1; count++) {
        int u = min_distance(dist, sptSet, problem->num_nodes);
        sptSet[u] = 1;

        for (int v = 0; v < problem->num_nodes; v++) {
            if (!sptSet[v] && graph_get(problem->graph, v, u) && dist[u] != FLT_MAX && dist[u] + graph_get(problem->graph, v, u) < dist[v]) {
                dist[v] = dist[u] + graph_get(problem->graph, v, u);
                parent[v] = u;
            }
        }
    }
    printSolution(dist, parent, 0, problem->num_nodes);
}



/*
            if (!sptSet[v] && graph_get(problem->graph, u, v) && dist[u] != FLT_MAX && dist[u] + graph_get(problem->graph, u, v) < dist[v]) {
                dist[v] = dist[u] + graph_get(problem->graph, u, v);
                parent[v] = u;
            }


*/