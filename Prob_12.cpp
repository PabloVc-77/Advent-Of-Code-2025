#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> readBlocks() {
    vector<vector<string>> blocks;
    vector<string> cur;
    string s;
    ifstream archivo("input_12_B.txt");

    while (getline(archivo, s)) {
        if (s.empty()) {
            blocks.push_back(cur);
            cur.clear();
        } else cur.push_back(s);
    }
    if (!cur.empty()) blocks.push_back(cur);

    return blocks;
}

bool solveline1(string line, vector<int> shapes) {
    int W, H;
    int prevpos;
    vector<int> amounts;
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == 'x') {
            W = stoi(line.substr(0, i));
            prevpos = i + 1;
        }

        if(line[i] == ':') {
            H = stoi(line.substr(prevpos, i - prevpos));
            string rest = line.substr(i+2);
            stringstream ss(rest);
            int cant;
            while(ss >> cant) {
                amounts.push_back(cant);
            }
            break;
        }
    }

    long long tot = 0;
    long long max = H * W;
    for(int i = 0; i < amounts.size(); i++) {
        tot += shapes[i]*amounts[i];
    }

    return tot <= max;
}

void star1() {
    vector<vector<string>> blocks = readBlocks();
    vector<int> shapes;
    int res = 0;
    for(auto b : blocks) {
        if(b[0].size() == 2) {
            int area = 0;
            for(int i = 1; i < b.size(); i++) {
               for(auto c : b[i]) {
                    if(c == '#') {
                        area++;
                    }
               }
            }
            shapes.push_back(area);
        } else {
            for(auto line : b) {
                bool ok = solveline1(line, shapes);
                if(ok) {
                    res++;
                }
            }
        }
    }

    cout << "RES: " << res;
}

int main() {
    star1();
}