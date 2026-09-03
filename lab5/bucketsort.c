#include<stdio.h>
void bucketsort(int a[],int n){
    int bucket[10][100];
    int count[10];
    int pos;
    for(int i=0;i<10;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        pos=a[i]/10;
        bucket[pos][count[pos]]=a[i];
        count[pos]++;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i]-1;j++){
            for(int k=j+1;k<count[i];k++){
                if(bucket[i][j]>bucket[i][k]){
                    int temp=bucket[i][j];
                    bucket[i][j]=bucket[i][k];
                    bucket[i][k]=temp;
                }
            }
        }
    }
    int k=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i];j++){
            a[k]=bucket[i][j];
            k++;
        }
    }
}
int main(){
    int arr[5]={15,48,66,78,2};
    printf("BEFORE SORTING=\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    bucketsort(arr,5);
    printf("\nAFTER SORTING=\n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}