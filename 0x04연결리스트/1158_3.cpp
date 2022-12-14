// Authored by : seondal
// Co-authored by : BaaaaaaaaaaarkingDog
// https://www.acmicpc.net/problem/1158
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int>V, ans;
	for (int i = 1; i <= n; i++) V.push_back(i); //N
	
	for (int i = 0; ans.size() < n; i++) { // 정답 벡터에 n개의 원소가 쌓이면 종료
		if (i % k == k - 1) ans.push_back(V[i]); 
		else V.push_back(V[i]);
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << ans[i]; // 마지막 원소는 , 없이 출력
		else cout << ans[i] << ", ";
	}
	cout << '>';
}

/*
STL vector를 이용한 풀이
매 순간 아직 제거되지 않은 원소는 제일 뒤로 보내고(V.push_back(V[i]))
제거되는 원소는 ans에 저장하고 있다가 다 채워지면 출력.
공간 복잡도가 O((K-1)*N + N)이라는 단점이 있음.
*/