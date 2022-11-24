#include <string>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int a, b, flag=0;
	cin>>a>>b;
	for(int i=2;i<b;i++){
		if(b%i==0){
			flag=1;
			break;
		}
		
	}
	if(flag==1){
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
	}
	
}
	
