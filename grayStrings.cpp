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

string alphabet;
void fillAlphabet() {
	alphabet.clear();
	for (char c = 'a'; c <= 'z'; ++c)
		alphabet.push_back(c);
	for (char c = 'A'; c <= 'Z'; ++c)
		alphabet.push_back(c);
}

vector<int> stringToVector (const string& s) {
	vector<int> res;
	for (int i = 0; i < s.length(); ++i) {
		bool flag = false;
		for (int j = 0; j < alphabet.size(); ++j) {
			if (alphabet[j] == s[i]) {
				res.push_back(j);
				flag = true;
				break;
			}
		}
		if (!flag)
			throw runtime_error("No such letter in alphabet: " + s[i]);
	}
	return res;
}

void ret0 () {
	cout << "0\n";
	exit(0);
}

int main() {
#ifdef PROGA
	freopen("in.txt", "r", stdin);
#endif
	fillAlphabet();
	string s;
	int n;
	cin >> s >> n;
	vector<int> input = stringToVector(s);
	int charNumber = 0;
	int pos = 0, num = 0;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] > input[pos]) {
			pos = i;
			num = 1;
			continue;
		}
		if (input[i] == input[pos])
			++num;
	}
	if (num > 1)
		ret0();
	for (int i = 0; i < input.size(); ++i)
		if (i != pos) {
			int curDist = abs(i - pos);
			char curNum = 0;
			while ((curDist & 1) == 0) {
				++curNum;
				curDist >>= 1;
			}
			if (curNum != input[i])
				ret0();
		}
	if (n < 1 + input[pos])
		ret0();
	long long answer = 1;
	for (int i = input[pos]; i < n - 1; ++i)
		answer <<= 1;
	cout << answer;
}






