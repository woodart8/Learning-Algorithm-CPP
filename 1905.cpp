#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int lx, ly, lz;
    int px, py;
    int alt = 0;
};

int Lx, Ly, N; // 창고의 가로, 세로, 입고되는 상자의 개수
// 1 <= Lx, Ly <= 1000
// 1 <= N <= 20000
vector<Box> v;

bool isOver(Box& a, Box& b) {
    return (a.px < b.px + b.lx && a.px + a.lx > b.px &&
            a.py < b.py + b.ly && a.py + a.ly > b.py);
}

void input() {
    cin >> Lx >> Ly >> N;
    for (int i=0; i<N; i++) {
        Box box;
        cin >> box.lx >> box.ly >> box.lz >> box.px >> box.py;
        v.push_back(box);
    }
}

void solve() {
    int answer = 0;
    for (int i=0; i<v.size(); i++) {
        v[i].alt = v[i].lz;
        for (int j=i-1; j>=0; j--) {
            if (isOver(v[i],v[j])) {
                v[i].alt = max(v[i].alt, v[j].alt+v[i].lz);
            }
        }
        answer = max(answer, v[i].alt);
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}