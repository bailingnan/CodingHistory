#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
int ans = 0, dp[MAXN][MAXN];
int main() {
	string str;
	getline(cin, str);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < str.length(); i++) {
		dp[i][i] = 1;
		ans = 1;
		if (i < str.length() - 1) {
			if (str[i] == str[i + 1]) {
				dp[i][i + 1] = 1;
				ans = 2;
			}
		}
	}
	int L;
	for (L = 3; L <= str.length(); L++) {
		for (int i = 0; i + L - 1 < str.length(); i++) {
			int j = i + L - 1;
			if (str[i] == str[j] && dp[i + 1][j - 1]==1) {
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];
int main() {
    gets(S);
    int len = strlen(S), ans = 1;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if(i < len - 1) {
            if(S[i] == S[i + 1]) {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for(int L = 3; L <= len; L++) {
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1;
            if(S[i] == S[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
