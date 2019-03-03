//
// Created by fate on 2018/12/12.
//
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, cnt;
	string s;
	while(cin >> a >> b) {
		s.clear();
		cnt = 0;
		a += b;
		if(a < 0) {
			cout << "-";
			a = -a;
		}
		do {
			s += (a % 10) + '0';
			a /= 10;
			cnt ++;
			if(cnt == 3 && a) {
				cnt = 0;
				s += ",";
			}
		} while(a);
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}