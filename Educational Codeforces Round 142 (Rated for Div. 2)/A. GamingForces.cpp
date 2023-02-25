#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,m,temp,count1=0;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> m;
        count1=0;
        
        for (int j=0; j<m; j++) {
            cin >> temp;
            
            if (temp == 1) {
                count1 ++;
            }
        }
        
        cout << m - count1 + (count1+1)/2 << "\n";
    }
}