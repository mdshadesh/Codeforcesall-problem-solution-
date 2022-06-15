#include <bits/stdc++.h> 

using namespace std;

int main() {
  
    int T;
    scanf("%d", &T);
    int i=0;
    while (i<T) {
        int a, b;
        scanf("%d %d", &a, &b);

        int ans = a + b;
        printf("%d\n", ans);
        
        i++;
    }

    return 0;
}