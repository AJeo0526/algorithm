#include <bits/stdc++.h>
using namespace std;
/* 寻找有序数组的旋转数组中的最小值
 * 例：56701234
 * 返回0
 */
int FindMin(int a[], int begin, int end) {
    while (begin < end) {
        int median = (begin + end) / 2;
        if (a[median] > a[begin])
            begin = median + 1;
        else if (a[median] < a[begin])
            end = median;
        else
            assert(0);
        // 数组中没有重复元素
    }
    return a[begin];
}
int main() {
    int a[] = {
        5,
        6,
        7,
        0,
        1,
        2,
        3,
        4,
    };
    cout << FindMin(a, 0, sizeof(a) / sizeof(a[0]) - 1) << endl;
    return 0;
}
