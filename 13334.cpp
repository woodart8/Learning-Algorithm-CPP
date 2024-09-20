#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Line {

    public:
        int left;
        int right;

        Line(int l, int r) {
            left = l;
            right = r;
        }

        bool operator<(const Line& other) const {
            return right < other.right;
        }

};

int n;
int d;
int ans = 0;
vector<Line> lines;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        lines.push_back(Line(l, r));
    }
    sort(lines.begin(), lines.end());

    cin >> d;
    for(Line line : lines) {
        pq.push(line.left);
        while(!pq.empty() && pq.top() < line.right - d)
            pq.pop();
        ans = max(ans, (int)pq.size());
    }

    cout << ans << '\n';
    return 0;
}