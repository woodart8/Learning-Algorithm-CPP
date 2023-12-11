#include <iostream>
#include <vector>

using namespace std;

int count,n,m;

string makePattern(int n){
    string s = "I";
    for(int i=0; i<n; i++){
        s+="OI";
    }

    return s;
}

vector<int> makeTable(string pattern){
    int patternSize =pattern.size();
    vector<int> table(patternSize,0);
    int j=0;
    for(int i=1; i<patternSize; i++){
        while(j>0 && pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i]==pattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern){
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for(int i=0; i<parentSize; i++){
        while(j>0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == patternSize - 1){
                count++;
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
}

int main(){
    string s;
    cin>>n>>m>>s;
    KMP(s, makePattern(n));

    cout<<count<<'\n';
    return 0;
}