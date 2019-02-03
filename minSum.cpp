#include <bits/stdc++.h>
using namespace std;
/* 题目描述：
 *  求数组中和最接近于0的子数组
 * 思路：
 *  1、求部分和数组
 *  2、堆排序
 *  3、求差值数组
 *  4、求最小值
 */
// 最大堆下滑调整算法
void siftDown(int a[], int begin, int end) {
    int tmp = a[begin];
    // i 为父节点，j为左子节点
    int i = begin, j = 2 * i + 1;
    while (j <= end) {
        // j 指向孩子中最大的
        if (j < end && a[j] < a[j + 1]) j++;
        if (a[j] > tmp) {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    a[i] = tmp;
}
// 进行堆排序
void heapSort(int a[], int size) {
    // 调整为堆
    for (int i = (size - 2) / 2; i >= 0; i--) {
        siftDown(a, i, size - 1);
    }
    // 进行排序
    int end = size - 1;
    while (end > 0) {
        int tmp = a[end];
        a[end] = a[0];
        a[0] = tmp;
        siftDown(a, 0, --end);
    }
}
int minSum(int a[], int size) {
    int *sum = new int[size];
    sum[0] = a[0];
    // 初始化sum数组
    for (int i = 1; i < size; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    // 堆排序
    heapSort(sum, size);
    int min = sum[0];
    for (int i = 1; i < size; i++) {
        int tmp = sum[i] - sum[i - 1];
        if (tmp < min) min = tmp;
    }
    delete[] sum;
    return min;
}
int main() {
    int a[] = {
        5,
        6,
        7,
        1,
        2,
        3,
        4,
    };
    // heapsort test
    /* heapSort(a, sizeof(a)/sizeof(a[0]));
     * for(int x : a) {
     *      cout << x << " ";
     * }
     * cout << endl;
     */
    cout << minSum(a, sizeof(a) / sizeof(a[0])) << endl;
    return 0;
}
