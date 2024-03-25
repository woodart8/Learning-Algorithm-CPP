#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6; //모듈러 연산 상수
int dp[5001]={0,};
int solution(string code, int n ) {
	if(code[0]=='0') return 0;
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=n;i++){
		if(code[i-1]!='0') dp[i]=dp[i-1]%MOD;
		
		int tmp=(code[i-2]-'0')*10+(code[i-1]-'0');
		if(tmp>=10&&tmp<=26)
			dp[i]=(dp[i]+dp[i-2])%MOD;
	}

    return dp[n];
}

int main() {
    string str;  
    cin >> str;   
    int answer = solution(str, str.length());  
    cout << answer;
    return 0;
}