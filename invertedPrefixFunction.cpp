#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <time.h>
#include <vector>
#include <list>
#include <cassert>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <cstdio>
#include <cmath>
#include <memory>
using namespace std;

typedef long long li;

#define all(a) a.begin(), a.end()
#define mp make_pair

int main() {
#ifdef PROGA
	freopen("in.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	string s;
	s += 'a';
	if (p[0] != 0) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (p[i] > p[i - 1] + 1) {
			cout << "NO\n";
			return 0;
		}
		int j = p[i - 1];
		set<char> had;
		while (j > 0 && j + 1 > p[i]) {
			had.insert(s[j]);
			j = p[j - 1];
		}
		if (p[i] == 0) {
			had.insert('a');
			for (char c = 'a'; c <= 'z'; ++c) {
				if (had.find(c) == had.end()) {
					s += c;
					break;
				}
			}
			continue;
		}
		if (j + 1 != p[i]) {
			cout << "NO\n";
			return 0;
		}
		if (had.find(s[j]) != had.end()) {
			cout << "NO\n";
			return 0;
		}
		s += s[j];
	}
	cout << "YES\n";
	cout << s << "\n";
}
