#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 봄에는 나이만큼 양분먹고 나이+1, 나이 어린순서대로, 못먹으면 쥬금
// 여름에는 죽은 나무의 나이 / 2 만큼 양분 추가, 소수점 아래 버림
// 가을에는 번식, 나무의 나이가 5의 배수, 인접한 8개 칸에 나이 1인 나무 추가
// 겨울에는 초기값만큼 양분 추가
// K년 후 살아있는 나무 개수 구하기
int N,M,K;
int A[11][11];
int map[11][11];
int cnt[11][11];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> trees[11][11];

void spring() {
    memset(cnt, 0, sizeof(cnt));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(!trees[i][j].empty()) {
                sort(trees[i][j].begin(), trees[i][j].end());
                for(int k=0; k<trees[i][j].size(); k++) {
                    if(trees[i][j][k] <= map[i][j]) {
                        map[i][j] -= trees[i][j][k];
                        trees[i][j][k]++;
                    }
                    else {
                        for(int l = trees[i][j].size()-1; l>=k; l--) {
                            cnt[i][j] += trees[i][j][l] / 2;
                            trees[i][j].pop_back();
                        }
                        break;
                    }
                }
            }
        }
    }
    return;
}

void summer() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            map[i][j] += cnt[i][j];
        }
    }
    return;
}

void autumn() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(!trees[i][j].empty()) {
                for(int k=0; k<trees[i][j].size(); k++) {
                    if(trees[i][j][k] % 5 == 0) {
                        for(int dir=0; dir<8; dir++) {
                            int next_x = i + dx[dir];
                            int next_y = j + dy[dir];
                            if(next_x < 1 || next_y < 1 || next_x > N || next_y > N) continue;
                            trees[next_x][next_y].push_back(1);
                        }
                    }
                }
            }
        }
    }
    return;
}

void winter() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            map[i][j] += A[i][j];
        }
    }
    return;
}

void season(int k) {
    while(k) {
        spring();
        summer();
        autumn();
        winter();
        k--;
    }
    return;
}

int cnt_trees() {
    int ans = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(!trees[i][j].empty()) {
                ans += trees[i][j].size();
            }
        }
    }
    return ans;
}

int main() {
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> A[i][j];
        }
    } // 초기 정보 입력

    for(int i=0; i<M; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    } // 나무 정보 입력

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            map[i][j] = 5;
        }
    }

    season(K);
    cout << cnt_trees() << endl;
    return 0;
} 