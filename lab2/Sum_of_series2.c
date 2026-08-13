#include<stdio.h>
#include<math.h>
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
    float sum;
    if(r==1){
        sum=a*n;
    }else{
         sum=(a*(pow(r,n)-1))/(r-1);
    }   
    printf("sum of geometric series= %f",sum);
    return 0;
}