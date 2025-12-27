#include <bits/stdc++.h>
using namespace std; 

class Graph {
    private:
        // Lista de adyacencia: nodo → (vecino, peso)
        unordered_map<string, vector<pair<string, int>>> adj;

    public:
        // ==============================
        // CREACIÓN DE NODOS Y ARISTAS
        // ==============================

        void addNode(string node) {
            if (adj.find(node) == adj.end()) {
                adj[node] = vector<pair<string, int>>();
            }
        }

        void addEdge(string from, string to, int weight = 1, bool bidirectional = true) {
            adj[from].push_back({to, weight});
            if (bidirectional) {
                adj[to].push_back({from, weight});
            }
        }

        // ==============================
        // DFS - BÚSQUEDA EN PROFUNDIDAD
        // ==============================
        int DFSUtil(string node, unordered_map<string, bool>& visited, unordered_map<string, int>& arrived) {
            cout << node << " ";
            if(node == "out") return 1;
            int res = 0;
            if(!visited[node]) {
                arrived[node] = 0;
            }
            visited[node] = true;
            for (auto &neighbor : adj[node]) {
                string next = neighbor.first;
                if (!visited[next]) {
                    res += DFSUtil(next, visited, arrived);
                    if(next == "out") {
                        arrived[node] += 1;
                    } else {
                        arrived[node] += arrived[next];
                    }
                } else {
                    res += arrived[next];
                    arrived[node] += arrived[next];
                }
            }

            return res;
        }

        void DFS(string start) {
            unordered_map<string, bool> visited;
            unordered_map<string, int> arrived;

            cout << "DFS desde el nodo " << start << ": ";
            int res =  DFSUtil(start, visited, arrived);
            cout << endl;
            cout << "Caminos = " << res;
        }

        vector<vector<string>> DFSUtil2(string node, unordered_map<string, bool>& visited, unordered_map<string, vector<vector<string>>>& route) {
            if(node == "out") return vector<vector<string>>(1, vector<string>(1, "out"));
            vector<vector<string>> res;
            if(!visited[node]) {
                route[node] = vector<vector<string>>();
            }
            visited[node] = true;
            for (auto &neighbor : adj[node]) {
                string next = neighbor.first;
                if (!visited[next]) {
                    vector<vector<string>> aux = DFSUtil2(next, visited, route);
                    for(vector<string> r : aux) {
                        res.push_back(r);
                    }

                    if(next == "out") {
                        route[node].push_back(vector<string>(1,"out"));
                    } else {
                        for(vector<string> r : route[next]) {
                            r.push_back(next);
                            route[node].push_back(r);
                        }
                    
                    }
                } else {
                    for(vector<string> r : route[next]) {
                        r.push_back(next);
                        res.push_back(r);
                        route[node].push_back(r);
                    }
                }
            }

            return route[node];
        }

        void DFS2(string start) {
            unordered_map<string, bool> visited;
            unordered_map<string, vector<vector<string>>> route;

            cout << "DFS desde el nodo " << start << ": ";
            vector<vector<string>> res =  DFSUtil2(start, visited, route);
            int caminos = 0;
            for(vector<string> r : res) {
                bool fft = false, dac = false;
                for(string n : r) {
                    cout << n << " -> ";
                    if(n == "fft") {fft = true;}
                    if(n == "dac") {dac = true;}
                }

                if(fft && dac) {
                    caminos++;
                }
                cout << endl;
            }
            cout << endl;
            cout << "Caminos = " << caminos;
        }

        vector<vector<string>> DFSUtil3(string node, unordered_map<string, vector<vector<string>>>& route, unordered_map<string, bool>& visited)
        {
            if (node == "out") {
                route[node] = {{ "out" }};
                return route[node];
            }

            vector<vector<string>> res;
            if(!visited[node]) {
                route[node] = res;
            }
            visited[node] = true;

            for (auto& nei : adj[node]) {
                string next = nei.first;

                if(!visited[node]) {
                    vector<vector<string>> subpaths = DFSUtil3(next, route, visited);

                    for (auto path : subpaths) {
                        path.insert(path.begin(), node);
                        res.push_back(path);
                    }
                } else {
                    for (auto path : route[next]) {
                        path.insert(path.begin(), node);
                        res.push_back(path);
                    }
                }
            }

            route[node] = res;
            return res;
        }

        void DFS3(string start) {
        unordered_map<string, vector<vector<string>>> route;
        unordered_map<string, bool> visited;

        vector<vector<string>> res = DFSUtil3(start, route, visited);

        int caminos = 0;
        for (auto& r : res) {
            bool fft = false, dac = false;

            for (auto& n : r) {
                cout << n << " -> ";
                if (n == "fft") fft = true;
                if (n == "dac") dac = true;
            }

            if (fft && dac) caminos++;

            cout << endl;
        }

        cout << "\nCaminos = " << caminos << endl;
    }

};

void star1() {
    string linea;
    ifstream archivo("input_11_B.txt");

    Graph g;
    while(getline(archivo, linea)) {
        string from = linea.substr(0, 3);
        g.addNode(from);
        int prev = 5;
        for(int i = 5; i < linea.size(); i++) {
            if(linea[i] == ' ') {
                string to = linea.substr(prev, i - prev);
                g.addEdge(from, to, 1, false);
                prev = i + 1;
            }
        }
        string to = linea.substr(prev);
        g.addEdge(from, to, 1, false);

    }


    g.DFS("you");
}

void star2() {
    string linea;
    ifstream archivo("input_11_B.txt");

    Graph g;
    while(getline(archivo, linea)) {
        string from = linea.substr(0, 3);
        g.addNode(from);
        int prev = 5;
        for(int i = 5; i < linea.size(); i++) {
            if(linea[i] == ' ') {
                string to = linea.substr(prev, i - prev);
                g.addEdge(from, to, 1, false);
                prev = i + 1;
            }
        }
        string to = linea.substr(prev);
        g.addEdge(from, to, 1, false);

    }


    g.DFS2("svr");
}

int main() {
    star2();
}