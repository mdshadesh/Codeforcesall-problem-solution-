#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
struct Point
{
    long long  x,y;
    Point( LL  x = 0,LL  y = 0):x(x),y(y) {}
};
bool IsOnLine(Point a,Point b,Point c)
{
    return (b.x-a.x)*(c.y-a.y) == (b.y-a.y)*(c.x-a.x);
}
const int maxn  = 1e5+100;
Point p[maxn];
int n;
bool JJ(vector<int> vec)
{
    if(vec.size() <= 2)
        return true;
    Point a,b;
    a = p[vec[0]];
    b = p[vec[1]];

    for(int i = 2;i < vec.size(); ++i)
    {
       if(!IsOnLine(a,b,p[vec[i]]))
            return false;
    }
    return true;
}
bool judge(int a,int b)
{
    vector<int> vec;
    for(int i = 0;i < n; ++i)
    {
        if(i == a||i == b)
            continue;
        if(!IsOnLine(p[a],p[b],p[i]))
            vec.push_back(i);
    }
    return JJ(vec);
}
int main(void)
{

    cin>>n;
    for(int i = 0;i < n; ++i)
        cin>>p[i].x>>p[i].y;
    bool t = (judge(0,1)||judge(0,2)||judge(1,2));
    if(t)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}