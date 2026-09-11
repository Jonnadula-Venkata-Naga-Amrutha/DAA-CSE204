#include<iostream>
using namespace std;
struct result{
    int min;
    int max;
};
result findMinMax(int arr[],int low,int high){
    if(low==high){
        return {arr[low],arr[high]};
    }
    if(high==low+1){
        if(arr[low]<arr[high]){
            return {arr[low],arr[high]};
        }else{
            return {arr[high],arr[low]};
        }
    }
    int mid=(low+high)/2;
    result left=findMinMax(arr,low,mid);
    result right=findMinMax(arr,mid+1,high);
    result answer;
    answer.min=(left.min<right.min)?left.min:right.min;
    answer.max=(left.max>right.max)?left.max:right.max;
    return answer;
}
int main(){
    int arr[5]={1,2,3,4,5};
    result ans=findMinMax(arr,0,4);
    cout<<"Minimum element is: "<<ans.min<<endl;
    cout<<"Maximum element is: "<<ans.max<<endl;    
    return 0;
}