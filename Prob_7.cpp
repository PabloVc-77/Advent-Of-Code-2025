#include <bits/stdc++.h>
using namespace std;   

void star1() {
    vector<string> map;
    string s;
    while(cin >> s) {
        map.push_back(s);
    }

    int ini = 0;
    while(map[0][ini] != 'S') {ini++;}

    vector<int> positions;
    vector<int> nextpositions;
    vector<int> deleteables;
    positions.push_back(ini);
    int res = 0;

    cout << map[0] << endl;
    for(int i = 1; i < map.size(); i++) {

        nextpositions = positions;
        for(int j = 0; j < positions.size(); j++) {
            int pos = nextpositions.front();
            nextpositions.erase(nextpositions.begin());
            if(map[i][pos] == '^') {
                res++;
                nextpositions.push_back(max(0, pos - 1));
                nextpositions.push_back(min((int) map[0].size() - 1,pos + 1));
            } else {
                nextpositions.push_back(pos);
            }
        }
        sort(nextpositions.begin(), nextpositions.end());
        auto w = unique(nextpositions.begin(), nextpositions.end());
        nextpositions.erase(w, nextpositions.end());

        positions = nextpositions;
        s = map[i];
        for(auto p : positions) {
            s[p] = '|'; 
        }

        cout << s << endl;
    }

    cout << res;
}

int quantum(int f, int c, vector<string> map, int res) { // Good luck PC o7
    if(f == map.size()) {
        return res + 1;
    }

    if(map[f][c] == '^') {
        res = quantum(f + 1, max(0, c - 1) , map, res);
        res = quantum(f + 1, min((int)map[0].size(), c + 1), map, res);
    } else {
        res = quantum(f + 1, c, map, res);
    }

    return res;
}

void star2() {
    vector<string> map;
    string s;
    while(cin >> s) {
        map.push_back(s);
    }

    int ini = 0;
    while(map[0][ini] != 'S') {ini++;}

    int res = quantum(0, ini, map, 0);
    cout << res;
}


int main() {
    star2();
}