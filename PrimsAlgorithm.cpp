#include <cstring>
#include <iostream>
using namespace std;

// Declaring a global variable
const int V = 8;

// Function to implement Prim's Algorithm
template<class NodeType>
void primsAlgorithm(int graph[V][V], NodeType nodes[V]) {
    int inMST[V];
    int edges = 0; 
    memset(inMST, false, sizeof(inMST));  // Initializing all thevertices inMST to false
    inMST[0] = true;  // Starting point of the vertex
    int x, y, totalCost = 0;
    cout << "Edges: Weight" << endl;

    // The number of edges (E) in MST, E = (V - 1), V = vertices
    while (edges < V - 1) {
        int min = INT_MAX;
        x = 0;
        y = 0;

        // Find the edge with the minimum weight
        for (int i = 0; i < V; i++) {
            if (inMST[i]) {
                for (int j = 0; j < V; j++) {
                    if (!inMST[j] && graph[i][j]) {  // If j is not selected and there is an edge
                        if (min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
		
        // Print the edges and weight
        cout << nodes[x] << nodes[y] << "   : " << graph[x][y] << endl;
        totalCost += graph[x][y];
        inMST[y] = true;  // Set a flag to mark as selected
        edges++; 
    }
    cout << "Total: " << totalCost << endl;
}

int main() {
	
	// Vertices can be tested for other data types
	char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	int graph[V][V] = {
  // A  B  C  D  E  F  G  H
  // 0  1  2  3  4  5  6  7
    {0, 1, 6, 2, 0, 0, 0, 0},  // 0 A
    {1, 0, 0, 9, 4, 6, 0, 0},  // 1 B
    {6, 0, 0, 2, 0, 0, 0, 0},  // 2 C
    {2, 9, 2, 0, 5, 0, 7, 0},  // 3 D
    {0, 4, 0, 5, 0, 5, 3, 0},  // 4 E
    {0, 6, 0, 0, 5, 0, 6, 2},  // 5 F
    {0, 0, 0, 7, 3, 6, 0, 0},  // 6 G
    {0, 0, 0, 0, 0, 2, 0, 0}   // 7 H
};
    primsAlgorithm(graph, vertices);
    return 0;
}
