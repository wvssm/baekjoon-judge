// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/ae38aa7eb7a44aca87e9d7928402d040
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int> > Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) // 입력과 동시에 시작점이면 queue에 push
                Q.push({ i,j });
            if (board[i][j] == 0) // 토마토 영역에는 dist = -1로 설정
                dist[i][j] = -1;
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] >= 0) continue; // 안익은 토마토는 dist는 -1로 설정해놨기 때문에 가능
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx,ny });
        }
    }
    // 토마토가 전부 익었는지, 토마토가 익는데 며칠 걸렸는지 동시에 검사
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) { // 안익은 토마토가 있다면
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}