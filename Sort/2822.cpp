#define _CRT_SECURE_NO_WARNINGS
#include bitsstdc++.h
using namespace std;
int arr[8];
int sol[8];

int main() {
	for (int i = 0; i  8; i++)
		cin  arr[i];

	for (int i = 0; i  8; i++)
		sol[i] = arr[i];

	sort(arr, arr + 8);
	int sum = 0;
	sum = arr[3] + arr[4] + arr[5] + arr[6] + arr[7];
	cout  sumendl;

	for (int j = 0; j  8; j++) {
		if (sol[j] == arr[3]  sol[j] == arr[4]  sol[j] == arr[5]  sol[j] == arr[6]  sol[j] == arr[7])
			cout  j+1   ;
	}


}