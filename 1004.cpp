#include <iostream>
#include <vector>

using namespace std;

struct Planet {
    int cx, cy, r;
};

int T;
int n;
int x1, y1, x2, y2;
vector<Planet> v;

void init() {
    n=0;
    x1=0; y1=0; x2=0; y2=0;
    v.clear();
}

void input() {
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;

    for (int i=0; i<n; i++) {
        int cx, cy, r;
        cin >> cx >> cy >> r;
        Planet p = {cx, cy, r};
        v.push_back(p);
    }
}

bool checkInside(int x, int y, int cx, int cy, int r) {
    int dx = x-cx;
    int dy = y-cy;

    if(dx*dx + dy*dy <= r*r) {
        return true;
    }

    return false;
}

void solve() {
    int cnt = 0;

    for (int i=0; i<n; i++) {
        if (checkInside(x1,y1,v[i].cx,v[i].cy,v[i].r) && !checkInside(x2,y2,v[i].cx,v[i].cy,v[i].r)) {
            cnt++;
        } else if(!checkInside(x1,y1,v[i].cx,v[i].cy,v[i].r) && checkInside(x2,y2,v[i].cx,v[i].cy,v[i].r)) {
            cnt++;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        init();
        input();
        solve();
    }

    return 0;
}