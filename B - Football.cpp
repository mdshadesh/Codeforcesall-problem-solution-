#include <iostream>
#include <vector>

using namespace std;
int count1[100005];
int count2[100005];
vector<int> v;

int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
    int x,y;
    cin>>x>>y;
    count1[x]++;
    v.push_back(y);
   }
   for(int i=0;i<n;i++)
   {
    int val=count1[v[i]];
    int sum=(n-1)+val;
    int left=(2*(n-1))-sum;

    cout<<sum<<" "<<left<<endl;
   }
    return 0;
}