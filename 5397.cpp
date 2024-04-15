#include <iostream>
#include <list>

using namespace std;

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  string s;
  cin >> T;

  while(T) {
    list<char> L;
    auto p = L.begin();

    cin >> s;
    for (auto c : s) {
      if (c == '<') {
        if (p != L.begin()) p--;
      }
      else if (c == '>') {
        if (p != L.end()) p++;
      }
      else if (c == '-') {
        if (p != L.begin()) {
          p--;
          p = L.erase(p);
        }
      }
      else L.insert(p, c);      
    }
    for (auto c : L) cout << c;
    cout << '\n';
    T--;
  }

  return 0;
}