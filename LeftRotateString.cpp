#include <bits/stdc++.h>
using namespace std;
// reverse string
void reverseString(char *s, int begin, int end) {
    while (begin < end) {
        char t = s[begin];
        s[begin++] = s[end];
        s[end--] = t;
    }
}

/* abcdef --> cdefab
 * <=> abcdef --> 'ab' + 'cdef'
 *            --> 'ba' + 'fedc' = 'bafedc'
 *            --> cdefab
 */
void leftRotateString(char *s, int m, int n) {
    m %= n;
    reverseString(s, 0, m - 1);
    reverseString(s, m, n - 1);
    reverseString(s, 0, n - 1);
}
