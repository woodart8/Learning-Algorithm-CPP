#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum;
int N;
string s = "";

char changeNum2Str(int num) {
    if(num >= 10 && num <=35) {
        return num-10+'A';
    }
    else if(num < 10 && num >= 0) {
        return num+'0';
    }
}

int main() {
    cin >> sum >> N;

    while(sum>0) {
        char c = changeNum2Str(sum%N);
        s = s+c;
        sum /= N;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}