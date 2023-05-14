#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    //int c=0;
    for(int i=1; ;i++)
    {
        int b=5*i;
        if(b>=a)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;

}
