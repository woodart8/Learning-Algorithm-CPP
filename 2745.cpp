#include <iostream>
#include <vector>

using namespace std;

string s;
int N;

int change2Dec(char c){
    if(c-'0'>=0 && c-'0'<=9) return c-'0';
    else if(c-'A'>=0 && c-'A'<=25) return c-'A'+10;
}

int main() {
    cin >> s >> N;
    int sum = 0;
    for(int i=s.size()-1; i>=0; i--) {
        int temp = change2Dec(s[i]);
        int mul = 1;
        for(int j=1; j<s.size()-i; j++) {
            mul *= N;
        } 
        sum += temp*mul;
    }
    cout << sum << endl;
    return 0;
}