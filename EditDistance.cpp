#include <bits/stdc++.h>
using namespace std;
/* string edit distance
 * legal operation
 *  delete, alter, add
 * solution
 *  the editdistance between string and empty string is the length of string
 *  strA : subA + "x"
 *  strB : subB + "y"
 */
int EditDistance(char  *pSource, char *pTarget) {
    int srcLen = strlen(pSource), tarLen = strlen(pTarget);
    int dp[srcLen + 1][tarLen + 1];
    // initial
    for (int i = 0; i < = srcLen; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= tarLen; i++) {
        dp[0][i] = i;
    }
    // dp
    for (int i = 0; i < srcLen; i++) {
        for (int j = 0; j < tarLen; j++) {
            if (pSource[i] == pTarget[j]) {
                dp[i + 1][j + 1] = dp[i][j];
            } else {
                int min = dp[i][j];
                if (dp[i + 1][j] < min) min = dp[i + 1][j];
                if (dp[i][j + 1] < min) min = dp[i][j + 1];
                dp[i + 1][j + 1] = min + 1;
            }
        }
    }
    return dp[srcLen][tarLen];
}
int main() {
    char pSource[] = "ALGORITHM", pTarget[] = "ALTRUISTIC";
    cout << EditDistance(pSource, pTarget) << endl;
    return 0;
}
