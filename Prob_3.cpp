#include <bits/stdc++.h>

using namespace std;    
    
void star(int amount) {
    string s;
    unsigned long long res = 0;
    while(cin>>s) {
        char max1 = '0';
        max1 = s[0];
        int skip_pos = 0;
        unsigned long long num = 0;

        for(int j = amount - 1; j >= 0; j--) {
            for(int i = skip_pos + 1; i < s.size() - j; i++) {
                if(max1 < s[i]) {
                    max1 = s[i];
                    skip_pos = i;
                }

                if(max1 == '9') {break;}
            }
            num += (max1 - '0') * pow(10,j);
            max1 = '0';
        }
        
        
        res += num;
    }

    cout << res;
}

int main() {
    star(12); // star1 = 2 , star2 = 12
}