#include<stdio.h>
int hash[10];
void intialize(){
    for(int i=0;i<10;i++){
        hash[i]=-1;
    }
}
void insert(int key){
    int index=key%10;
    while(hash[index]!=-1){
        index= (index+1)%10;
    }
    hash[index]=key;
}
void display(){
    for(int i=0;i<10;i++){
        if(hash[i]==-1){
            printf("-1\n");
        }else{
            printf("%d\n",hash[i]);
        }
    }
}
int main(){
    int key,n;
    printf("enter number of elements =");
    scanf("%d",&n);
    printf("enter %d elements to insert into hash table using linear probing\n",n);
    intialize();
    for(int i=0;i<n;i++){
        scanf("%d",&key);
        insert(key);
    }
    display();
    return 0;
}