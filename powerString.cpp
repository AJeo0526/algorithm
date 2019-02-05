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
