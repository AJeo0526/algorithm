#include <bits/stdc++.h>
using namespace std;
// the space of next has been allocated
void calNext(char *s, int *next) {
    int len = strlen(s);
    // initial
    int i = 0;
    next[0] = -1;
    int k = -1;
    while (i < len - 1) {
        // k == -1 implicit that there is no such string
        if (k == -1 || s[i] == s[k]) {
            ++i;
            ++k;
            // 改进的kmp算法
            if (s[i] == s[k]) {
                next[i] = next[k];
            } else {
                next[i] = k;
            }
        } else {
            k = next[k];
        }
    }
}
int KMP(char *target, char *pattern) {
    int tarLen = strlen(target), patLen = strlen(pattern);
    int *next = new int[patLen];
    // initial next
    calNext(pattern, next);
    int i = 0, j = 0;
    int ans = -1;
    while (i < tarLen) {
        if (j == -1 || target[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == patLen) {
            ans = i - patLen;
            break;
        }
    }
    delete[] next;
    return ans;
}
int main() {
    char tar[] = "hello", pat[] = "llo";
    cout << KMP(tar, pat) << endl;
    return 0;
}
