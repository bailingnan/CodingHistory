#include<cstdio>
#include<cstring>
int main() {
	int ht[128];
	for (int i = 0; i < 128; i++) {
		ht[i] = -1010;
	}
	char str1[1010], str2[1010];
	gets_s(str1);
	gets_s(str2);
	int len1 = strlen(str1), len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {
		if (ht[str1[i]] == -1010)
			ht[str1[i]] = 1;
		else ht[str1[i]]++;
	}
	for (int i = 0; i < len2; i++) {
		ht[str2[i]]--;
	}
	int cnt1 = 0,cnt2 = 0;
	for (int i = 0; i < 128; i++) {
		if (ht[i] != -1010) {
			if (ht[i]<0 && ht[i]>-1010)
				cnt2 = cnt2 + (-ht[i]);
			if (ht[i] < -1010)
				cnt2 = cnt2 + (-ht[i] - 1010);
			if (ht[i] > 0)
				cnt1 += ht[i];
		}
	}
	if (cnt2 > 0) {
		printf("No %d", cnt2);
	}
	else {
		printf("Yes %d", cnt1);
	}
}
//算法笔记
#include <cstdio>
#include <cstring>
const int MAXN = 1010;
// hashTable记录第一串中每种颜色的个数，miss记录缺少的珠子个数
int hashTable[80] = {0}, miss = 0;
// 将数字和字母转换为hashTable的下标
int change(char c) {
    if(c >= '0' && c <= '9') return c - '0';    // 数字
    if(c >= 'a' && c <= 'z') return c - 'a' + 10;    // 小写字母
    if(c >= 'A' && c <= 'Z') return c - 'A' + 36;    // 大写字母
}
int main() {
    char whole[MAXN], target[MAXN];
    gets(whole);    // 第一串
    gets(target);    // 第二串
    int len1 = strlen(whole);    // 第一串长度
    int len2 = strlen(target);    // 第二串长度
    for(int i = 0; i < len1; i++) {    // 遍历第一串
        int id = change(whole[i]);    // 字符->hashTable下标
        hashTable[id]++;    // 该颜色个数加1
    }
    for(int i = 0; i < len2; i++) {    // 遍历第二串
        int id = change(target[i]);    // 字符->hashTable下标
        hashTable[id]--;    // 该颜色个数减1
        if(hashTable[id] < 0) {    // 该颜色个数小于0
            miss++;    // 缺少的珠子个数加1
        }
    }
    if(miss > 0) printf("No %d\n", miss);    // 有缺少
    else printf("Yes %d\n", len1 - len2);    // 有富余
    return 0;
}
