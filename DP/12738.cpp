#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
vector<int> vt;
vector<int>::iterator iter;
int main() {

	int n, data;

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> data;
		if (i == 0) vt.push_back(data);
		if (vt.back() < data)vt.push_back(data);
		else {
			iter = lower_bound(vt.begin(), vt.end(), data);
			*iter = data;
		}
	}
	cout << vt.size();
	return 0;
}