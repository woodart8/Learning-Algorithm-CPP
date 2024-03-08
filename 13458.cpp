#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
vector<int> num;
long long tc, sc;

long long cnt_ans() {
    for(int i=0; i<num.size(); i++) {
        num[i] -= B;
        tc++;
    }
    for(int i=0; i<num.size(); i++) {
        if(num[i] <= 0) continue;
        if(num[i] < C) sc += 1;
        else {
            if(num[i] % C == 0) sc += num[i] / C;
            else sc = sc + (num[i] / C) + 1;
        }
    }

    return tc+sc;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        num.push_back(n);
    }
    cin >> B >> C;

    cout << cnt_ans();
    return 0;
}