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

void zFunction(const string& s, vector<int>& z) {
	if (s.length() == 0)
		return;
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < s.length(); ++i) {
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}


int main() {
#ifdef PROGA
	freopen("in.txt", "r", stdin);
#endif
	string s, t;	
	getline(cin, s);
	getline(cin, t);
	string toAlgos = s + '#' + t;
	vector<int> p(toAlgos.size()), z(toAlgos.size());
	prefixFunction(toAlgos, p);
	zFunction(toAlgos, z);
	vector <long long> occurP(s.length() + 1, 0), occurZ(s.length() + 1, 0);
	for (int i = s.length() + 1; i < p.size(); ++i)
		if (p[i] > 0)
			++occurP[p[i] - 1];
	for (int i = s.length(); i > 0; --i)
		if (p[i] > 0)
			occurP[p[i] - 1] += occurP[i];
	for (int i = s.length() + 1; i < z.size(); ++i)
		if (z[i] > 0)
			++occurZ[z[i] - 1];
	for (int i = (int)s.length() - 1; i >= 0; --i)
		occurZ[i] += occurZ[i + 1];
	for (int i = 0; i <= s.length(); ++i)
		if (occurP[i] != occurZ[i])
			throw new runtime_error("Results of prefix- and z-functions are inconsistent");
	for (int i = 0; i < s.length(); ++i)
		cout << "Prefix #" << i + 1 << " occur " << occurP[i] << " times\n";
}






