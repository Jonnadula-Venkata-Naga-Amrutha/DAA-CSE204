#include<stdio.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n,W;
    printf("enter number of items=");
    scanf("%d",&n);
    printf("enter knapsack capacity=");
    scanf("%d",&W);
    int wt[n],p[n];
    printf("enter weights of the items=");
    for(int i=0;i<n;i++){
        scanf("%d",&wt[i]);
    }
    printf("enter profits of the items=");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    int v[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0||w==0){
                v[i][w]=0;
            }else if(wt[i-1]<=w){
                v[i][w]=max(v[i-1][w],p[i-1]+v[i-1][w-wt[i-1]]);
            }else{
                v[i][w]=v[i-1][w];
            }
        }
    }
    printf("MAXIMUM PROFIT= %d\n",v[n][W]);
    return 0;
}