#include<cstdio>
#include<cstring>
int main() {
  char str1[10010], str2[10010];
  gets(str1);
  gets(str2);
  int len1 = strlen(str1), len2 = strlen(str2);
  int ht[128] = { 0 };
  for (int i = 0; i < len2; i++) {
    ht[str2[i]] = 1;
  }
  for (int i = 0; i < len1; i++) {
    if (ht[str1[i]] == 0)
      printf("%c", str1[i]);
  }
  return 0;
}
//算法笔记
#include <cstdio>
#include <cstring>
const int MAX_LEN = 10005;
char a[MAX_LEN], b[MAX_LEN];
bool HashTable[128];
int main() {
    gets(a);
    gets(b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    for(int i = 0; i < lenB; i++) {
        HashTable[b[i]] = true;
    }
    for(int i = 0; i < lenA; i++) {
        if(HashTable[a[i]] == false) {
            printf("%c", a[i]);
        }
    }
    return 0;
}
