#include <iostream>

using namespace std;

int map[1001][1001];
int n,m;

int cntL(int y, int x){
    int mode[8]={0,};
    int max_num = 0;

    if(x<=m-1 && y<=n-2){
        mode[0] = map[y][x]+map[y+1][x]+map[y+2][x]+map[y+2][x+1];
        //|_
        mode[1] = map[y][x]+map[y][x+1]+map[y+1][x+1]+map[y+2][x+1];
        //_
        // |
    }
    if(x>=2 && y<=n-2){
        mode[2] = map[y][x]+map[y+1][x]+map[y+2][x]+map[y+2][x-1];
        //_|
        mode[3] = map[y][x]+map[y][x-1]+map[y+1][x-1]+map[y+2][x-1];
        // _
        //|
    }
    if(x<=m-2 && y<=n-1){
        mode[4] = map[y][x]+map[y+1][x]+map[y+1][x+1]+map[y+1][x+2];
        //ㅣ___
        mode[5] = map[y][x]+map[y][x+1]+map[y][x+2]+map[y+1][x+2];
        //___
        //   ㅣ
    }
    if(x>=3 && y<=n-1){
        mode[6] = map[y][x]+map[y+1][x]+map[y+1][x-1]+map[y+1][x-2];
        //___ㅣ
        mode[7] = map[y][x]+map[y][x-1]+map[y][x-2]+map[y+1][x-2];
        //  ___
        //ㅣ
    }

    for(int i=0; i<8; i++){
        if(mode[i]>max_num){
            max_num = mode[i];
        }
    }
    
    return max_num;
}

int cntS(int y, int x){
    int mode[4]={0,};
    int max_num = 0;

    if(x<=m-1 && y<=n-2){
        mode[0] = map[y][x]+map[y+1][x]+map[y+1][x+1]+map[y+2][x+1];
    }
    if(x>=2 && y<=n-2){
        mode[1] = map[y][x]+map[y+1][x]+map[y+1][x-1]+map[y+2][x-1];
    }
    if(x<=m-2 && y<=n-1){
        mode[2] = map[y][x]+map[y][x+1]+map[y+1][x+1]+map[y+1][x+2];
    }
    if(x>=3 && y<=n-1){
        mode[3] = map[y][x]+map[y][x-1]+map[y+1][x-1]+map[y+1][x-2];
    }

    for(int i=0; i<4; i++){
        if(mode[i]>max_num){
            max_num = mode[i];
        }
    }
    
    return max_num;
}

int cntT(int y, int x){
    int mode[4]={0,};
    int max_num = 0;

    if(x<=m-1 && y<=n-2){
        mode[0] = map[y][x]+map[y+1][x]+map[y+1][x+1]+map[y+2][x];
    }
    if(x>=2 && y<=n-2){
        mode[1] = map[y][x]+map[y+1][x]+map[y+1][x-1]+map[y+2][x];
    }
    if(x<=m-2 && y<=n-1){
        mode[2] = map[y][x]+map[y][x+1]+map[y+1][x+1]+map[y][x+2];
    }
    if(x<=m-2 && y>=2){
        mode[3] = map[y][x]+map[y][x+1]+map[y-1][x+1]+map[y][x+2];
    }

    for(int i=0; i<4; i++){
        if(mode[i]>max_num){
            max_num = mode[i];
        }
    }
    
    return max_num;
}

int cntI(int y, int x){
    int mode[2]={0,};
    int max_num = 0;

    if(x<=m-3){
        mode[0] = map[y][x]+map[y][x+1]+map[y][x+2]+map[y][x+3];
    }
    if(y<=n-3){
        mode[1] = map[y][x]+map[y+1][x]+map[y+2][x]+map[y+3][x];
    }

    for(int i=0; i<2; i++){
        if(mode[i]>max_num){
            max_num = mode[i];
        }
    }
    
    return max_num;
}

int cntO(int y, int x){
    int mode=0;
    if(x<=m-1&&y<=n-1){
        mode = map[y][x]+map[y][x+1]+map[y+1][x]+map[y+1][x+1];
    }
  
    return mode;
}

int main(){
    int max_num=0;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int ci = cntI(i,j);
            int co = cntO(i,j);
            int ct = cntT(i,j);
            int cs = cntS(i,j);
            int cl = cntL(i,j);
            if(max_num<ci){
                max_num=ci;
            }
            if(max_num<co){
                max_num=co;
            }
            if(max_num<ct){
                max_num=ct;
            }
            if(max_num<cs){
                max_num=cs;
            } 
            if(max_num<cl){
                max_num=cl;
            }                                   
        }
    }

    cout<<max_num<<'\n';
    return 0;
}