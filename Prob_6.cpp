#include <bits/stdc++.h>
using namespace std;   

void star1() {
    string s;
    vector<vector<long long>> nums;
    vector<string> ops;
    int c = 0;
    while(getline(cin, s)) {
        stringstream ss(s);
        string num;
        nums.push_back(vector<long long>(0));
        while (std::getline(ss, num, ' ')) {
            if(num == "+" || num == "*") {
                ops.push_back(num);
            } else if(num.length() > 0){
                nums[c].push_back(stoll(num));
            }
        }
        c++;
    }
    unsigned long long res = 0;
    unsigned long long col;
    for(int i = 0; i < nums[0].size(); i++) {
        if(ops[i] == "*") {
            col = 1;
        } else {
            col = 0;
        }
        
        for(int j = 0; j < nums.size() - 1; j++) {
            if(ops[i] == "*") {
                col = col * nums[j][i];
            } else {
                col += nums[j][i];
            }
        }

        res += col;
    }

    cout << res;
}

void star2() {
    string s;
    vector<string> input;
    vector<char> ops;
    while(getline(cin, s)) {
        input.push_back(s);
    }

    vector<vector<long long>> nums(1);
    int c = 0;
    for(int i = 0; i < input[0].size(); i++) {
        string n = "";
        for(int j = 0; j < input.size(); j++) {
            if(input[j][i] != ' ') {
                if(input[j][i] == '*' || input[j][i] == '+') {
                    ops.push_back(input[j][i]);
                } else {
                    n += input[j][i];
                }
            }
        }

        if(n == "") {
            nums.push_back(vector<long long>(0));
            c++;
        } else {
            nums[c].push_back(stoll(n));
        }
    }

    unsigned long long res = 0;
    unsigned long long col;
    for(int i = 0; i < nums.size(); i++) {
        if(ops[i] == '*') {
            col = 1;
        } else {
            col = 0;
        }
        
        for(int j = 0; j < nums[i].size(); j++) {
            if(ops[i] == '*') {
                col = col * nums[i][j];
                cout << nums[i][j] << " * ";
            } else {
                col += nums[i][j];
                cout << nums[i][j] << " + ";
            }
        }

        cout << endl;
        res += col;
    }

    cout << res;
}

int main() {
    star2();
}