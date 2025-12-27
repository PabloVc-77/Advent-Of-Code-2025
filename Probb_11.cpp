// C++ Code to count paths from source 
// to destinattion using Topological Sort
#include <bits/stdc++.h>
using namespace std;

long long countPaths(int n, vector<vector<int>> &edgeList,
               int source, int destination) {

    // Create adjacency list (1-based indexing)
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);

    for (auto &edge : edgeList) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        indegree[v]++;
    }

    // Perform topological sort using Kahn's algorithm
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Array to store number of ways to reach each node
    vector<long long> ways(n + 1, 0);
    ways[source] = 1;

    // Traverse in topological order
    for (int node : topoOrder) {
        for (int neighbor : graph[node]) {
            ways[neighbor] += ways[node];
        }
    }

    return ways[destination];
}

unordered_map<string, int> nodos;
int nextID = 1;

int getID(const string& s) {
    if (!nodos.count(s)) {
        nodos[s] = nextID++;
    }
    return nodos[s];
}

int main() {
    string linea;
    ifstream archivo("input_11_B.txt");

    // Edge list: [u, v] represents u -> v
    vector<vector<int>> edgeList;

    while(getline(archivo, linea)) {
        string from = linea.substr(0, 3);
        int f = getID(from);
        int prev = 5;
        for(int i = 5; i < linea.size(); i++) {
            if(linea[i] == ' ') {
                string to = linea.substr(prev, i - prev);
                int t = getID(to);
                edgeList.push_back({f, t});
                prev = i + 1;
            }
        }
        string to = linea.substr(prev);
        int t = getID(to);
        edgeList.push_back({f, t});

    }
    int n = nodos.size();
    int svr = getID("svr");
    int out = getID("out");
    int fft = getID("fft");
    int dac = getID("dac");

    long long res = countPaths(n, edgeList, svr, fft) * countPaths(n, edgeList, fft, dac) * countPaths(n,edgeList, dac, out);
    res += countPaths(n, edgeList, svr, dac) * countPaths(n, edgeList, dac, fft) * countPaths(n,edgeList, fft, out);
    cout << "RES = " << res;
    return 0;
}