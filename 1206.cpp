#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, a[105]; 
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		double y;
		cin >> y;
		a[i] = (int)(y * 1000 + 0.01);
	}
	for(int i=1; ; i++){
		bool ok = 1;
        for(int j=0; j<n; j++){
            lint s = 1ll * i * a[j];
            lint e = 1ll * i * a[j] + i - 1;
            if((e / 1000) * 1000 < s){
            	ok = 0;
            	break;
            }
        }
        if(ok){
        	printf("%d\n", i);
        	return 0;
		}
    }
}
