#include <bits/stdc++.h>
using namespace std;
void move(int *arr,int size)
{
    int i=0,j=size-1;
    while(i<j)
    {
        while(i<j&&arr[i]%2!=0)i++;
        while(i<j&&arr[j]%2!=0)j--;
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++,j--;
        }
    }
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
    move(arr,size);
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }    
    delete[] arr;
    return 0;
}