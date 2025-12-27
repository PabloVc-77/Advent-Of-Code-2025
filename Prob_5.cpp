#include <bits/stdc++.h>
using namespace std;   

void star1() {
    vector<pair<unsigned long long, unsigned long long>> ranges;
    string s;
    while(getline(cin, s)) {
        if(s.empty()) {
            break;
        } else {
            unsigned long long num1, num2;

            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '-') {
                    num1 = stoull(s.substr(0, i));
                    num2 = stoull(s.substr(i+1));

                    ranges.push_back(pair(num1, num2));
                }
            }
        }
    }

    unsigned long long res = 0;
    unsigned long long id;
    while(cin >> id) {
        bool flag = true;
        for(int i = 0; i < ranges.size() && flag; i++) {
            if(id >= ranges[i].first && id <= ranges[i].second) {
                flag = false;
            }
        }

        if(!flag) {
            res++;
        }
    }

    cout << res;
}

void star2() {
    vector<pair<unsigned long long, unsigned long long>> ranges;
    string s;
    unsigned long long res = 0;
    while(getline(cin, s)) {
        if(s.empty()) {
            break;
        } else {
            unsigned long long num1, num2;

            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '-') {
                    num1 = stoull(s.substr(0, i));
                    num2 = stoull(s.substr(i+1));

                    bool flag = true;
                    bool flagf = false;
                    int pos;
                    for(int j = 0; j < ranges.size() && !flagf; j++) {
                        // MIN incluido en algun rango
                        if(ranges[j].first <= num1 && ranges[j].second >= num1) {
                            if(flag) {
                                if(ranges[j].second < num2) {
                                    ranges[j].second = num2;
                                }
                                pos = j;
                                flag = false;
                            } else {
                                ranges[pos].first = ranges[j].first;
                                ranges.erase(ranges.begin() + j);
                                pos--;
                                flagf = true;
                            }
                        }
                        
                        if(num2 >= ranges[j].first && num2 <= ranges[j].second) { // MAX incluido en algun rango
                            if(flag) {
                                if(ranges[j].first > num1) {
                                    ranges[j].first = num1;
                                }
                                pos = j;
                                flag = false;
                            } else {
                                ranges[pos].second = ranges[j].second;
                                ranges.erase(ranges.begin() + j);
                                pos--;
                                flagf = true;
                            }
                        }
                    }

                    if(flagf) {
                        unsigned long long min = ranges[pos].first, max = ranges[pos].second;
                        for(int j = 0; j < ranges.size(); j++) {
                            if(j != pos && ranges[j].first >= min && ranges[j].second <= max) {
                                ranges.erase(ranges.begin() + j);
                                j--;
                                pos--;
                            }
                        }
                    }

                    if(flag) {
                        ranges.push_back(pair(num1, num2));
                    }
                }
            }
        }
    }

    for(int i = 0; i < ranges.size(); i++) {
        res += ranges[i].second - ranges[i].first + 1;
    }

    cout << res;
}

void sstar2() {
    vector<pair<unsigned long long, unsigned long long>> ranges;
    string s;
    unsigned long long res = 0;
    while(getline(cin, s)) {
        if(s.empty()) {
            break;
        } else {
            unsigned long long num1, num2;

            for(int i = 0; i < s.length(); i++) {
                if(s[i] == '-') {
                    num1 = stoull(s.substr(0, i));
                    num2 = stoull(s.substr(i+1));
                    break;
                }
            }

            bool flag = true;
            for(int i = 0; i < ranges.size() && flag; i++) {
                if(num1 > ranges[i].second) {
                    continue;
                } else if(num1 >= ranges[i].first) { // Incluido en el rando
                    if(ranges[i].second < num2) {
                        flag = false;
                        ranges[i].second = num2;
                        for(int j = i + 1; j < ranges.size();j++) {
                            if(num2 < ranges[i].first) {
                                break;
                            }

                            if(num2 >= ranges[j].second) {
                                ranges.erase(ranges.begin() + j);
                                j--;
                            } else if (num2 >= ranges[j].first && num2 < ranges[j].second) {
                                ranges[i].second = ranges[j].second;
                                ranges.erase(ranges.begin() + j);
                                break;
                            }
                        }
                    }
                } else if(num2 >= ranges[i].first) {
                    if(num2 <= ranges[i].second) {ranges[i].first = num1; flag = false;}
                    else {
                        ranges.erase(ranges.begin() + i);
                        i--;
                    }
                    
                } else {break;}
            }

            if(flag) {
                ranges.push_back(pair(num1, num2));
            }

            std::sort(ranges.begin(), ranges.end());
        }
    }

    for(int i = 0; i < ranges.size(); i++) {
        res += ranges[i].second - ranges[i].first + 1;
    }

    cout << res;
}


void tar2() {
    vector<pair<unsigned long long, unsigned long long>> ranges;
    string s;
    
    while (getline(cin, s)) {
        if (s.empty()) break;

        size_t pos = s.find('-');
        unsigned long long num1 = stoull(s.substr(0, pos));
        unsigned long long num2 = stoull(s.substr(pos + 1));
        ranges.push_back({num1, num2});
    }

    sort(ranges.begin(), ranges.end());

    unsigned long long res = 0;
    unsigned long long mn = ranges[0].first;
    unsigned long long mx = ranges[0].second;

    for (int i = 1; i < ranges.size(); i++) {
        if (ranges[i].first > mx) {
            // No overlap
            res += mx - mn + 1;
            mn = ranges[i].first;
            mx = ranges[i].second;
        } else {
            // Overlap
            mx = max(mx, ranges[i].second);
        }
    }

    res += mx - mn + 1;

    cout << res;
}

int main() {
    tar2();
}