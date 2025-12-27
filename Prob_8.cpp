#include <bits/stdc++.h>
using namespace std;

// ---------- Disjoint Set (Union-Find) ----------
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB)
            return false;

        if (rank[rootA] < rank[rootB])
            parent[rootA] = rootB;
        else if (rank[rootA] > rank[rootB])
            parent[rootB] = rootA;
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }


};

// ---------- Edge Structure ----------
struct Edge {
    int u, v;
    double weight;
};

void star2() {
    string s;
    vector<pair<int,pair<int,int>>> nodes;
    while(cin >> s) {
        int x, y, z;
        int c = 0, prevpos = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ',' && c == 0) {
                x = stoi(s.substr(0,i));
                prevpos = i + 1;
                c++;
            } else if (s[i] == ',' && c == 1) {
                y = stoi(s.substr(prevpos, i - prevpos));
                z = stoi(s.substr(i + 1));
                break;
            }
        }

        nodes.push_back(pair(x, pair(y, z)));
    }

    int V = nodes.size();

    vector<Edge> edges;
    for(int i = 0; i < nodes.size(); i++) {
        for(int j = i + 1; j < nodes.size(); j++) {
            if(j != i) {
                Edge e;
                e.u = i;
                e.v = j;
                double dx = nodes[i].first - nodes[j].first;
                double dy = nodes[i].second.first - nodes[j].second.first;
                double dz = nodes[i].second.second - nodes[j].second.second;

                e.weight = sqrt(dx*dx + dy*dy + dz*dz);
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });
    
    DSU dsu(V);
    int edgesUsed = 0;
    bool flag = true;
    
    int x1, x2;
    for (const auto& e : edges) {
        int root = dsu.find(0);
        bool flag = true;
        for(int i = 1; i < V && flag; i++) {
            if(root != dsu.find(i)) {
                flag = false;
            }
        }

        if(flag) {
            break;
        }

        cout << " Root = " << dsu.find(e.u) << " / " << dsu.find(e.v) << " ------- ";
        if(dsu.unite(e.u, e.v)) {
            cout << "Unidos: (" << nodes[e.u].first << "," << nodes[e.u].second.first << "," << nodes[e.u].second.second
            << ") <-> (" << nodes[e.v].first << "," << nodes[e.v].second.first << "," << nodes[e.v].second.second
            << ") W = " << e.weight << " Root = " << dsu.find(e.u) << " / " << dsu.find(e.v) << endl;
            x1 = nodes[e.u].first;
            x2 = nodes[e.v].first;
        } else {
            cout << "No Unidos: (" << nodes[e.u].first << "," << nodes[e.u].second.first << "," << nodes[e.u].second.second
            << ") <-> (" << nodes[e.v].first << "," << nodes[e.v].second.first << "," << nodes[e.v].second.second
            << ") W = " << e.weight << " Root = " << dsu.find(e.u) << " / " << dsu.find(e.v) << endl;
        }
        
        edgesUsed++;
    }

    cout << "RES: " << x1 * x2;
}

void star1() {
    string s;
    vector<pair<int,pair<int,int>>> nodes;
    while(cin >> s) {
        int x, y, z;
        int c = 0, prevpos = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ',' && c == 0) {
                x = stoi(s.substr(0,i));
                prevpos = i + 1;
                c++;
            } else if (s[i] == ',' && c == 1) {
                y = stoi(s.substr(prevpos, i - prevpos));
                z = stoi(s.substr(i + 1));
                break;
            }
        }

        nodes.push_back(pair(x, pair(y, z)));
    }

    int V = nodes.size();

    vector<Edge> edges;
    for(int i = 0; i < nodes.size(); i++) {
        for(int j = i + 1; j < nodes.size(); j++) {
            if(j != i) {
                Edge e;
                e.u = i;
                e.v = j;
                double dx = nodes[i].first - nodes[j].first;
                double dy = nodes[i].second.first - nodes[j].second.first;
                double dz = nodes[i].second.second - nodes[j].second.second;

                e.weight = sqrt(dx*dx + dy*dy + dz*dz);
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });
    
    DSU dsu(V);
    int edgesUsed = 0;
    bool flag = true;
    
    for (const auto& e : edges) {
        if(edgesUsed == 1000) {
            break;
        }

        if(dsu.unite(e.u, e.v)) {
            cout << "Unidos: (" << nodes[e.u].first << "," << nodes[e.u].second.first << "," << nodes[e.u].second.second
            << ") <-> (" << nodes[e.v].first << "," << nodes[e.v].second.first << "," << nodes[e.v].second.second
            << ") W = " << e.weight << " Root = " << dsu.find(e.u) << " / " << dsu.find(e.v) << endl;
        } else {
            cout << "No Unidos: (" << nodes[e.u].first << "," << nodes[e.u].second.first << "," << nodes[e.u].second.second
            << ") <-> (" << nodes[e.v].first << "," << nodes[e.v].second.first << "," << nodes[e.v].second.second
            << ") W = " << e.weight << " Root = " << dsu.find(e.u) << " / " << dsu.find(e.v) << endl;
        }
        
        edgesUsed++;
    }

    vector<int> componentSize(V, 0);

    for (int i = 0; i < V; i++) {
        int root = dsu.find(i);
        componentSize[root]++;
    }

    sort(componentSize.begin(), componentSize.end(), greater<int>());

    cout << componentSize[0] << endl << componentSize[1] << endl << componentSize[2] << endl;

    cout << "RES: " << componentSize[0] * componentSize[1] * componentSize[2];
}

int main() {
    star2();
}
