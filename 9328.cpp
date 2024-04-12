#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int t,h,w;
char board[102][102];
int vis[102][102];
string hasKey;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> h >> w;
        int ans = 0;
        queue<pair<int,int>> q;
        queue<pair<int,int>> door[26]; // 열쇠가 없어서 다음에 방문할 곳의 좌표
        // 처음에는 빌딩의 밖에 있으며, 빌딩 가장자리의 벽이 아닌 곳을 통해 빌딩 안팎을 드나들 수 있다.
        for (int i = 0; i <= h + 1; i++) {
            fill(vis[i], vis[i] + w + 2, 0);
            fill(board[i], board[i] + w + 2, 0);
        }
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                cin >> board[i][j];
        int key[26] = {}; // 열쇠 획득 여부를 저장할 배열. 열쇠 획득 시 1, 미획득 시 0
        cin >> hasKey;
        for (auto e : hasKey) key[e - 'a'] = 1;

        q.push({0,0});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
                if (vis[nx][ny] || board[nx][ny] == '*') continue;
                vis[nx][ny] = 1;

                // 1. 열쇠인 경우 (소문자)
                if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
                    int k = board[nx][ny] - 'a';
                    key[k] = 1; // 열쇠 등록
                    while (!door[k].empty()) { // 열쇠를 찾았으니 해당하는 문은 열고 방문이 가능하다.
                        auto nextDoor = door[k].front(); door[k].pop();
                        q.push({nextDoor.X,nextDoor.Y});
                    }
                }
                // 2. 문인 경우 (대문자)
                else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
                    int k = board[nx][ny] + 32 - 'a';
                    if (!key[k]) { // 키가 없으면
                        // 다음에 방문
                        door[k].push({nx,ny});
                        continue;
                    }
                }
                // 3. 문서인 경우
                else if (board[nx][ny] == '$') ans++;

                q.push({nx,ny});
            }
        }

        cout << ans << '\n';
    }

    return 0;
}