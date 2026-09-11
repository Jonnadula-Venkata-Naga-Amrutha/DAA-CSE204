#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int weight;
    int profit;
    double ratio;
};
bool compare(Item a, Item b)
{
    return a.ratio > b.ratio;
}
int main(){
    Item items[]={{10, 60, 0},{20, 100, 0},{30, 120, 0}};
    int n=3;
    int capacity=50;
    for (int i=0; i<n;i++)
    {
        items[i].ratio=(double)items[i].profit / items[i].weight;
    }
    sort(items,items+n,compare);
    double totalProfit=0;
    for(int i=0;i<n;i++)
    {
        if (capacity>=items[i].weight)
        {
            capacity-=items[i].weight;
            totalProfit += items[i].profit;
        }
        else
        {
            totalProfit += items[i].ratio*capacity;
            capacity = 0;
            break;
        }
    }
    cout<<"Maximum Profit="<<totalProfit<<endl;
    return 0;
}