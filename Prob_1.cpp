#include <bits/stdc++.h>
using namespace std;

void star1() { // Puede que no este bien (no original)
    string s;
    int pass = 50;
    int turns = 0;

    int res = 0;

    while (cin >> s) {   
        turns = stoi(s.substr(1));
        if (s[0] == 'L') {
            pass -= turns;
        } 
        else if (s[0] == 'R') {
            pass += turns;
        }
        pass = (pass % 100 + 100) % 100; // Ajustar pass en rango

        if(pass == 0) {
            res++;
        }
    }

    cout << res;
}

void star2() {
    string s;
    int pass = 50;
    int turns = 0;

    int res = 0;

    while (cin >> s) {   
        turns = stoi(s.substr(1));
        res += turns / 100;

        turns = turns % 100;

        if (s[0] == 'L') {
            if(pass == 0) {res--;} // 0 - x no pasa por 0 (pre-Corrección para después)
            pass -= turns;
        } 
        else if (s[0] == 'R') {
            pass += turns;
        }

        if(pass <= 0 || pass >= 100) {res++;}

        pass = (pass % 100 + 100) % 100; // Ajustar pass en rango
    }

    cout << res;
}

int main() {
    star1();
}
