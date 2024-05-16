#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K;
vector<pair<bool, string>> wheel; // first: 돌릴 수 있는 바퀴인지, second: 바퀴 상태
bool visited[4];

void turn(int num, int dir) {
    if(dir == 1) {
        for(int i=7; i>=1; i--) {
            swap(wheel[num].second[i], wheel[num].second[(i+1)%8]);
        }
        return;
    }
    if(dir == -1) {
        for(int i=1; i<=7; i++) {
            swap(wheel[num].second[i], wheel[num].second[(i+1)%8]);
        }
        return;
    }
} // num번 바퀴 dir방향으로 회전

void move(int num, int dir) {
    visited[num] = true;
    if(num == 0) {
        if(wheel[num].second[2] == wheel[num+1].second[6]) // 우측 바퀴 검사
            wheel[num+1].first = false;
        else {
            wheel[num+1].first = true;
        }
        turn(num, dir);
        if(wheel[num+1].first && !visited[num+1]) {
            move(num+1, -1 * dir);
        }
    }
    else if(num == 3) {
        if(wheel[num].second[6] == wheel[num-1].second[2]) // 좌측 바퀴 검사
            wheel[num-1].first = false;
        else {
            wheel[num-1].first = true;
        }
        turn(num, dir);
        if(wheel[num-1].first && !visited[num-1]) {
            move(num-1, -1 * dir);
        }
    }
    else {
        if(wheel[num].second[2] == wheel[num+1].second[6]) // 우측 바퀴 검사
            wheel[num+1].first = false;
        else {
            wheel[num+1].first = true;
        }
        if(wheel[num].second[6] == wheel[num-1].second[2]) // 좌측 바퀴 검사
            wheel[num-1].first = false;
        else {
            wheel[num-1].first = true;
        }
        turn(num, dir);
        if(wheel[num+1].first && !visited[num+1]) {
            move(num+1, -1 * dir);
        }
        if(wheel[num-1].first && !visited[num-1]) {
            move(num-1, -1 * dir);
        }
    }
}

int main() {
    for(int i=0; i<=3; i++) {
        string s;
        cin >> s;
        wheel.push_back({true, s});
    }

    cin >> K;
    for(int i=0; i<K; i++) {
        memset(visited, false, sizeof(visited));
        int num, dir;
        cin >> num >> dir;
        move(num-1, dir); // 바퀴 이동
    }

    int ans = 0;
    for(int i=0; i<=3; i++) {
        if(wheel[i].second[0] == '1') ans = ans + (1 << i);
    }
    cout << ans << endl;
    return 0;
}