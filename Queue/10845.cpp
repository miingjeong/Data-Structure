#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	queue<int>qu;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			qu.push(num);

		}
		else if (str == "pop") {
			if (!qu.empty()) {
				cout << qu.front() << endl;
				qu.pop();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (str == "size") {
			cout << qu.size() << endl;
		}
		else if (str == "empty") {
			if (qu.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if (str == "front") {
			if (!qu.empty()) {
				cout << qu.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (str == "back") {
			if (!qu.empty()) {
				cout<<qu.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}

	}


	return 0;

}