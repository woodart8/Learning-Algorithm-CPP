#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int ans;
vector<int> v;

void backtracking(int index, int temp) {
    if(temp == S) {
        ans++;
    }
    for(int i=index+1; i<v.size(); i++) {
            backtracking(i, temp+v[i]);
    }
}

int main() {
    cin >> N >> S;
    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        v.push_back(num);
    }

    for(int i=0; i<v.size(); i++) {
        backtracking(i, v[i]);
    }

    cout << ans << endl;
}