#include <bits/stdc++.h>
using namespace std;
void DoubleBubble(int *a,int size)
{
    int flag=size/2;
    //int icount=0;
    //int jcount=0;
    while(flag>0)
    {
        for(int i=0;i<size-1;i++)
        {
            for(int j=size-1;j>i;j--)
            {
                if(a[j]<a[j-1])
                {
                    int temp=a[j];
                    a[j]=a[j-1];
                    a[j-1]=temp;
                }
            }
            flag--;
            break;
        }
        for(int i=size-1;i>=0;i--)
        {
            for(int j=0;j<size-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;                    
                }
            }
            flag--;
            break;
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
    DoubleBubble(arr,size);
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }    
    delete[] arr;
    return 0;
}
//  int left = 0;
//     int right = size - 1;
//     int swapped = 1; // Flag to check if any swap is made in a pass

//     while (left < right && swapped) {
//         swapped = 0;

//         // Left to right pass (bubble larger elements to the right)
//         for (int i = left; i < right; i++) {
//             if (a[i] > a[i + 1]) {
//                 int temp = a[i];
//                 a[i] = a[i + 1];
//                 a[i + 1] = temp;
//                 swapped = 1;
//             }
//         }
//         right--; // Reduce the right boundary

//         // Right to left pass (bubble smaller elements to the left)
//         for (int i = right; i > left; i--) {
//             if (a[i] < a[i - 1]) {
//                 int temp = a[i];
//                 a[i] = a[i - 1];
//                 a[i - 1] = temp;
//                 swapped = 1;
//             }
//         }
//         left++; // Increase the left boundary
//     } 