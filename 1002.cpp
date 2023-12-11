#include <iostream>

using namespace std;

int dot(int x1, int y1, int r1, int x2, int y2, int r2){

    if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<(r1-r2)*(r1-r2)){
        return 0;
    }

    else if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1-r2)*(r1-r2)){
        if(r1-r2==0) return -1;
        return 1;
    }

    else if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<(r1+r2)*(r1+r2)){
        return 2;
    }

    else if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1+r2)*(r1+r2)){
        return 1;
    }
    else return 0;
}

int main(){
    int n, x1, y1, r1, x2, y2, r2;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        cout<<dot(x1,y1,r1,x2,y2,r2)<<endl;
    }
    return 0;
}