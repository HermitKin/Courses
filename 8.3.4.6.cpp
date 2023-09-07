
#include <bits/stdc++.h>
using namespace std;
void sortColors(int* nums, int numsSize) {
    int red = 0;          // 红色区域的右边界
    int blue = numsSize - 1; // 蓝色区域的左边界
    int i = 0;            // 当前遍历的位置
    while (i <= blue) {
        if (nums[i] == 0) {
            // 如果当前元素是红色（0），将它交换到红色区域，然后红色区域和白色区域都向右扩展
            swap(nums[i], nums[red]);
            i++;
            red++;
        } else if (nums[i] == 2) {
            // 如果当前元素是蓝色（2），将它交换到蓝色区域，然后蓝色区域向左扩展
            swap(nums[i], nums[blue]);
            blue--;
        } else {
            // 如果当前元素是白色（1），不需要交换，只需继续遍历下一个元素
            i++;
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
    sortColors(arr,size);
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }        
    delete[] arr;
    return 0;    
}