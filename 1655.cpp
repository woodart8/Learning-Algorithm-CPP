#include <iostream>
#include <queue>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq1; // 내림차순 (top이 항상 중간값 중 작은 값을 가리키게)
    priority_queue<int, vector<int>, greater<int>> pq2; // 오름차순 (top이 중간값 중 큰 값 또는 중간값보다 크거나 같은 값을 가리키게)

    cin >> N;

    for (int i=1; i<=N; i++) {
        int num;
        cin >> num;

        if (i%2) {
            // i가 홀수일 때는 num을 pq1에다 넣는게 디폴트
            // 다만 pq2가 비어있지 않고 pq2의 top이 num보다 작으면 pq2.top을 대신 pq1에 넣고 num은 pq2에 넣는다.
            if (pq1.empty() || (!pq2.empty() && pq2.top() >= num)) {
                pq1.push(num);
            } else {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
        } else {
            // i가 짝수일 때는 num을 pq2에다 넣는게 디폴트 (숫자가 두 pq에 반씩 들어가도록)
            // 다만 pq1가 비어있지 않고 pq1의 top이 num보다 크면 pq1.top을 대신 pq2에 넣고 num은 pq1에 넣는다.
            if (!pq1.empty() && pq1.top() > num) {
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            } else {
                pq2.push(num);
            }
        }

        // pq1의 top은 항상 pq1와 pq2의 모든 수의 중간값 중 작은 값을 가리킨다.
        cout << pq1.top() << '\n';
    } 
    // 시간복잡도는 O(NlogN)

    return 0;
}