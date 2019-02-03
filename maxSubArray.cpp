#include <bits/stdc++.h>
using namespace std;
// 暴力法
int maxSubArray1(int a[], int begin, int end) {
    int max = a[begin];
    for (int i = begin; i < end; i++) {
        int tmp = 0;
        for (int j = i; j < end; j++) {
            tmp += a[j];
            if (tmp > max) max = tmp;
        }
    }
    return max;
}
// 分治法
int maxSubArray2(int a[], int begin, int end) {
    // 只有一个元素
    if (begin == end) return a[begin];
    // 分而治之
    int median = (begin + end) / 2;
    int m1 = maxSubArray2(a, begin, median);
    int m2 = maxSubArray2(a, median + 1, end);
    //    int m3 = a[median] + a[median + 1];
    int left = a[median], right = a[median + 1];
    int tmp = left;
    for (int i = median - 1; i >= begin; i--) {
        tmp += a[i];
        if (tmp > left) left = tmp;
    }
    tmp = right;
    for (int i = median + 2; i <= end; i++) {
        tmp += a[i];
        if (tmp > right) right = tmp;
    }
    int m3 = left + right;
    // 返回m1, m2, m3中的最大值
    m1 = (m2 > m1) ? m2 : m1;
    m1 = (m3 > m1) ? m3 : m1;
    return m1;
}
// 动态规划法
int maxSubArray3(int a[], int begin, int end) {
    int max = a[begin], sum = a[begin];
    for (int i = begin + 1; i <= end; i++) {
        /* sum 表示以a[i]结尾的连续子数组的最大和
         * 计算方法 : sum = max{sum + a[i], a[i]}
         */
        if (sum > 0) {
            sum += a[i];
        } else {
            sum = a[i];
        }
        if (sum > max) max = sum;
    }
    return max;
}
int main() {
    int a[] = {1,-2,3,10,-4,7,2,-5,};
    cout << maxSubArray1(a, 0, sizeof(a) / sizeof(a[0])) << endl;
    cout << maxSubArray2(a, 0, sizeof(a) / sizeof(a[0])) << endl;
    cout << maxSubArray3(a, 0, sizeof(a) / sizeof(a[0])) << endl;
}
