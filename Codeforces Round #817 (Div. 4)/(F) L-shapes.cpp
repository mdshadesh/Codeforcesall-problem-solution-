#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 55
#define INF 0x3f3f3f
char c[MAXN][MAXN];
int n, m;
int check(int x, int y){
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
    for(int i = x-1; i <= x+1; i++){
        for(int j = y-1; j <= y+1; j++){
            if(i >= 1 && i <= n && j >= 1 && j <= m && c[i][j] == '*'){
                if(x1 == 0){
                    x1 = i;
                    y1 = j;
                }
                else if(x2 == 0){
                    x2 = i;
                    y2 = j;
                }
                else if(x3 == 0){
                    x3 = i;
                    y3 = j;
                }
                else{
                    return 0;
                }
            }
        }
    }
    if(x1 == 0 || x2 == 0 || x3 == 0){
        return 0;
    }
    if(abs(x1 - x2) >= 2 || abs(x2 - x3) >= 2 || abs(x1 - x3) >=2 || abs(y1 - y2) >= 2 || abs(y2 - y3) >= 2 || abs(y1 - y3) >= 2){
        return 0;
    }
    return 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> c[i][j];
            }
        }
        int flag = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(c[i][j] == '*' && check(i, j) == 0){
                    flag = 0;
                }
            }
        }
        if(flag){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}