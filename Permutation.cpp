#include <bits/stdc++.h>
using namespace std;
void Permutation(char *s, int begin, int end) {
    if (begin == end) {
        cout << s << endl;
    } else {
        for (int i = begin; i <= end; i++) {
            // left s[i] be first character int sequence begin to end
            swap(s[i], s[begin]);
            Permutation(s, begin + 1, end);
            swap(s[i], s[begin]);
        }
    }
}
int main() {
    char s[] = "hel";
    Permutation(s, 0, strlen(s) - 1);
    return 0;
}
