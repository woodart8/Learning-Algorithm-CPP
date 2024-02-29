#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for(int i = 1; i < patternSize; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

int main() {
    vector<int> ans;
    while(1) {
        string s;
        cin >> s;
        if(s.compare(".") == 0) break;

        vector<int> table = makeTable(s);
        int strSize = s.size();
        int div =  strSize - table[table.size() - 1];
        int share = strSize / div;
        int remainder = strSize % div;

        if(remainder == 0)
            ans.push_back(share);
        else ans.push_back(1);
    }
    
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}