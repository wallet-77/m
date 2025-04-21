#include <stdio.h>
#define INFINITY 999

int primAlgorithm(int costMatrix[10][10], int numVertices, int startVertex) {
    int visited[10], i, j, totalCost = 0;
    int parentVertex[10], minDistance[10], minValue, currentVertex;

  
    for (i = 1; i <= numVertices; i++) {
        minDistance[i] = costMatrix[startVertex][i];
        parentVertex[i] = startVertex;
        visited[i] = 0;
    }
    visited[startVertex] = 1;

    for (i = 1; i < numVertices; i++) {
        minValue = INFINITY;
        currentVertex = -1;

      
        for (j = 1; j <= numVertices; j++) {
            if (!visited[j] && minDistance[j] < minValue) {
                minValue = minDistance[j];
                currentVertex = j;
            }
        }

        if (currentVertex == -1) break;

        visited[currentVertex] = 1;
        totalCost += minDistance[currentVertex];
        printf("\n%d -> %d totalCost=%d", parentVertex[currentVertex], currentVertex, totalCost);

        
        for (j = 1; j <= numVertices; j++) {
            if (!visited[j] && costMatrix[currentVertex][j] < minDistance[j]) {
                minDistance[j] = costMatrix[currentVertex][j];
                parentVertex[j] = currentVertex;
            }
        }
    }

    return totalCost;
}

void main() {
    int costMatrix[10][10], i, j, minimumCost, startVertex, numVertices;

    printf("\nEnter number of vertices: ");
    scanf("%d", &numVertices);

    printf("\nEnter the graph data:\n");
    for (i = 1; i <= numVertices; i++) {
        for (j = 1; j <= numVertices; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", &startVertex);

    minimumCost = primAlgorithm(costMatrix, numVertices, startVertex);
    printf("\nMinimum Spanning Tree Cost=%d\n", minimumCost);
}