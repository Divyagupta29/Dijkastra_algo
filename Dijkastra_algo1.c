#include <stdio.h>
#define MAX 5
#define INFINITY 9999

void Dijkstra(int Graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX],distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    
    // Creating cost matrix
       for (i = 0; i < n; i++) {
           for (j = 0; j <n; j++) {
               if(Graph[i][j] == 0) {
                   cost[i][j] = INFINITY;
               } else {
                   cost[i][j] = Graph[i][j];
               }
           }
       }
    
    //Setup all nodes as non visisted nodes before start
    for (i = 0 ; i < n ; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }
    
    distance[start] = 0;  // Make startup point distance as 0 becuase its current position
    visited[start] = 1;
    count = 1;
    
    while (count < n - 1) {
        mindistance = INFINITY;
        
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        
        visited[nextnode] = 1;
        for (i = 0;  i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                } // if
            } // nested if
        } // for
        ++count;
    }//while
    
    
    // Printing the distance
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    }
}  // function body


int main(int argc, const char * argv[]) {
    int Graph[MAX][MAX],n = 5,u;
    Graph[0][0] = 0;
    Graph[0][1] = 1;
    Graph[0][2] = 1;
    Graph[0][3] = 6;
    Graph[0][4] = 0;
    
    Graph[1][0] = 1;
    Graph[1][1] = 0;
    Graph[1][2] = 2;
    Graph[1][3] = 0;
    Graph[1][4] = 0;
    
    Graph[2][0] = 1;
    Graph[2][1] = 2;
    Graph[2][2] = 0;
    Graph[2][3] = 1;
    Graph[2][4] = 3;
    
    Graph[3][0] = 6;
    Graph[3][1] = 0;
    Graph[3][2] = 1;
    Graph[3][3] = 0;
    Graph[3][4] = 2;
    
    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 3;
    Graph[4][3] = 2;
    Graph[4][4] = 0;
    
    u = 0;
    Dijkstra(Graph, n, u);
    
    
    return 0;
}
