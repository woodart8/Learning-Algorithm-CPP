#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> p;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x,y});
    }

    sort(p.begin(), p.end(), compare);

    int cnt = 0;
    int validX[80001] = {0};
    int validY[80001] = {0};

    for (int i=0; i<p.size(); i++) {
        if (validX[p[i].first+40000] < 2 || validY[p[i].second+40000] < 2) {
            
            validX[p[i].first+40000]++;
            validY[p[i].second+40000]++;
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}