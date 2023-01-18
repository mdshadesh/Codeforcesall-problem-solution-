#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int p=0;
    int counter=0;
    int e;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        if(e>0)
        {
            p+=e;

        }else{
            if(p>0)
            {
                p--;
            }else{
                counter++;
            }
        }

    }
    cout<<counter;
    return 0;
}
