#include <iostream>

using namespace std;

int n;
int map[2187][2187];
int count[3];
void printPaper(int y, int x, int size){
    int temp = map[y][x];
    bool check = false;
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(temp!=map[i][j]){
                check = true;
                break;
            }
        }
        if(check){
            printPaper(y,x,size/3);
            printPaper(y+size/3,x,size/3);
            printPaper(y+size*2/3,x,size/3); 

            printPaper(y,x+size/3,size/3);
            printPaper(y+size/3,x+size/3,size/3);
            printPaper(y+size*2/3,x+size/3,size/3);            

            printPaper(y,x+size*2/3,size/3);
            printPaper(y+size/3,x+size*2/3,size/3);
            printPaper(y+size*2/3,x+size*2/3,size/3);

            return;
        }
    }
    
    if(temp==-1){ 
        count[0]++;
    }
    else if(temp==0){
        count[1]++;
    }
    else{
        count[2]++;
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }

    printPaper(0,0,n);

    for(int i=0; i<3; i++){
        cout<<count[i]<<'\n';
    }
    
    return 0;
}