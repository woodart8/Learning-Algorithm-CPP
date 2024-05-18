#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <cmath>
using namespace std;
#define MAX 50

int N,M,T;
int sz;
int sum;
vector<deque<int>> disk;

void Init() {
    cin >> N >> M >> T;
    for(int i=0; i<N; i++) {
        deque<int> dq;
        for(int j=0; j<M; j++) {
            int num;
            cin >> num;
            dq.push_back(num);
            sum += num;
        }
        disk.push_back(dq);
    }
    sz = N*M;
}

void FindTarget() {
    if(sz == 0) return;
    bool check[MAX][MAX];
    memset(check, false, sizeof(check));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(disk[i][j] == 0) continue;
            if(disk[i][j] == disk[i][(j+1)%M]) {
                check[i][j] = true;
                check[i][(j+1)%M] = true;
            }
        } 
    } // 같은 원반에서 인접한 경우

    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M; j++) {
            if(disk[i][j] == 0) continue;
            if(disk[i][j] == disk[i+1][j]) {
                check[i][j] = true;
                check[i+1][j] = true;
            }
        }
    } // 서로 다른 원반에서 인접한 경우

    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(check[i][j]) {
                sum -= disk[i][j];
                disk[i][j] = 0;
                cnt++;
            }
        }
    } //숫자 지우기

    if(cnt > 0) {
        sz -= cnt;
    }
    else {
        int avg = sum/sz;
        int res = sum%sz;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(disk[i][j] == 0) continue;
                if(res == 0) { //나머지가 0이면 평균이 정수임
                    if(disk[i][j] > avg) {
                        disk[i][j]--;
                        sum--;
                    }
                    else if(disk[i][j] < avg) {
                        disk[i][j]++;
                        sum++;
                    }
                }
                else { //나머지가 0이 아니면 평균이 실수임
                    if(disk[i][j] > avg) {
                        disk[i][j]--;
                        sum--;
                    }
                    else { //avg와 disk[i][j]가 같아도 실제평균은 (avg).xx임
                        disk[i][j]++;
                        sum++;
                    } 
                }
            }
        }
    }
}

void Spin(int x, int d, int k) {
    for(int i=x-1; i<N; i+=x) {
        for(int j=0; j<k; j++) {
            if(!d) { // 시계방향
                int temp = disk[i].back();
                disk[i].pop_back();
                disk[i].push_front(temp);
            }
            else {
                int temp = disk[i].front();
                disk[i].pop_front();
                disk[i].push_back(temp);
            }
        }
    }
}

void Solve() {
    for(int i=0; i<T; i++) {
        int x,d,k;
        cin >> x >> d >> k;
        Spin(x,d,k);
        FindTarget();
    }
    cout << sum;
}

int main() {
    Init();
    Solve();
    return 0;
}