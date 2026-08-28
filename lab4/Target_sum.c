#include<stdio.h>
#define max 10
int hash[10];
void intialise(){
    for(int i=0;i<max;i++){
        hash[i]=-1;
    }
}
void insert(int key){
    int index=key%max;
    while(hash[index]!=-1){
        index=(index+1)%max;
    }
    hash[index]=key;
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
int search(int required){
    int index= (required%max);
    for(int i=0;i<max;i++){
        if(required==hash[(index+i)%max]){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,target,result=0;
    printf("enter n=");
    scanf("%d",&n);
    int a[n];
    intialise();
    printf("enter %d numbers to insert into the hash table of max size 10=",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    printf("enter a target value=");
    scanf("%d",&target);
    for(int i=0;i<n;i++){
        int required=target-a[i];
        if(search(required)){
            result=1;
            break;
        }
    }
    if(result){
        printf("target found\n");
    }else{
        printf("not found\n");
    }
    return 0;
}