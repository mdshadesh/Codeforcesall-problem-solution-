#include <iostream>

using namespace std;

int main()
{
    int n,i,c=0,p,q;
    cin>>n;
    for (i=0;i<n;i++){
        cin>>p>>q;
        if(q-p-2>=0){
            c++;
        }
    }
    cout<<c;
    return 0;
}
