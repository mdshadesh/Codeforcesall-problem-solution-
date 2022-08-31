#include<iostream>
using namespace std;

int n, ans = 1;

void f(){
    
    for(int i = 2; i*i<=n; i++)
    {
        while(n%i == 0)
         {
            ans += n;
            n /= i;
         }
    }
}
int main()
{
    cin>>n;
    f();
    if(n > 1)
    {
        ans += n;
    }
    cout<<ans;

    return 0;
}