#include <bits/stdc++.h>
using namespace std; 

int BFS(string start, vector<vector<int>> buttons, string endstate) {
        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;

        q.push(pair(start, 0));
        visited[start] = true;

        cout << "BFS desde el nodo " << start << ": ";

        while (!q.empty()) {
            pair<string, int> current = q.front();
            q.pop();

            cout << current.first << " ";

            for(vector<int> button : buttons) {
                string next = current.first;
                for(int pos : button) {
                    if(next[pos] == '.') {
                        next[pos] = '#';
                    } else {
                        next[pos] = '.';
                    }
                }
                if(endstate == next) {
                    cout << endl;
                    return current.second + 1;
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(pair(next, current.second + 1));
                }
            }
        }

        cout << endl;
    }

void star1() {
    string linea;
    ifstream archivo("input_10_B.txt");
    long res = 0;
    while(getline(archivo, linea)) {
        int i = 1;
        string endstate = "";
        while (linea[i] != ']')
        {
            endstate += linea[i];
            i++;
        }
        i += 2;
        vector<vector<int>> buttons;
        while (linea[i] != '{') {
            if(linea[i] == '(') {
                i++;
                vector<int> button;
                while(linea[i] != ')') {
                    if(linea[i] == ',') i++;
                    button.push_back(linea[i] - '0');
                    i++;
                }

                buttons.push_back(button);
            }
            i++;
        }

        res += BFS(string(endstate.size(), '.'), buttons, endstate);

    }

    cout << res;
}

double h(vector<int> state, vector<int> endstate, int largestButton) {
    double res = 0;
    for (int i = 0; i < state.size(); i++) {
        res += endstate[i] - state[i];
    }

    return res;
}

struct node {
    double f;
    string name;
    int g;
};

struct Compare {
    bool operator()(const node& a, const node& b) const {
        return a.f > b.f;   // > convierte en min-heap
    }
};

int BFS2(string start, vector<vector<int>> buttons, string endstate) {
    unordered_map<string, bool> visited;
    priority_queue<node, vector<node>, Compare> q;

    vector<int> ends;
    int prev = 0;
    for(int i = 0; i < endstate.size(); i++) {
        if(endstate[i] == ',') {
            ends.push_back(stoi(endstate.substr(prev, i - prev)));
            prev = i + 1;
        }
    }
    ends.push_back(stoi(endstate.substr(prev)));

    // ---- Largest Button ----
    int largestButton = -1;
    for(vector<int> b : buttons) {
        largestButton = max((int)b.size(), largestButton);
    }

    node n;
    n.f = h(vector<int>(ends.size(), 0), ends, largestButton);
    n.g = 0;
    n.name = start;
    q.push(n);
    visited[start] = true;

    while (!q.empty()) {
        node current = q.top();
        q.pop();

        for(vector<int> button : buttons) {
            string next = current.name;
            int prevpos = 0;
            vector<int> nextstate;
            for(int i = 0; i < next.size(); i++) {
                if(next[i] == ',') {
                    nextstate.push_back(stoi(next.substr(prevpos, i - prevpos)));
                    prevpos = i + 1;
                }
            }
            nextstate.push_back(stoi(next.substr(prevpos)));

            bool flag = true;
            for(int p : button) {
                nextstate[p]++;
                if(ends[p] < nextstate[p]) {
                    flag = false;
                }
            }

            next = "";
            for(int x : nextstate) {
                next += to_string(x) + ",";
            }

            next = next.substr(0, next.size() - 1);
            
            if(flag && endstate == next) {
                return current.g + 1;
            }

            if (!visited[next]) {
                visited[next] = true;
                node z;
                z.name = next;
                z.g = current.g + 1;
                z.f = current.g + 1 + h(nextstate, ends, largestButton);
                q.push(z);
            }
        }
    }

    cout << endl;
}

void star2() {
    string linea;
    ifstream archivo("input_10_A.txt");
    long res = 0;
    int l = 0;
    while(getline(archivo, linea)) {
        int i = 1;
        l++;
        cout << l << endl;
        string endstate = "";
        while (linea[i] != ']')
        {
            endstate += linea[i];
            i++;
        }
        i += 2;
        vector<vector<int>> buttons;
        while (linea[i] != '{') {
            if(linea[i] == '(') {
                i++;
                vector<int> button;
                while(linea[i] != ')') {
                    if(linea[i] == ',') i++;
                    button.push_back(linea[i] - '0');
                    i++;
                }

                buttons.push_back(button);
            }
            i++;
        }
        endstate = linea.substr(i + 1);
        endstate = endstate.substr(0, endstate.size() - 1);
        string inistate = "";
        for(int j = 0; j < endstate.size(); j++) {
            if(endstate[j] == ',') {
                inistate += "0,";
            }
        }
        inistate += "0";
        res += BFS2(inistate, buttons, endstate);

    }

    cout << res;
}

void star2() {
    string linea;
    ifstream archivo("input_10_A.txt");
    long res = 0;
    int l = 0;
    while(getline(archivo, linea)) {
        int i = 1;
        l++;
        cout << l << endl;
        string endstate = "";
        while (linea[i] != ']')
        {
            endstate += linea[i];
            i++;
        }
        i += 2;
        vector<vector<int>> buttons;
        while (linea[i] != '{') {
            if(linea[i] == '(') {
                i++;
                vector<int> button;
                while(linea[i] != ')') {
                    if(linea[i] == ',') i++;
                    button.push_back(linea[i] - '0');
                    i++;
                }

                buttons.push_back(button);
            }
            i++;
        }
        endstate = linea.substr(i + 1);
        endstate = endstate.substr(0, endstate.size() - 1);
        string inistate = "";
        for(int j = 0; j < endstate.size(); j++) {
            if(endstate[j] == ',') {
                inistate += "0,";
            }
        }
        inistate += "0";
        res += BFS2(inistate, buttons, endstate);

    }

    cout << res;
}

int main() {
    star2();
}