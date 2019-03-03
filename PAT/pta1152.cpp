//
// Created by fate on 2018/12/12.
//
#include <bits/stdc++.h>
using namespace std;

bool prime(long long n) {
    if (n < 2) {
        return 0;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 6 != 1 && n % 6 != 5) {
        return false;
    }
    int a = sqrt(n);
    for (int i = 6; i <= a; i += 6) {
        if (n % (i - 1) == 0 || n % (i + 1) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    if (n < k) {
        cout << 404 << endl;
        return 0;
    }
    long long t = 0;
    for (int i = 0; i < k; i++) {
        t = t * 10 + (s[i] - '0');
    }
    if (prime(t)) {
        cout << s.substr(0, k) << endl;
        return 0;
    }
    for (int i = k; i < n; i++) {
        t = t * 10 + (s[i] - '0');
        t = t % (int)pow(10, k);
        if (prime(t)) {
            cout << s.substr(i - k + 1, k) << endl;
            return 0;
        }
    }
    cout << 404 << endl;
    return 0;
}
