#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<string> vs;
vector<string> words;

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

int KMP(string parent, string pattern) {
    int ret = 0;
    int parentSize = parent.size();
    int patternSize = pattern.size();
    vector<int> table = makeTable(pattern);
    int j = 0;
    for(int i = 0; i < parentSize -1; i++) {
        while(j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }
        if(parent[i] == pattern[j]) {
            if(j == patternSize - 1) {
                ret++;
                j = table[j];
            }
            else j++;
        }
    }
    return ret;
}

void permutation(int depth) {
    if(depth == N) {
        string s;
        for(int i = 0; i < N; i++) {
            s.append(words[i]);
        }
        vs.push_back(s);
        return;
    }

    for(int i = depth; i < N; i++) {
        swap(words[depth], words[i]);
        permutation(depth + 1);
        swap(words[depth], words[i]);
    }
}

int countMagic() {
    int count = 0;
    for(int i = 0; i < vs.size(); i++) {
        if(KMP(vs[i]+vs[i],vs[i]) == K) count++;
    }
    return count*N;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }
    cin >> K;

    permutation(1);
    cout << countMagic();

    return 0;
}