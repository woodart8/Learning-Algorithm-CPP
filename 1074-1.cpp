#include <iostream>
#include <vector>

using namespace std;

int N, r, c;

void Z(int rstart, int rend, int cstart, int cend, int num, int minus) {
    //cout << rstart << ' ' << rend << ' ' << cstart << ' ' << cend << ' ' << num << endl;
    if(minus == 0) {
        cout << num-1 << endl;
        return;
    }
    int rmid = (rstart+rend)/2;
    int cmid = (cstart+cend)/2;
    if(r >= rstart-1 && r <= rmid-1) {
        if(c >= cstart-1 && c <= cmid-1) {
            Z(rstart, rmid, cstart, cmid, num-minus*3, minus/4);
        }
        else {
            Z(rstart, rmid, cmid+1, cend, num-minus*2, minus/4);
        }
    }
    else {
        if(c >= cstart-1 && c <= cmid-1) {
            Z(rmid+1, rend, cstart, cmid, num-minus*1, minus/4);
        }
        else {
            Z(rmid+1, rend, cmid+1, cend, num-minus*0, minus/4);
        }
    }
}

int main() {
    cin >> N >> r >> c;
    Z(1,1<<N,1,1<<N,(1<<N)*(1<<N),(1<<N)*(1<<N)/4);
    return 0;
}