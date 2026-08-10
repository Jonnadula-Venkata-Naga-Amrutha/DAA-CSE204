#include<stdio.h>
int main(){
    int arr[10]={10,20,30,40,50,60,70,80,90,100};
    int key,index;
    int found=0;
    printf("enter key element you want to search=");
    scanf("%d",&key);
    int low=0;
    int high=9;
    while(low<=high){
        int mid=(low+high)/2;
        if(key==arr[mid]){
            found=1;
            index=mid;
            break;
        }else if(key<arr[mid]){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    if(found==1){
        printf("element found at position %d\n",index);
    }else{
        printf("element not found\n");
    }
    return 0;
}