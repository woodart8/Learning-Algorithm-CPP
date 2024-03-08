#include <iostream>
#include <vector>

using namespace std;

int map[6][6];

int main() {
    for(int t=0; t<3; t++) {
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
                cin >> map[i][j];
            }
        }

        int min_x=1e9, max_x=-1, min_y=1e9, max_y=-1;
        for(int i=0; i<6; i++) {
            for(int j=0; j<6; j++) {
                if(map[i][j] == 1) {
                    min_x = min(min_x, i);
                    max_x = max(max_x, i);
                    min_y = min(min_y, j);
                    max_y = max(max_y, j);
                }
            }
        }

        if(((max_x - min_x) == 2 && (max_y - min_y) == 3) || ((max_x - min_x) == 3 && (max_y - min_y) == 2)) {
            bool check = true;
            if(map[min_x+1][min_y+1] == 0 || map[max_x-1][max_y-1] == 0) check = false;
            if(!check)
                cout << "no" << '\n';
            else cout << "yes" << '\n';
        }
        else if(((max_x - min_x) == 1 && (max_y - min_y) == 4) || ((max_x - min_x) == 4 && (max_y - min_y) == 1)) {
            if((map[min_x][min_y] == 1 && map[max_x][max_y] == 1)) {
                if((max_x - min_x) > (max_y - min_y)) {
                    if(map[min_x+2][min_y] == 1 && map[max_x-2][max_y] == 1) cout << "yes" << '\n';
                    else cout << "no" << '\n';
                }
                else {
                    if(map[min_x][min_y+2] == 1 && map[max_x][max_y-2] == 1) cout << "yes" << '\n';
                    else cout << "no" << '\n';
                }
            }
            else if((map[min_x+1][min_y] == 1 && map[max_x-1][max_y] == 1) || (map[min_x][min_y+1] == 1 && map[max_x][max_y-1] == 1))
                cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
        else cout << "no" << '\n';
    }
    return 0;
}