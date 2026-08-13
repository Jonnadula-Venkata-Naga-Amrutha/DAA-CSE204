#include<stdio.h>
int main(){
    int n;
    printf("enter number of elements= ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array= ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int k;
    printf("enter the value of k= ");
    scanf("%d",&k);
    if(k<=0 || k>n){
        printf("invalid input");
        return 0;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("the %dth smallest element is %d",k,arr[k-1]);
    return 0;
}