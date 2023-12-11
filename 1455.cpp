#include <iostream>

using namespace std;

int main(){
    int n,m;
    int matrix[100][100];
    int total = 0;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==1){
                if(i==0 && j==0){
                    total+=1;
                }

                else if(i==j){
                    total+=4;
                }


            }
        }
    }

    cout<<total<<'\n';
    return 0;
}