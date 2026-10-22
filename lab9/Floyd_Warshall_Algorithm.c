#include<stdio.h>
#define INF 999999
int main(){
    int n;
    printf("enter number of vertices=");
    scanf("%d",&n);
    int a[10][10];
    printf("ENTER THE ADJACENCY MATRIX (note:enter 999999 for infinity) =\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][k]!=INF && a[k][j]!=INF && a[i][k]+a[k][j]<a[i][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    printf("The shortest path matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==999999){
                printf("INF ");
            }else{
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
