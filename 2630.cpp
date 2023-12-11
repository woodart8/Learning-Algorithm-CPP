#include <iostream>

using namespace std;

int n;
int map[129][129];
int blue,white;

void cntPaper(int x, int y, int size){
    int temp = map[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(map[i][j]!=temp){
                cntPaper(x,y,size/2);
                cntPaper(x+size/2,y,size/2);
                cntPaper(x,y+size/2,size/2);
                cntPaper(x+size/2,y+size/2,size/2);
                return;
            }
            else continue;
        }
    }

    if(temp == 1){
        blue++;
    }
    else {
        white++;
    }
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>map[i][j];
        }
    }

    cntPaper(1,1,n);
    cout<<white<<'\n';
    cout<<blue<<'\n';
    return 0;
}