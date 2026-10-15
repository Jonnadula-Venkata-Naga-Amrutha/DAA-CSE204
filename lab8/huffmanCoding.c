#include<stdio.h>
#include<stdlib.h>
struct node{
    char ch;
    int freq;
    struct node *left;
    struct node *right;
};
struct node *createnode(char ch,int freq){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->ch=ch;
    newnode->freq=freq;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int findminfreq(struct node *nodes[],int size){
    int min=0;
    for(int i=0;i<size;i++){
        if(nodes[i]->freq<nodes[min]->freq){
            min=i;
        }
    }
    return min;
}
void printcodes(struct node *root,char code[],int top){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        code[top]='\0';
        printf("%c : %s\n",root->ch,code);
        return;
    }
    code[top]='0';
    printcodes(root->left,code,top+1);
    code[top]='1';
    printcodes(root->right,code,top+1);
}
struct node *Buildhuffman(char ch[],int freq[],int n){
    struct node *nodes[200];
    int size=n;
    for(int i=0;i<n;i++){
        nodes[i]=createnode(ch[i],freq[i]);
    }
    while(size>1){
        int minleft=findminfreq(nodes,size);
        struct node *left=nodes[minleft];
        nodes[minleft]=nodes[size-1];
        size--;
        int minright=findminfreq(nodes,size);
        struct node *right=nodes[minright];
        nodes[minright]=nodes[size-1];
        size--;
        struct node *parent=createnode('@',left->freq+right->freq);
        parent->left=left;
        parent->right=right;
        nodes[size]=parent;
        size++;
    }
    return nodes[0];
}
int main(){
    int n;
    char ch[100];
    int freq[100];
    char code[100];
    printf("enter number of characters= ");
    scanf("%d",&n);
    if(n<2 ||n>100){
        printf("invalid number of characters..");
        return 1;
    }
    printf("enter characters=");
    for(int i=0;i<n;i++){
        scanf(" %c",&ch[i]);
    }
    printf("enter frequencies=");
    for(int i=0;i<n;i++){
        scanf("%d",&freq[i]);
    }
    for(int i=0;i<n;i++){
        if(freq[i]<0){
            printf("frequency cannot be negative...");
            return 1;
        }
    }
    struct node *root=Buildhuffman(ch,freq,n);
    printf("HUFFMAN CODES ARE \n");
    printcodes(root,code,0);
    return 0;
}