#include <iostream>

using namespace std;

int N,K;
int student[7][2];
int room;

int main() {
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int gender, grade;
        cin >> gender >> grade;
        student[grade][gender]++;
    }

    for(int i=1; i<=6; i++) {
        room += (student[i][0]/K + student[i][1]/K);
        if(student[i][0]%K > 0) room++;
        if(student[i][1]%K > 0) room++; 
    }

    cout << room << endl;
    return 0;
}