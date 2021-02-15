#include<iostream>
using namespace std;
int a[100000];
int d[100000];
int main() {
	int t;
	int ans;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a[i];
	}
	ans = a[0];
	for (int i = 0; i < t; i++) {
		d[i] = a[i];
		if (i == 0) continue;
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
		if (d[i] > ans) ans = d[i]; 
	}
	cout << ans << '\n';
}