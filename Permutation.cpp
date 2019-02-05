#include <bits/stdc++.h>
using namespace std;
void Permutation(char *s, int begin, int end) {
    if (begin == end) {
        cout << s << endl;
    } else {
        // mark the charcter which has been set as first charcter of the subsequence
        bool mark[256] = {false};
        for (int i = begin; i <= end; i++) {
            // left s[i] be first character int subsequence begin to end
            if (mark[(unsigned) s[i]]) {
                continue;
            } else {
                mark[(unsigned) s[i]] = true;
            }
            swap(s[i], s[begin]);
            Permutation(s, begin + 1, end);
            swap(s[i], s[begin]);
        }
    }
}
int main() {
    char s[] = "hello";
    Permutation(s, 0, strlen(s) - 1);
    return 0;
}
