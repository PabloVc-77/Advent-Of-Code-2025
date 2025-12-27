#include <bits/stdc++.h>
using namespace std;    
    
void star1() {
    string s;
    vector<string> map;
    int res = 0;
    while(cin >> s) {
        map.push_back(s);
    }

    for(int i = 0; i < map.size(); i++) {
        for(int j = 0; j < map[i].size(); j++) {
            if(map[i][j] == '@') {
                int count = 0;
                if(i != 0) {
                    for(int k = max(0,j - 1); k < j + 2 && k < map[i].size(); k++) {
                        if(map[i - 1][k] == '@') {count++;}
                    }
                }
                if(j > 0 && map[i][j - 1] == '@') {count++;}
                if(j < map[i].size() - 1 && map[i][j + 1] == '@') {count++;}
                
                if(i < map.size() - 1) {
                    for(int k = max(0, j - 1); k < j + 2 && k < map[i].size(); k++) {
                        if(map[i + 1][k] == '@') {count++;}
                    }
                }

                if(count < 4) {
                    res++;
                    cout << 'x';
                } else {
                    cout << '@';
                }
            } else {cout << '.';}
        }
        cout << endl;
    }

    cout << res;
}

void star2() {
    string s;
    vector<string> map;
    int res = 0, pastres = -1;
    while(cin >> s) {
        map.push_back(s);
    }


    int sz = map.size();
    while(res != pastres) {
        vector<string> map2(sz,"");
        pastres = res;
        for(int i = 0; i < map.size(); i++) {
            for(int j = 0; j < map[i].size(); j++) {
                if(map[i][j] == '@') {
                    int count = 0;
                    if(i != 0) {
                        for(int k = max(0,j - 1); k < j + 2 && k < map[i].size(); k++) {
                            if(map[i - 1][k] == '@') {count++;}
                        }
                    }
                    if(j > 0 && map[i][j - 1] == '@') {count++;}
                    if(j < map[i].size() - 1 && map[i][j + 1] == '@') {count++;}
                    
                    if(i < map.size() - 1) {
                        for(int k = max(0, j - 1); k < j + 2 && k < map[i].size(); k++) {
                            if(map[i + 1][k] == '@') {count++;}
                        }
                    }

                    if(count < 4) {
                        res++;
                        cout << 'x';
                        map2[i] += 'x';
                    } else {
                        cout << '@';
                        map2[i] += '@';
                    }
                } else {cout << '.'; map2[i] += '.';}
            }
            cout << endl;
        }

        cout << endl << endl << endl;

        map = map2;
    }

    cout << res;
}

int main() {
    star2();
}