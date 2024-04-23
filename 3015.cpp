#include <iostream>
#include <stack>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  stack<pair<int, int>> S;
  long long ans = 0;
  while (n--) {
    int h;
    cin >> h;
    int cnt = 1;
    while (!S.empty() && S.top().first <= h) {
      ans += S.top().second;
      if (S.top().first == h) cnt += S.top().second;
      S.pop();
    }
    if (!S.empty()) ans++;
    S.push({h, cnt});
  }
  cout << ans;
}