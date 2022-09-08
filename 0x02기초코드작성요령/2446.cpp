// https://www.acmicpc.net/problem/2446
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = n; i >0; i--) {
		for (int j = 0; j < n - i; j++)cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++)cout << '*';
		cout << "\n";
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n - i; j++)cout << ' ';
		for (int j = 0; j < 2 * i - 1; j++)cout << '*';
		cout << "\n";
	}
}