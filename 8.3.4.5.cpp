#include <bits/stdc++.h>
using namespace std;
void quicksort(int *a,int start,int end)
{
    if(start>=end)return;
    int left=start,right=end;int temp=a[left];
    while(left<right)
    {
        while(left<right&&a[right]>=temp)right--;
        a[left]=a[right];
        while(left<right&&a[left]<=temp)left++;
        a[right]=a[left];

    }
    a[left]=temp;
    quicksort(a,start,left-1);
    quicksort(a,left+1,end);
}
int main()
{
    int size;
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,size-1);
    int k;
    cin>>k;
        for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }    
    cout<<arr[k-1]<<endl; 
    delete[] arr;
    return 0;    
}