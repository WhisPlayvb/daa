#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;
int main()
{
    cout << "Enter The number of nodes of Graph-> ";
    int nodes;
    cin >> nodes;
    
    int graph[nodes][nodes];
    memset(graph, -1, sizeof(graph));
    for (int i = 0; i <= nodes; i++)
    {
        graph[i][i] = 0;
    }
    int i = 0;
    for (int i = 0; i < nodes; i++)
    {
        int j = 0;
        for (int j = 0; j < nodes; j++)
        {
            if (graph[i][j] == -1)
        {
            int data;
            cout << "\nEnter the Vertex length for " << i + 1 << " to "<<j+1<<"->";
            cin >>data;
            graph[i][j] = graph[j][i] = data;
        }
        }
    }
    cout << "\n\nGraph is shown below as";
    i = 0;

    for (int i = 0; i < nodes; i++)
    {
        int j = 0;
        for (int j = 0; j < nodes; j++)
        {
            cout << "\nVertex length of " << i << " to " << j << " is "<<graph[i][j]<<"";
        }
        cout << endl;
    }

    auto start_prims = high_resolution_clock::now();
    
    int selected[nodes];
    for (int i = 0; i < nodes; i++)
    {
        selected[i] = false;
    }
    int no_edge = 0;

    selected[0] = true;
    int x; 
    int y;

    cout << "Edge"<< " : ""Weight";
    cout << endl;
    while (no_edge < nodes - 1)
    {
        int min = INT_MAX;
        x = 0;
        y = 0;
        for (int i = 0; i < nodes; i++)
        {
            if (selected[i] == true)
            {
                for (int j = 0; j < nodes; j++)
                {
                
                    if (selected[j] == false && graph[i][j] != 0)
                    {
                    
                    if (min > graph[i][j])
                    {
                    min = graph[i][j];
                    x = i;
                    y = j;
                    
                    }
                 }
                }
             }
        }
        cout << x << " - " << y << " : " << graph[x][y] << endl;
        selected[y] = true;
        no_edge++;
    }
    auto stop_prims = high_resolution_clock::now();
    auto duration_prims = duration_cast<microseconds>(stop_prims -
    start_prims);
    cout << "\nTime taken by Prims Algorithm : " << duration_prims.count() <<
    "microseconds" << endl;
}
