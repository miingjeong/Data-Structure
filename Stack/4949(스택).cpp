#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int>st;
int main() {
	string S;

	while (1) {
		//getline()함수 사용
		//길이가 일이고 .이면 끝냄
		getline(cin, S);
		if (S.length() == 1 && S[0] == '.')
			break;
		//스택 초기화
		while (!st.empty())
			st.pop();

		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '(')
				st.push(1);
			else if (S[i] == '[')
				st.push(2);
			else if (S[i] == ')') {
				if (!st.empty() && st.top() == 1)
					st.pop();
				else st.push(3);
			}
			else if (S[i] == ']') {
				if (!st.empty() && st.top() == 2)
					st.pop();
				else st.push(4);
			}
		}

		if (st.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

}