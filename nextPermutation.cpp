#include <bits/stdc++.h>
using namespace std;
// 寻找比s稍大的全排列
// 无重复字符
void reverseString(char *s, int begin, int end) {
    while(begin < end) {
        char t = s[begin];
        s[begin++] = s[end];
        s[end--] = t;
    }
}
bool nextPermutation(char *s, int len) {
    int i = len - 2;
    while (i >= 0 && s[i] > s[i + 1]) i--;
    if (i < 0) return false;
    int j = len - 1;
    while (s[j] < s[i]) j--;
    swap(s[i],s[j]);
    reverseString(s, i + 1, len - 1);
    return true;
}
int main() {
    char s[] = "123";
    // you should insure s is increasing sequence
    do {
        cout << s << endl;
    } while (nextPermutation(s, strlen(s)));
    return 0;
}
