#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s = "13579";
int num[] = {2,3,5,7};
int N;

bool sosu(int temp) {
    for(int i=2; i*i <= temp; i++) {
        if(temp % i == 0)
            return false;
    }
    return true;
}

void backtracking(int depth, int temp) {
    if(depth == 1 || sosu(temp)) {
        if(depth == N) {
            cout << temp << endl;
            return;
        }
        for(int i=0; i<5; i++) {
            string str = to_string(temp) + s[i];
            backtracking(depth+1, stoi(str));
        }
    }
}

int main() {
    cin >> N;
    for(int i=0; i<4; i++) {
        int depth = 1;
        backtracking(depth, num[i]);
    }
}