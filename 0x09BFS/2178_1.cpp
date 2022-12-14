#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

string board[102];
int dist[102][102];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for(int i=0; i<n; i++){
		fill(dist[i], dist[i] + m, -1); // 전부 -1 로 채움
	}
	queue<pair<int, int>>Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;

	while (!Q.empty()) {
		pair<int, int>cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] != '1') continue; // or 해야되는데 && 함
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1]+1; // 문제 특성상 거리+1이 정답
}
/*
디버깅 :
1) 예외 잡아 내는 곳에서 or 해야되는데 && 함
2) 공백 없는 숫자는 문자열로 받아내야 함
3) 거리가 어떻게 구해지는 지 생각하고 코드 짜기
*/