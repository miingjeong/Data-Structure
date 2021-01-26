#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n, pos, a[100001];
stack<int>s;
vector<char>ans;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		s.push(i);
		ans.push_back('+');
		while (s.size() && s.top() == a[pos]) {
			pos++;
			s.pop();
			ans.push_back('-');
		}
	}

	if (s.size()) cout << "NO" << '\n';
	else for (char a : ans) cout << a << "\n";
	return 0;

}