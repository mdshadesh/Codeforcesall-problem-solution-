#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,i;
    bool eoh = true;
    cin>>n;
    while(n--){
        cin>>i;
        if(i==1){
            eoh = false;
            break;
        }
    }
    if(eoh){
        cout<<"EASY";
    }
    else{
        cout<<"HARD";
    }
 
    return 0;
}