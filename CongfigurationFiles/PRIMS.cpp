#include <iostream>
#include <cstring> // for memset
#include <climits> // for INT_MAX
#include <ctime> // for time
using namespace std;

int main() {
    int nodes;
    cout << "Enter the number of nodes of the Graph: ";
    cin >> nodes;
    int graph[nodes][nodes];
    memset(graph, -1, sizeof(graph)); // Initialize graph with -1
    
    // Input graph edges
    for (int i = 0; i < nodes; ++i) {
        for (int j = i; j < nodes; ++j) {
            if (i == j) {
                graph[i][j] = 0; // Diagonal elements are set to 0
            } else if (graph[i][j] == -1) {
                int data;
                cout << "Enter the weight of the edge between nodes " << i + 1 << " and " << j + 1 << ": ";
                cin >> data;
                graph[i][j] = graph[j][i] = data; // Assign weight to both symmetric edges
            }
        }
    }
    
    // Display input graph (adjacency matrix)
    cout << "\nGraph adjacency matrix:\n";
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    int startVertex;
    cout << "\nEnter the starting vertex for Prim's Algorithm (1-" << nodes << "): ";
    cin >> startVertex;
    if (startVertex < 1 || startVertex > nodes) {
        cout << "Invalid starting vertex. Please enter a vertex within the range 1-" << nodes << endl;
        return 1;
    }
    --startVertex; // Adjust to zero-based index
    
    // Using time function for timing
    clock_t startPrims = clock();
    
    // Array to store whether a vertex is selected in MST
    bool selected[nodes] = {false};
    selected[startVertex] = true; // Start from the chosen vertex
    int no_edge = 0; // Count of edges included in MST
    int totalCost = 0; // Total cost of the MST
    
    cout << "\nEdges of MST and their weights:\n";
    cout << "Edge : Weight\n";
    
    while (no_edge < nodes - 1) {
        int min = INT_MAX;
        int x = 0, y = 0; // Vertices of the edge with minimum weight
        
        // Find the minimum weight edge
        for (int i = 0; i < nodes; ++i) {
            if (selected[i]) {
                for (int j = 0; j < nodes; ++j) {
                    if (!selected[j] && graph[i][j] != 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout << x + 1 << " - " << y + 1 << " : " << graph[x][y] << endl;
        totalCost += graph[x][y]; // Add edge weight to total cost
        selected[y] = true;
        ++no_edge;
    }
    
    // Using time function for timing
    clock_t stopPrims = clock();
    double durationPrims = (double)(stopPrims - startPrims) / CLOCKS_PER_SEC * 1000000; // in microseconds
    
    cout << "\nTotal cost of MST: " << totalCost << endl;
    cout << "Time taken by Prim's Algorithm: " << durationPrims << " microseconds" << endl;
    
    return 0;
}

/*
Enter the number of nodes of the Graph: 4
Enter the weight of the edge between nodes 1 and 2: 4
Enter the weight of the edge between nodes 1 and 3: 5
Enter the weight of the edge between nodes 1 and 4: 2
Enter the weight of the edge between nodes 2 and 3: 0
Enter the weight of the edge between nodes 2 and 4: 3
Enter the weight of the edge between nodes 3 and 4: 7

Graph adjacency matrix:
0 4 5 2
4 0 0 3
5 0 0 7
2 3 7 0

Enter the starting vertex for Prim's Algorithm (1-4): 1

Edges of MST and their weights:
Edge : Weight
1 - 4 : 2
4 - 2 : 3
1 - 3 : 5

Total cost of MST: 10

Time taken by Prim's Algorithm: 3000 microseconds

The time complexity of Prim’s algorithm is O(V2) using an adjacency matrix and 
O((V +E) log V) using an adjacency list, where V is the number of vertices and E is the number of edges in the graph. 
*/
