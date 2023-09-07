#include <bits/stdc++.h>
using namespace std;

int RandomPartition(int *arr, int start, int end) {
    int randomIndex = start + rand() % (end - start + 1); // 随机选择一个索引
    swap(arr[randomIndex], arr[start]); // 交换随机选择的元素与第一个元素
    int pivot = arr[start];
    int left = start, right = end;
    
    while (left < right) {
        while (left < right && arr[right] >= pivot) right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) left++;
        arr[right] = arr[left];
    }
    
    arr[left] = pivot;
    return left;
}

void QuickSort(int *arr, int start, int end) {
    if (start >= end) return;
    int pivotIndex = RandomPartition(arr, start, end); // 随机选择基准位置
    QuickSort(arr, start, pivotIndex - 1);
    QuickSort(arr, pivotIndex + 1, end);
}

int main() {
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    srand(time(0)); // 使用当前时间作为随机种子
    QuickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}