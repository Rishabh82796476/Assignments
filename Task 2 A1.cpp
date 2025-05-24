// Problem 2: Echoes of the Blood Moon

#include<bits/stdc++.h>
using namespace std;

int longestPathFrom(int i, const vector<int>& echo, vector<int>& memo) {
    if (memo[i] != -1) return memo[i];
    int maxLen = 1;
    for (int j = i + 1; j < echo.size(); ++j) {
        if (echo[j] > echo[i]) {
            maxLen = max(maxLen, 1 + longestPathFrom(j, echo, memo));
        }
    }
    return memo[i] = maxLen;
}

int longestEchoPath(const vector<int>& echo) {
    int n = echo.size();
    vector<int> memo(n, -1);
    int maxPath = 0;
    for (int i = 0; i < n; ++i)
        maxPath = max(maxPath, longestPathFrom(i, echo, memo));
    return maxPath;
}
