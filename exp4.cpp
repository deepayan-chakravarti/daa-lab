#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Edge {
    int u, v, w;
};

void sortEdges(Edge arr[], int low, int high) {
    if (low < high) {
        Edge pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].w < pivot.w) {
                i++;
                Edge temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        Edge temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        int pi = i + 1;
        sortEdges(arr, low, pi - 1);
        sortEdges(arr, pi + 1, high);
    }
}

struct DSU {
    int p[5000];
    int r[5000];
    
    void init(int n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
            r[i] = 0;
        }
    }
    
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        
        if (r[a] < r[b]) {
            int temp = a; 
            a = b; 
            b = temp;
        }
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

unsigned long int next_rand = 1;
int my_rand() {
    next_rand = next_rand * 1103515245 + 12345;
    return (unsigned int)(next_rand / 65536) % 32768;
}

long long kruskal(int n, Edge edges[], int numEdges) {
    sortEdges(edges, 0, numEdges - 1);
    DSU dsu;
    dsu.init(n);
    
    int count = 0;
    long long total = 0;
    
    for (int i = 0; i < numEdges; i++) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            total += edges[i].w;
            count++;
            if (count == n - 1) break;
        }
    }
    
    if (count == n - 1) return total;
    return -1;
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n = 5000;
    int extra[] = {0, 5000, 15000};
    double times[3];
    
    cout << "KRUSKAL'S ALGORITHM (V=" << n << ")\n";
    cout << "Theoretical complexity: O(E log E)\n\n";
    
    for (int i = 0; i < 3; i++) {
        int numEdges = (n - 1) + extra[i];
        Edge* edges = new Edge[numEdges];
        int edgeCount = 0;
        
        for (int j = 1; j < n; j++) {
            edges[edgeCount].u = j - 1;
            edges[edgeCount].v = j;
            edges[edgeCount].w = (my_rand() % 1000) + 1;
            edgeCount++;
        }
        
        int currentExtra = extra[i];
        while (currentExtra > 0) {
            int u = my_rand() % n;
            int v = my_rand() % n;
            if (u != v) {
                edges[edgeCount].u = u;
                edges[edgeCount].v = v;
                edges[edgeCount].w = (my_rand() % 1000) + 1;
                edgeCount++;
                currentExtra--;
            }
        }
        
        if (i == 0) cout << "Sparse graph\n";
        else if (i == 1) cout << "Medium-density graph\n";
        else cout << "Dense graph\n";
        
        auto start = high_resolution_clock::now();
        long long mstWeight = kruskal(n, edges, numEdges);
        auto stop = high_resolution_clock::now();
        
        times[i] = duration<double, milli>(stop - start).count();
        
        cout << "Vertices: " << n << "\n";
        cout << "Edges: " << numEdges << "\n";
        cout << "MST total weight: " << mstWeight << "\n";
        cout << "Execution time: " << times[i] << " ms\n\n";
        
        delete[] edges;
    }
    
    cout << "TIME COMPARISON\n";
    cout << "Sparse: " << times[0] << " ms\n";
    cout << "Medium: " << times[1] << " ms\n";
    cout << "Dense: " << times[2] << " ms\n";
    
    return 0;
}