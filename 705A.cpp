#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
        if (n==1)
        {
            cout<<"I hate it ";
        }

        else{
          for(int i=1;i<=n;i++)
          {
          if(i%2!=0)
          {
            cout<<"I hate ";
            if (i==n)
            {
                cout<<" it ";
            }
            else
            {
                cout<<" that ";
            }
           }
           else
           { 
            cout<<"I love ";
            if (i==n)
            {
                cout<<" it ";
            }
            else
            {
                cout<<" that ";
            }

           }
         }
        }
    return 0;
}
	 				  			 		     		 	 	   			