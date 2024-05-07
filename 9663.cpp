#include <iostream>
#include <vector>

using namespace std;

int N;
bool v45d[31];
bool vm45d[31];
bool vc[16];
int ans;

void BT(int row, int cnt) {
    if(cnt == N) {
        ans++;
        return;
    }

    for(int col=1; col<=N; col++) {
        if(!vc[col] && !v45d[row+col] && !vm45d[N-row+col]) {
            vc[col] = true;
            v45d[row+col] = true;
            vm45d[N-row+col] = true;
            BT(row+1, cnt+1);
            vc[col] = false;
            v45d[row+col] = false;
            vm45d[N-row+col] = false;
        }
    }
}

int main() {
    cin >> N;

    BT(1,0);
    cout << ans << '\n';
    return 0;
}