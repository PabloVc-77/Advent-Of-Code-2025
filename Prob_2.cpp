#include <bits/stdc++.h>
using namespace std;    
    
void star1() {
    std::string s;
    cin >> s;
    vector<std::string> tokens;
    string token;
    stringstream ss(s);

    unsigned long long res = 0;

    // Usando stringstream y getline
    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    for(string cd : tokens) {
        string ini, fin;
        for(int i = 0; i < cd.length(); i++) {
            if(cd[i] == '-') {
                ini = cd.substr(0, i);
                fin = cd.substr(i+1);
                break;
            }
        }


        long long in = stoll(ini), fn = stoll(fin);
        cout << "IN: " << in << " FN: " << fn << endl;
        string aux;
        for(long long i = in; i <= fn; i++) {
            aux = to_string(i);
            int tam = aux.length() / 2;
            if(aux.substr(0, tam) == aux.substr(tam)) {
                res += i;
                cout << "ESTP: " << i << endl;
            } 
        }
    }

    cout << res << '\n';
}

void star2() {
    std::string s;
    cin >> s;
    vector<std::string> tokens;
    string token;
    stringstream ss(s);

    unsigned long long res = 0;

    // Usando stringstream y getline
    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    for(string cd : tokens) {
        string ini, fin;
        for(int i = 0; i < cd.length(); i++) {
            if(cd[i] == '-') {
                ini = cd.substr(0, i);
                fin = cd.substr(i+1);
                break;
            }
        }


        long long in = stoll(ini), fn = stoll(fin);
        cout << "IN: " << in << " FN: " << fn << endl;
        string aux;
        for(long long i = in; i <= fn; i++) {
            aux = to_string(i);
            int tam = aux.length();
            for(int j = 1; j <= tam / 2; j++){
                bool flag = true;
                string p1 = aux.substr(0,j);
                for(int k = j; k < tam && flag; k += j) {
                    string p2 = aux.substr(k, j);
                    flag = p1 == p2;
                }

                if(flag) {
                    res += i;
                    break;
                }
            } 
        }
    }

    cout << res << '\n';
}

int main() {
    star2();
}