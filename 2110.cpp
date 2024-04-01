#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> router;

int find_max_dist(int n, int c){
    int l_dist = 1;  
    int r_dist = router[n-1]-router[0]; 

    int result_dist=0;

    while(l_dist<=r_dist){
        int install_router = 1;
        int mid_dist = (l_dist+r_dist)/2;   
        int start = router[0];

        for (int i=1; i<n; ++i){
            int end = router[i];
            if (end - start >= mid_dist){
                install_router += 1;
                start = end;
            }
        }

        if (install_router >= c){
            result_dist = max(result_dist, mid_dist);
            l_dist = mid_dist + 1;
        }
        else{
            r_dist = mid_dist - 1;
        }
    }
    return result_dist;
}

int main(){
    int n, c;
    cin >> n >> c;

    int loc;
    for (int i=0; i<n; ++i){
        cin >> loc;
        router.push_back(loc);
    }

    sort(router.begin(), router.end());

    cout << find_max_dist(n, c);
    return 0;
}