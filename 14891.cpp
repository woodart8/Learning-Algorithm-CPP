#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K;
vector<pair<bool, string>> wheel; // first: 돌릴 수 있는 바퀴인지, second: 바퀴 상태
bool visited[5] = {false ,false , false, false, false};
// 0: 상, 1: 우상, 2: 우, 3: 우하, 4: 하, 5: 좌하, 6: 좌, 7: 좌상 

int ans;

void turn(int num, int dir) {
    if(dir == 1) {
        swap(wheel[num].second[7], wheel[num].second[0]);
        for(int i=6; i>=1; i--) {
            swap(wheel[num].second[i], wheel[num].second[i+1]);
        }
    }
    else if(dir == -1) {
        for(int i=0; i<=6; i++) {
            swap(wheel[num].second[i], wheel[num].second[i+1]);
        }
    }
} // num번 바퀴 dir방향으로 회전

void move(int num, int dir) {
    if(num <= 0 || num > 4)  {
        return;
    } // 잘못된 num
    visited[num] = true;
    if(num == 1) {
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
    else if(num == 4) {
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
    wheel.push_back({true,""});
    for(int i=1; i<=4; i++) {
        string s;
        cin >> s;
        wheel.push_back({true, s});
    }

    cin >> K;
    for(int i=0; i<K; i++) {
        memset(visited, false, sizeof(visited));
        int num, dir;
        cin >> num >> dir;
        move(num, dir); // 바퀴 이동
    }

    for(int i=1; i<=4; i++) {
        if(wheel[i].second[0] == '1') ans = ans + (1 << (i-1));
    }
    cout << ans << endl;
    return 0;
}