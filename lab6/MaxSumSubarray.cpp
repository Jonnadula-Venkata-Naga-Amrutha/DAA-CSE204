#include<iostream>
#include<algorithm>
using namespace std;
struct result{
    int sum;
    int start;
    int end;
};
result maxcrossingsubarray(int arr[],int low,int mid,int high){
    int sum=0;
    int leftsum=arr[mid];
    int rightsum=arr[mid+1];
    int leftindex=mid;
    int rightindex=mid+1;
    for(int i=mid;i>=low;i--){
        sum=sum+arr[i];
        if(sum>leftsum){
            leftsum=sum;
            leftindex=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum=sum+arr[i];
        if(sum>rightsum){
            rightsum=sum;
            rightindex=i;
        }
    }
    return {leftsum+rightsum,leftindex,rightindex};
}
result maxsubarray(int arr[],int low,int high){
    if(low==high){
        return {arr[low],low,high};
    }
    int mid=(low+high)/2;
    result left=maxsubarray(arr,low,mid);
    result right=maxsubarray(arr,mid+1,high);
    result cross=maxcrossingsubarray(arr,low,mid,high);
    if(left.sum>=right.sum && left.sum>=cross.sum){
        return left;
    }
    if(right.sum>=left.sum && right.sum>=cross.sum){
        return right;
    }
    return cross;
}
int main(){
    int arr[8]={2,-4,3,5,-2,6,-7,4};
    result ans=maxsubarray(arr,0,7);
    cout<<"Maximum sum= "<<ans.sum<<endl;
    cout<<"max subarray=";
    for(int i=ans.start;i<=ans.end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}