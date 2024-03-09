#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
 
int N;
int L;
int map[100][100];
bool check[100];
vector<int> v;
 
bool IsPossible()
{
    // 초기화
    memset(check, false, sizeof(check));
 
    for (int i = 0; i < N - 1; i++)
    {
        int cur = v[i];
        int next = v[i + 1];
        int sub = v[i] - v[i + 1];
        // 같을 때(평지)
        if (sub == 0)
            continue;
        // 왼쪽 경사로, 내리막길
        else if (sub == 1)
        {
            for (int j = i + 1; j <= i + L; j++)
            {
                if (j >= N || check[j] || v[j] != next)
                    return false;
                else
                {
                    check[j] = true;
                }
            }
        }
        // 오른쪽 경사로, 오르막길
        else if (sub == -1)
        {
            for (int j = i; j > i - L; j--)
            {
                if (j < 0 || check[j] || v[j] != cur)
                    return false;
                else
                {
                    check[j] = true;
                }
            }
        }
        // 경사로 만들어지지 못함
        else
            return false;
    }
 
    return true;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> N >> L;
 
    int result = 0;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    // 행 검사
    for (int i = 0; i < N; i++)
    {
        v.clear();
 
        for (int j = 0; j < N; j++)
        {
            v.push_back(map[i][j]);
        }
 
        if (IsPossible())
        {
            result += 1;
        }
    }
    // 열 검사
    for (int i = 0; i < N; i++)
    {
        v.clear();
 
        for (int j = 0; j < N; j++)
        {
            v.push_back(map[j][i]);
        }
 
        if (IsPossible())
        {
            result += 1;
        }
    }
 
    cout << result;
    return 0;
}