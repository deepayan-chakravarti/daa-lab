#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

const long long INF = 999999999999LL;

struct Edge {
    int to;
    long long weight;
};

struct CompareDist {
    bool operator()(pair<long long, int> const& a, pair<long long, int> const& b) {
        return a.first > b.first;
    }
};

unsigned long int next_rand = 1;
int my_rand() {
    next_rand = next_rand * 1103515245 + 12345;
    return (unsigned int)(next_rand / 65536) % 32768;
}

void dijkstra(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, CompareDist> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d != dist[u]) continue;
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            long long w = graph[u][i].weight;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n = 5000;
    int extra[] = {0, 5000, 15000};
    
    cout << "DIJKSTRA'S ALGORITHM (n=" << n << ")\n";
    
    for (int i = 0; i < 3; i++) {
        vector<vector<Edge>> graph(n);
        
        for (int v = 1; v < n; v++) {
            int w = (my_rand() % 100) + 1;
            graph[v - 1].push_back({v, w});
            graph[v].push_back({v - 1, w});
        }
        
        int currentExtra = extra[i];
        while (currentExtra > 0) {
            int u = my_rand() % n;
            int v = my_rand() % n;
            if (u != v) {
                int w = (my_rand() % 100) + 1;
                graph[u].push_back({v, w});
                graph[v].push_back({u, w});
                currentExtra--;
            }
        }
        
        if (i == 0) cout << "\nSparse graph:\n";
        else if (i == 1) cout << "\nMedium-density graph:\n";
        else cout << "\nDenser graph:\n";
        
        auto start = high_resolution_clock::now();
        dijkstra(graph, 0);
        auto stop = high_resolution_clock::now();
        
        double ms = duration<double, milli>(stop - start).count();
        cout << "Execution time: " << ms << " ms\n";
    }
    
    return 0;
}