//
// Created by fate on 2018/12/12.
//

#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef pair<string, int> P;
vector<P> a, T, A, B;
map<string, pair<int, int>> type2;
map<string, map<string, int>> type3;
bool cmp(const P &a, const P &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return a.first <= b.first;
    }
}

void print(vector<P> a) {
    if (a.size() == 0) {
        cout << "NA" << endl;
    }
    else {
        for (auto it : a) {
            cout << it.first << " " << it.second << endl;
        }
    }
}

int main() {
    cin >> n >> m;
    P p;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        if (p.first[0] == 'T') {
            T.push_back(p);
        }
        else if (p.first[0] == 'A') {
            A.push_back(p);
        }
        else {
            B.push_back(p);
        }
        string s = p.first.substr(1, 3);
        type2[s].first++;
        type2[s].second += p.second;
        string date = p.first.substr(4, 6);
        type3[date][s] ++;
    }
    sort(T.begin(), T.end(), cmp);
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    map<string, vector<P>> ans3;
    for (auto it : type3) {
        vector<P> temp;
        map<string, int> tt = it.second;
        for (auto i : tt) {
            p.first = i.first;
            p.second = i.second;
            temp.push_back(p);
        }
        sort(temp.begin(), temp.end(), cmp);
        ans3[it.first] = temp;
    }
    string Type, Term;
    for (int i = 1; i <= m; i++) {
        cin >> Type >> Term;
        cout << "Case " << i << ": " << Type << " " << Term << endl;
        if (Type == "1") {
            if (Term == "T") {
                print(T);
            }
            else if (Term == "A") {
                print(A);
            }
            else {
                print(B);
            }
        }
        else if (Type == "2") {
            if (type2[Term].first != 0) {
                cout << type2[Term].first << " " << type2[Term].second << endl;
            }
            else {
                cout << "NA" << endl;
            }
        }
        else {
            if (type3.find(Term) == type3.end()) {
                cout << "NA" << endl;
            }
            else {
                vector<P> temp = ans3[Term];
                print(temp);
            }
        }
    }
    return 0;
}
