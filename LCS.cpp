#include <bits/stdc++.h>
using namespace std;
/* LCS --> LIS
 */
int LCS(char *str1, char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    int array[len1 + 1][len2 + 1];
    // initial
    for (int i = 0; i <= len1; i++) {
        array[i][0] = 0;
    }
    for (int i = 0; i <= len2; i++) {
        array[0][i] = 0;
    }
    // dynamic_programming
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                array[i + 1][j + 1] = array[i][j] + 1;
            } else {
                array[i + 1][j + 1] = (array[i + 1][j] > array[i][j + 1] ? array[i + 1][j] : array[i][j + 1]);
            }
        }
    }
    return array[len1][len2];
}
int main() {
    char str1[] = "hello", str2[] = "gellho";
    cout << LCS(str1, str2) << endl;
    return 0;
}
