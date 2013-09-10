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

void prefixFunction(const string& s, vector<int>& p) {
	if (s.length() == 0)
		return;
	p[0] = 0;
	for (int i = 1; i < s.length(); ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			++j;
		p[i] = j;
	}
}

int main() {
#ifdef PROGA
	freopen("in.txt", "r", stdin);
#endif
	string s;
	cin >> s;
	if (s.empty()) {
		cout <<"0\n";
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < s.length(); ++i) {
		string q;
		for (int j = i; j >= 0; --j)
			q += s[j];
		vector<int> curPref(i + 1);
		prefixFunction(q, curPref);
		int mx = 0;
		for (int j = 0; j < curPref.size(); ++j)
			mx = max(mx, curPref[j]);
		ans += i + 1 - mx;
	}
	cout << ans << "\n";
}






