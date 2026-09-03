#include<stdio.h>
void merge(int a[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[100];
    while(i<=mid && j<=ub){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=ub){
        b[k++]=a[j++];
    }
    for(int i=lb;i<=ub;i++){
        a[i]=b[i];
    }
}
void mergesort(int a[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid-1);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int main(){
    int arr[5]={23,45,88,1,2};
    printf("BEFORE SORTING=\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    mergesort(arr,0,4);
    printf("\nAFTER SORTING=\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}



