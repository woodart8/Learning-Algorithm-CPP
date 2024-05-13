#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
vector<int> graph[33];
int dice[10];
int points[33] {
    0,
    2,4,6,8,10,
    12,14,16,18,20,
    22,24,26,28,30,
    32,34,36,38,40,
    13,16,19,22,24,
    28,27,26,25,30,
    35,0
};
bool visited[33];

void addVector(int here, int there) {
    graph[here].push_back(there);
}

int move(int here, int there, int cnt) {
    while(cnt--) {
        here = there;
        if(here == 32) return here;
        there = graph[here][0];
    }
    return here;
}

void Init() {
    for(int i=0; i<=19; i++) {
        addVector(i,i+1);
    }
    addVector(5,21);
    addVector(21,22);
    addVector(22,23);
    addVector(23,29);

    addVector(10,24);
    addVector(24,25);
    addVector(25,29);

    addVector(15,26);
    addVector(26,27);
    addVector(27,28);
    addVector(28,29);

    addVector(29,30);
    addVector(30,31);
    addVector(31,20);
    addVector(20,32);
}

void BT(int horse[4], int diceIdx, int point) {
    if(diceIdx == 10) {
        ans = max(ans, point);
        return;
    }
    for(int i=0; i<4; i++) {
        int cur = horse[i];
        if(cur == 32) continue;
        int next = move(cur, graph[cur][(graph[cur].size()+1)%2], dice[diceIdx]);
        if(next != 32 && visited[next]) continue;

        horse[i] = next;
        visited[cur] = false;
        visited[next] = true;
        BT(horse, diceIdx+1, point+points[next]);
        horse[i] = cur;
        visited[next] = false;
        visited[cur] = true;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Init();
    for(int i=0; i<10; i++) {
        cin >> dice[i];
    }
    int horse[4] = {dice[0],0,0,0};
    BT(horse, 1, points[dice[0]]);
    cout << ans << '\n';
    return 0;
}