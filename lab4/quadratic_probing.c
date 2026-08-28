#include<stdio.h>
#define max 10
int hash[max];
void intialize(){
    for(int i=0;i<max;i++){
        hash[i]=-1;
    }
}
void insert(int key){
    int index=key%max;
    int i=0;
    while(hash[(index+i*i)%max]!=-1){
        i++;
    }
    hash[(index+i*i)%max]=key;
}
void display(){
    for(int i=0;i<max;i++){
        if(hash[i]==-1){
            printf("-1\n");
        }else{
            printf("%d\n",hash[i]);
        }
    }
}
int main(){
    int n,key;
    printf("enter n=");
    scanf("%d",&n);
    intialize();
    printf("enter %d numbers=",n);
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key);
    }
    display();
    return 0;
}
