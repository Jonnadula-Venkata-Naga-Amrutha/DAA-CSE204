#include<stdio.h>
int main(){
    int a;
    printf("enter first coeffiecient= ");
    scanf("%d",&a);
    int r;
    printf("enter common ratio= ");
    scanf("%d",&r);
    int n;
    printf("enter number of terms= ");
    scanf("%d",&n);
    float sum = 0;
    for(int i=0; i<n; i++){
        sum=sum+a;
        a=a*r;
    }
    printf("sum of geometric series= %.2f",sum);
    return 0;
}