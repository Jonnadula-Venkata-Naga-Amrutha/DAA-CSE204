#include<stdio.h>
void main(){
    int arr[10]={10,20,30,40,50,60,70,80,90,100};
    int key,index;
    int found=0;
    printf("enter key element you want to search=");
    scanf("%d",&key);
    for(int i=0;i<10;i++){
        if(key==arr[i]){
            found=1;
            index=i;
            break;
        }
    }
    if(found==1){
        printf("element found at position %d\n",index);
    }else{
        printf("element not found\n");
    }
}