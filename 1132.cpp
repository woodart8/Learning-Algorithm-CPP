#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
long long alpha[10]; // 각 알파벳 별로 자릿수 합 저장 ex) ABC -> alpha[0] = 100, alpha[1] = 10, alpha[2] = 1
bool nz[10]; // 0으로 치환 불가능하면 true, 아니면 false

void input() {
    cin >> N; 
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        int j = s.size()-1;
        for (int i = 0; i<=j; i++) {
            if (i == 0) nz[s[i]-'A'] = true; // 첫번째로 나오는 알파벳은 0이 될 수 없으므로 true 처리
            alpha[s[i]-'A'] += pow(10, j-i);
        }
    }
}

void solve() {
    long long minimum = __LONG_LONG_MAX__; // 0으로 치환가능한 알파벳의 자릿수 합 최소값 저장하는 변수
    int minI = -1; // 그 알파벳의 인덱스

    for (int i=0; i<10; i++) {
        if (nz[i] == false && minimum > alpha[i]) {
            minimum = alpha[i];
            minI = i;
        }
    }

    // 인덱스가 갱신된 적이 있다면 그 인덱스의 자릿수 합을 0으로 변환
    if (minI > -1) alpha[minI] = 0;

    // 내림차순 정렬
    sort(alpha, alpha+10, greater<long long>());

    long long sum = 0;
    int last = 9; // 마지막으로 사용될 숫자
    for (int i=0; i<10; i++) {
        if (alpha[i] == 0) {
            last = 9-i; 
            break;
        }
        sum += alpha[i] * (9-i);
    }

    // last가 갱신되었다면 아까 구한 minimum에 last를 곱하여 sum에 더함
    if (last < 9) {
        sum += minimum * last;
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}