#include <bits/stdc++.h>
using namespace std;
void sort(int a[],int start,int end)
{
    if(start>end)return;
    int left=start;
    int right=end;
    int temp=a[left];
    while(left<right)
    {
        while(left<right&&a[right]>temp)right--;
        a[left]=a[right];
        while(left<right&&a[left]<temp)left++;
        a[right]=a[left];
    }
    a[left]=temp;
    sort(a,start,left-1);
    sort(a,left+1,end);

}
int main()
{
    int a[10]={1,6,2,4,9,7,8,3,5,0};
    sort(a,0,9);
    for (size_t i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
        /* code */
    }    
    return 0;
}