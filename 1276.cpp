#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Platform {
public:
    int y, x1, x2;

    Platform(int y, int x1, int x2) {
        this->y = y;
        this->x1 = x1;
        this->x2 = x2;
    }

    bool operator<(const Platform& other) const {
        return y > other.y; // 높은 y부터 처리하기 위해 내림차순 정렬
    }
};

int N;
vector<Platform> v;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        v.push_back(Platform(y, x1, x2));
    }
}

void solve() {
    sort(v.begin(), v.end()); // y 기준 내림차순 정렬

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int leftSupport = 0, rightSupport = 0;

        // 왼쪽 끝(x1)에 대해 겹침 확인
        for (int j = i+1; j < N; j++) {
            if (v[i].x1 >= v[j].x1 && v[i].x1 < v[j].x2) {
                leftSupport = v[j].y; // 지지하는 높이 찾기
                break;
            }
        }

        // 오른쪽 끝(x2)에 대해 겹침 확인
        for (int j = i+1; j < N; j++) {
            if (v[i].x2 - 1 >= v[j].x1 && v[i].x2 - 1 < v[j].x2) {
                rightSupport = v[j].y; // 지지하는 높이 찾기
                break;
            }
        }

        // 노출된 높이 계산
        ans += (v[i].y - leftSupport) + (v[i].y - rightSupport);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
    return 0;
}
