#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int r,c,k;
int arr[101][101];
int cnt[101];
vector<pair<int,int>> v;
int rowsize = 3, colsize = 3;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.second < b.second) {
        return true;
    }
    else if(a.second == b.second) {
        if(a.first < b.first) return true;
        else return false;
    }
    else return false;
}

int R(int idx) {
    memset(cnt, 0, sizeof(cnt));
    v.clear();
    for(int i=1; i<=colsize; i++) {
        cnt[arr[idx][i]]++;
    }
    for(int i=1; i<=100; i++) {
        if(cnt[i] > 0) {
            v.push_back({i,cnt[i]});
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) {
        if(i*2+1 < 100)
            arr[idx][i*2+1] = v[i].first;
        if(i*2+2 <= 100)
            arr[idx][i*2+2] = v[i].second; 
    }
    for(int i=v.size()*2+1; i<=100; i++) {
        arr[idx][i] = 0;
    }

    return v.size()*2;
}

int C(int idx) {
    memset(cnt, 0, sizeof(cnt));
    v.clear();
    for(int i=1; i<=rowsize; i++) {
        cnt[arr[i][idx]]++;
    }
    for(int i=1; i<=100; i++) {
        if(cnt[i] > 0) {
            v.push_back({i,cnt[i]});
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) {
        if(i*2+1 < 100)
            arr[i*2+1][idx] = v[i].first;
        if(i*2+2 <= 100)
            arr[i*2+2][idx] = v[i].second; 
    }
    for(int i=v.size()*2+1; i<=100; i++) {
        arr[i][idx] = 0;
    }

    return v.size()*2;
}

int simulation() {
    if(arr[r][c] == k) return 0;
    for(int t=1; t<=100; t++) {
        int num = -1;
        if(rowsize >= colsize) {
            for(int i=1; i<=rowsize; i++) {
                num = max(num, R(i));
            }
            colsize = num;
        }
        else {
            for(int i=1; i<=colsize; i++) {
                num = max(num, C(i));
            }
            rowsize = num;
        }

        if(arr[r][c] == k) return t;
    }
    return -1;
}

int main() {
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }

    cout << simulation() << endl;
}