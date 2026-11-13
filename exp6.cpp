#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int INF = 999999999;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, Edge edges[], int source) {
    int dist[1000];
    
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Negative-weight cycle detected.\n";
            return;
        }
    }

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];
        cout << '\n';
    }
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int V, E, source;
    
    cout << "Enter number of vertices: ";
    cin >> V;
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    if (V <= 0 || E < 0) {
        cout << "Invalid number of vertices or edges.\n";
        return 0;
    }
    
    Edge* edges = new Edge[E];
    
    cout << "Enter source, destination and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        
        if (edges[i].src < 0 || edges[i].src >= V || 
            edges[i].dest < 0 || edges[i].dest >= V) {
            cout << "Invalid vertex number.\n";
            return 0;
        }
    }
    
    cout << "Enter source vertex: ";
    cin >> source;
    
    if (source < 0 || source >= V) {
        cout << "Invalid source vertex.\n";
        return 0;
    }
    
    auto start = high_resolution_clock::now();
    
    bellmanFord(V, E, edges, source);
    
    auto stop = high_resolution_clock::now();
    double ms = duration<double, milli>(stop - start).count();
    
    cout << "\nExecution time: " << ms << " ms\n";
    
    delete[] edges;
    return 0;
}