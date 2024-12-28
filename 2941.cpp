#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<string> alphas = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string w;
  cin >> w;
  for(auto alpha : alphas){
    while(true){
      int pos = w.find(alpha);
      if(pos == string::npos) break;
      w.replace(pos, alpha.size(), "1");
    }
  }
  cout << w.size();
}