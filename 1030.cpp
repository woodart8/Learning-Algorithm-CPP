#include "bits/stdc++.h"

using namespace std;

bool func(int y, int x, int s, int n, int k)
{
    while (s > 0)
    {
        int whiteLength = pow(n, s);                      // 현재 스케일의 전체 크기
        int blackLength = whiteLength / n * k;            // 현재 스케일의 검은색 부분 크기
        int blackStart = (whiteLength - blackLength) / 2; // 검은색 시작 좌표
        int blackEnd = blackStart + blackLength;          // 검은색 끝 좌표

        // 현재 레벨의 검은색 영역에 포함되는지 체크
        if (y >= blackStart && y < blackEnd && x >= blackStart && x < blackEnd)
        {
            return true;
        }

        // 좌표를 축소시켜 하위 레벨로 이동
        y %= whiteLength / n;
        x %= whiteLength / n;

        s--;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, n, k, r1, r2, c1, c2;
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            if (func(i, j, s, n, k))
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        cout << "\n";
    }

    return 0;
}