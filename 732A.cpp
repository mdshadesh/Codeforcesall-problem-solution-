#include<iostream>
using namespace std;
int k,r;
int main()
{
    cin>>k>>r;
    for(int i=1;;i++)
    {
        if((i*k)%10==0||(i*k-r)%10==0)
        {
            cout<<i;
            return 0;
            
        }
    }
}
