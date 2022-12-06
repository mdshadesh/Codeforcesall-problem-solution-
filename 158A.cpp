#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,i,count=0;
    int arr[100];
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    for(i=1; i<=n; i++){
        if(arr[i]==arr[k] || arr[i]>arr[k]){
            if(arr[i]>0){
            count++;
            }
        }
    }
    printf("%d\n",count);
   return 0;
}
