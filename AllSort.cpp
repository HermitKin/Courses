#include <bits/stdc++.h>
using namespace std;
//DiectInsertSort
void DirectInsertSort(int *arr,int size)
{
    for(int i=1;i<size;i++)//从第二个开始循环，到末尾结束
    {
        int j=i,temp=arr[i];//j等于i，准备向前循环遍历，设定临时值保存当前位置数据
        while(j>0&&arr[j-1]>temp)//只要j还大于0（没遍历完数组）且前一个值小于临时值
        {
            arr[j]=arr[j-1];//前面的元素后移一位，腾出对应位置
            j--;//循环减少
        }
        arr[j]=temp;//最终停在什么位置上，然后把临时保存的数据重新插入到正确位置上
    }
}
//折半插入法
void DIS_with_BinarySearch(int *arr,int size)
{
    for(int i=1;i<size;i++)//外部循环，从第二个开始比较
    {
        int low=0;
        int high=i-1;//每次排序都从待排的前一个元素开始（即前面有序序列的最后一个）
        int temp=arr[i];
        int mid;
        while(low<=high)//当高位大于等于低位时
        {
            mid=(low+high)/2;//折半
            if(temp<arr[mid])high=mid-1;//如果临时元素小于中间值，让high跑到mid的左边
            else low=mid+1;//否则跑到mid的右边
        }
        for(int j=i;j>=low;j--)//从挪出临时值的那位置开始，直到low待插入位置后面的一个元素
        {
            arr[j]=arr[j-1];//后移操作
        }
        arr[low]=temp;//把值插入到当前位置         
    }
    
}
//希尔排序
void ShellSort(int *arr,int size)
{
    int gap=size/2;
    while(gap>=1)
    {
        for(int i=gap;i<size;i++)
        {
            int j=i;
            int temp=arr[i];
            while(j>=gap&&arr[j-gap]>temp)
            {
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j] = temp;
        }
        gap/=2;
    }
}
//冒泡排序
void BubbleSort(int *arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=size-1;j>i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
//快速排序
void QuickSort(int *arr,int start,int end)
{
 if(start >= end) return;    //范围不可能无限制的划分下去，要是范围划得都没了，肯定要结束了
    int left = start, right = end, pivot = arr[left];   //这里我们定义两个指向左右两个端点的指针，以及取出基准
    while (left < right) {     //只要两个指针没相遇，就一直循环进行下面的操作
        while (left < right && arr[right] >= pivot) right--;   //从右向左看，直到遇到比基准小的
        arr[left] = arr[right];    //遇到比基准小的，就丢到左边去
        while (left < right && arr[left] <= pivot) left++;   //从左往右看，直到遇到比基准大的
        arr[right] = arr[left];    //遇到比基准大的，就丢到右边去
    }
    arr[left] = pivot;    //最后相遇的位置就是基准存放的位置了
    QuickSort(arr, start, left - 1);   //不包含基准，划分左右两边，再次进行快速排序
    QuickSort(arr, left + 1, end);
}
//简单选择排序
void SelectSort(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])min=j;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;

    }
}
//堆排序
//调整堆
void HeadAdjust(int *arr,int tag,int size)
{
    int temp=arr[tag];
    for(int i=2*tag;i<=size;i*=2)
    {
        if(i<size&&arr[i]<arr[i+1])i++;
        if(temp>=arr[i])break;
        else
        {
            arr[tag]=arr[i];
            tag=i;
        }
    }
    arr[tag]=temp;
}
//建堆
void BulidMaxHeap(int *arr,int size)
{
    for(int i=size/2;i>=0;i--)
    {
        HeadAdjust(arr,i,size);
    }
}

//排序
void HeapSort(int *arr,int size)
{
    BulidMaxHeap(arr,size-1);
    for(int i=size-1;i>0;i--)
    {
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        HeadAdjust(arr,0,i-1);
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
    //DirectInsertSort(arr,size);//直接插入
    //DIS_with_BinarySearch(arr,size);//折半插入
    //ShellSort(arr,size);//希尔排序
    //BubbleSort(arr,size);//冒泡
    //QuickSort(arr,0,size-1);//快速排序
    //SelectSort(arr,size);//选择排序
    HeapSort(arr,size);
    for (size_t i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
        /* code */
    }    
    delete[] arr;
    return 0;
}