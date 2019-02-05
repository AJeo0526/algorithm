#include <bits/stdc++.h>
using namespace std;
// the space of next has been allocated
void calNext(char *s, int *next) {
    int len = strlen(s);
    // initial
    int i = 0;
    next[0] = -1;
    int k = -1;
    // 多计算一位
    while (i < len) {
        // k == -1 implicit that there is no such string
        if (k == -1 || s[i] == s[k]) {
            ++i;
            ++k;
            next[i] = k;
        } else {
            k = next[k];
         }
     }
 }
 /* 寻找周期字符串s中的最小周期子串
  * 注意：必须使用经典next数组，不能使用next数组的变种，详见下面的证明部分
  *  abababab --> ab
  *  思路：
  *   首先证明如果strlen(s) % len == 0表示s为周期串
  *    记长度为len的字符串为大写字母
  *    则可以设字符串s可以表示为ABCDE
  *    由 len = strlen(s) - next[strlen(s)]
  *    可得 ABCD == BCDE
  *    => A = B = C = D = E
  *    即A为s的一个周期
  *    使用反证法易得A为s的最小周期
  *    而next[strlen(s)]表示s的最大子串重合程度即N-1个最小周期串
  *    s为N个最小周期串
  *    则最小周期串长为len = strlen(s) - next[strlen(s)]
  *    最小周期串为s的前len个字符
  */
 void powerString(char *s) {
     int *next = new int[strlen(s) + 1];
     calNext(s, next);
     int len = strlen(s) - next[strlen(s)];
     if (strlen(s) % len == 0) {
         for (int i = 0; i < len; i++) {
             cout << s[i];
         }
         cout << endl;
     }
     delete[] next;
 }
 int main() {
     char s[] = "ababababab";
     powerString(s);
     return 0;
}
