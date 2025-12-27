#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std; 

void star1() {
    vector<pair<long long, long long>> coords;
    string s;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            long long x, y;
            if(s[i] == ',') {
                x = stoi(s.substr(0, i));
                y = stoi(s.substr(i + 1));
                coords.push_back(pair(x,y));
                break;
            }
        }
    }

    long long res = -1;
    int cx1, cx2, yx1, yx2;
    for(int i = 0; i < coords.size(); i++) {
        int x1 = coords[i].first, y1 = coords[i].second;
        for(int j = 0; j < coords.size(); j++) {
            if(j!=i) {
                int x2 = coords[j].first, y2 = coords[j].second;
                long long area = (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
                if(area > res) {
                    res = area;
                    cx1 = x1; cx2 = x2; yx1 = y1; yx2 = y2;
                }
            }
        }
    }

    cout << "[" << cx1 << "," << yx1 << "] :: [" << cx2 << "," << yx2 << "]" << endl;
    cout << res;
}   

void sstar1() {

    vector<pair<long long, long long>> coords;
    string s;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            long long x, y;
            if(s[i] == ',') {
                x = stoi(s.substr(0, i));
                y = stoi(s.substr(i + 1));
                coords.push_back(pair(x,y));
                break;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < coords.size(); i++) {
        for (int j = 0; j < coords.size(); j++) {
            ans = max(ans, (abs(coords[i].first - coords[j].first) + 1) * (abs(coords[i].second - coords[j].second) + 1));
        }
    }
    cout << ans << endl;
}

void test() {
    vector<pair<long long, long long>> coords;
    string s;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            long long x, y;
            if(s[i] == ',') {
                x = stoi(s.substr(0, i));
                y = stoi(s.substr(i + 1));
                coords.push_back(pair(x,y));
                break;
            }
        }
    }

    long long mx = -1, my = -1;
    for(int i = 0; i < coords.size(); i++) {
        mx = max(mx, coords[i].first);
        my = max(my, coords[i].second);
    }

    cout << mx << "," << my;
}

void noejec() {
    vector<pair<long long, long long>> coords;
    string s;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            long long x, y;
            if(s[i] == ',') {
                x = stoi(s.substr(0, i));
                y = stoi(s.substr(i + 1));
                coords.push_back(pair(x,y));
                break;
            }
        }
    }

    
    vector<string> dibujito(9, string(14, '.')); // No consola
    long long prevx = coords[0].first, prevy = coords[0].second;
    dibujito[prevy][prevx] = '#';
    for(int i = 1; i < coords.size(); i++) {
        long long x = coords[i%coords.size()].first, y = coords[i%coords.size()].second;
        if(prevy == y) {
            dibujito[y].replace(dibujito[y].begin() + (min(prevx, x) + 1), dibujito[y].begin() + max(prevx, x), abs(prevx - x), 'X');
            dibujito[y][x] = '#';
        } else {
            for(int j = min(y, prevy) + 1; j < max(y, prevy); j++) {
                dibujito[j][x] = 'X';
            }
            dibujito[y][x] = '#';
        }

        prevx = x; prevy = y;
    }
    
    for(int i = 0; i < dibujito.size(); i++) {
        cout << dibujito[i] << endl;
    }
}

bool checkAngle(pair<long long, long long> p, vector<pair<long long, long long>> coords) {
    double c = 0;
    for (int i = 0; i < coords.size(); i++) {

        pair<long long, long long> p1 = coords[i];
        pair<long long, long long> p2 = coords[(i + 1) % coords.size()];

        pair<long long, long long> v1 = {p1.first - p.first, p1.second - p.second};
        pair<long long, long long> v2 = {p2.first - p.first, p2.second - p.second};

        double va_vb = (double)v1.first * v2.first + (double)v1.second * v2.second;

        double mod1 = sqrt((double)v1.first * v1.first + (double)v1.second * v1.second);
        double mod2 = sqrt((double)v2.first * v2.first + (double)v2.second * v2.second);
        double modulos = mod1 * mod2;

        if (modulos == 0) continue;   // ← evita crash

        double cosang = va_vb / modulos;

        // Clamp por errores numéricos
        cosang = max(-1.0, min(1.0, cosang));

        c += acos(cosang);
    }


    //return c == 2 * M_PI;
    return abs(c - 2*M_PI) < 1e-6;

}

bool checkRay(pair<long long, long long> p, vector<pair<long long, long long>>& poly) {
    bool inside = false;
    int n = poly.size();

    for (int i = 0, j = n - 1; i < n; j = i++) {
        auto [xi, yi] = poly[i];
        auto [xj, yj] = poly[j];

        if ((yi > p.second) != (yj > p.second)) {
            double x_intersect =
                (double)(xj - xi) * (p.second - yi) / (double)(yj - yi) + xi;

            if (p.first < x_intersect)
                inside = !inside;
        }
    }

    return inside;
}

void star2() {
    vector<pair<long long, long long>> coords;
    string s;
    while(cin >> s) {
        for(int i = 0; i < s.size(); i++) {
            long long x, y;
            if(s[i] == ',') {
                x = stoi(s.substr(0, i));
                y = stoi(s.substr(i + 1));
                coords.push_back(pair(x,y));
                break;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < coords.size(); i++) {
        long long x1 = coords[i].first, y1 = coords[i].second;
        for (int j = 0; j < coords.size(); j++) {
            long long x2 = coords[j].first, y2 = coords[j].second;
            long long a = max(ans, (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1));
            if(a > ans) {
                bool flag = true;
                for(int k = min(x1, x2); k <= max(x1, x2) && flag; k++) {
                    if(!checkAngle(pair(k, min(y1, y2)), coords)) {
                        flag = false;
                    }
                }
                for(int k = min(y1, y2); k <= max(y1, y2) && flag; k++) {
                    if(!checkAngle(pair(max(x1, x2), k), coords)) {
                        flag = false;
                    }
                }
                for(int k = max(x1, x2); k >= min(x1, x2) && flag; k--) {
                    if(!checkAngle(pair(k, max(y1, y2)), coords)) {
                        flag = false;
                    }
                }
                for(int k = max(y1, y2); k >= min(y1, y2) && flag; k--) {
                    if(!checkAngle(pair(min(x1, x2), k), coords)) {
                        flag = false;
                    }
                }

                if(flag) {
                    ans = a;
                }
            }
        }
    }

    cout << ans;
}

long long area(long long x1, long long y1, long long x2, long long y2) {
    return llabs(x1 - x2) * llabs(y1 - y2);
}

void gptstar2() {
    vector<pair<long long, long long>> coords;
    string s;

    while (cin >> s) {
        int pos = s.find(',');
        long long x = stoll(s.substr(0, pos));
        long long y = stoll(s.substr(pos + 1));
        coords.push_back({x, y});
    }

    long long ans = 0;

    for (int i = 0; i < coords.size(); i++) {
        for (int j = i + 1; j < coords.size(); j++) {

            long long x1 = coords[i].first;
            long long y1 = coords[i].second;
            long long x2 = coords[j].first;
            long long y2 = coords[j].second;

            long long A = area(x1, y1, x2, y2);
            if (A <= ans) continue;

            bool ok = true;

            // Borde inferior
            for (long long x = min(x1, x2); x <= max(x1, x2) && ok; x++)
                if (!checkRay({x, min(y1, y2)}, coords)) ok = false;

            // Borde derecho
            for (long long y = min(y1, y2); y <= max(y1, y2) && ok; y++)
                if (!checkRay({max(x1, x2), y}, coords)) ok = false;

            // Borde superior
            for (long long x = max(x1, x2); x >= min(x1, x2) && ok; x--)
                if (!checkRay({x, max(y1, y2)}, coords)) ok = false;

            // Borde izquierdo
            for (long long y = max(y1, y2); y >= min(y1, y2) && ok; y--)
                if (!checkRay({min(x1, x2), y}, coords)) ok = false;

            if (ok)
                ans = A;
        }
    }

    cout << ans;
}

int main() {
    star2();
}