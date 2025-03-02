#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
int parent[200000];
int rk[200000];
vector<pair<pair<int,int>, int>> v;

int findParent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = findParent(parent[a]);
}

void unionNode(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);

    if (pa != pb) {
        if (rk[pa] > rk[pb]) {
            parent[pb] = pa;
        } else if (rk[pa] < rk[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
            rk[pa]++;
        }
    }
}

bool cmpx(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.second < b.second;
}

bool cmpy(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
    if (a.first.second != b.first.second) return a.first.second < b.first.second;
    return a.second < b.second;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

void input() {
    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({{x,y},i}); // {{x좌표, y좌표}, 인덱스}
    }
}

void solve() {
    vector<int> vx; // x 좌표만 저장
    vector<int> vy; // y 좌표만 저장
    vector<pair<pair<int,int>, int>> t(v.begin(), v.end()); // 원본 복사 배열

    for (int i=0; i<N; i++) {
        parent[i] = i;
    } // 부모 인덱스 자기 자신으로 초기화

    sort(t.begin(), t.end(), cmpx); // x좌표 기준으로 오름차순, 같은 경우 인덱스 작은 순
    for (int i=0; i<N; i++) {
        vx.push_back(t[i].first.first);
    }

    for (int i=0; i<N; i++) {
        int idx = lower_bound(vx.begin(), vx.end(), t[i].first.first)- vx.begin();
        unionNode(t[i].second, t[idx].second);
    } // lower_bound로 vx의 i번째 x좌표값에서 가장 작은 idx 찾고 t[i]와 t[idx]의 v기준 인덱스 union

    sort(t.begin(), t.end(), cmpy); // y좌표 기준으로 오름차순, 같은 경우 인덱스 작은 순
    for (int i=0; i<N; i++) {
        vy.push_back(t[i].first.second);
    }

    for (int i=0; i<N; i++) {
        int idx = lower_bound(vy.begin(), vy.end(), t[i].first.second)- vy.begin();
        unionNode(t[i].second, t[idx].second);
    }  // lower_bound로 vy의 i번째 y좌표값에서 가장 작은 idx 찾고 t[i]와 t[idx]의 v기준 인덱스 union

    unordered_map<int, int> map;

    for (int i=0; i<N; i++) {
        map[findParent(i)]++;
    } // 그룹별 점 개수 저장

    vector<pair<int,int>> group(map.begin(), map.end());
    
     // 그룹이 1개인 경우
    if (group.size() == 1) {
        int k = 1e9 + 1; // 최댓값 + 1
        for (int i=0; i<vy.size()-1; i++) {
            if (vy[i] < vy[i+1]-1) {
                k = vy[i+1]-1;
                break;
            } // 간격이 2이상 차이난다면 그 사이는 비어있으므로 k값 갱신 후 break
        }

        if (k == 1e9 + 1) {
            if (vy[0]-1 > -1e9) {
                k = vy[0]-1;
            } else {
                k = vy[vy.size()-1]+1;
            }
        } // 갱신되지 않았다면 20만개의 점이 모두 1차이로 붙어있다는 것이므로 가장 작은 y좌표가 -10억보다 크면
        // k는 가장 작은 y좌표-1, -10억이라면 가장 큰 y좌표+1 
        
        cout << v[group[0].first].first.first << ' ' << k << '\n';
        return;
    }

    // 그룹이 2개 이상인 경우
    sort(group.begin(), group.end(), cmp); // value 순으로 내림차순 정렬
    
    cout << v[group[0].first].first.first << ' ' << v[group[1].first].first.second << '\n'; // 가장 큰 두 그룹을 연결해주는 점을 출력
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    return 0;
}