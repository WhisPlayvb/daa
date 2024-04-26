#include <iostream>
#include <algorithm>
//#include <chrono>
using namespace std;

class prims
{
public:
    static const int V = 5;
    int min_Key(int[], bool[]);
    void print_MST(int[], int cost[V][V]);
    void find_MST(int cost[V][V]);
};


int prims::min_Key(int key[], bool visited[])
{
    int min = 999;
    int min_index;
    
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void prims::print_MST(int parent[], int cost[V][V])
{
    int min_cost = 0;
    cout << "Edges \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << "\t" << cost[i][parent[i]] << endl;
        min_cost += cost[i][parent[i]];
    }
    cout << "Total cost of MST : " << min_cost << endl;
}

void prims::find_MST(int cost[V][V])
{
    int parent[V], key[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int x = 0; x < V; x++)
    {
        int u = min_Key(key, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (cost[u][v] != 0 && !visited[v] && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    print_MST(parent, cost);
}

int main()
{
    prims p;

    int cost[p.V][p.V];
    cout << "Enter the incidence matrix for graph with 5 vertices : " << endl;
    for (int i = 0; i < p.V; i++)
    {
        for (int j = 0; j < p.V; j++)
        {
            cin >> cost[i][j];
        }
    }

//    auto start = chrono::steady_clock::now();
//    auto end = chrono::steady_clock::now();
    p.find_MST(cost);
//    cout << "\nElapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count()<<"ms"<< endl;
    cout << endl;

    return 0;
}
