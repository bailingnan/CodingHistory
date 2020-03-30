//next[i]就是子串s[0...i]的最长相等前后缀的前缀最后一位的下标
//getNext求解长度为len的字符串s的next数组
void getNext(char s[], int len) {
	int j = -1;
	next[0] = -1;//初始化j=next[0]=-1
	for (int i = 1; i < len; i++) {//求解next[i]-next[len-1]
		while (j != -1 && s[i] != s[j + 1]) {
			j = next[j];//反复令j=next[j];
		}//直到j回退到-1，或是s[i]==s[j+1]
		if (s[i] = s[j + 1]) {
			j++;
		}
		next[i] = j;
	}
}
//next数组的含义就是当j+1位失配时，j应该回退的位置
//KMP算法，判断pattern是否是text的子串,复杂度O(m+n)
bool KMP(char text[], pattern[]) {
	int n = strlen(text), m = strlen(pattern);//字符串长度
	getNext(pattern, m);//计算pattern的next数组
	int j = -1;//初始化j=1,表示当前没有任意一位被匹配
	for (int i = 0; i < n; i++) {//试图匹配text[i]
		while (j != -1 && text[i] != pattern[j + 1]) {
			j = next[j];
		}
		if (text[i] == pattern[j + 1]) {
			j++;
		}
		if (j == m - 1) {
			return true;
		}
	}
	return false;
}
//KMP算法，统计pattern在text中出现的次数
bool KMP(char text[], pattern[]) {
	int n = strlen(text), m = strlen(pattern);//字符串长度
	getNext(pattern, m);//计算pattern的next数组
	int ans=0,j = -1;//初始化j=1,表示当前没有任意一位被匹配
	for (int i = 0; i < n; i++) {//试图匹配text[i]
		while (j != -1 && text[i] != pattern[j + 1]) {
			j = next[j];
		}
		if (text[i] == pattern[j + 1]) {
			j++;
		}
		if (j == m - 1) {
			ans++;
			j = next[j];
		}
	}
	return ans;
}
//nextval[i]的含义是当模式串pattern的i+1位发生失配时，i应当回退到的最佳位置
//getNext求解长度为len的字符串s的next数组
void getNextval(char s[], int len) {
	int j = -1;
	nextval[0] = -1;//初始化j=next[0]=-1
	for (int i = 1; i < len; i++) {//求解next[i]-next[len-1]
		while (j != -1 && s[i] != s[j + 1]) {
			j = nextval[j];//反复令j=next[j];
		}//直到j回退到-1，或是s[i]==s[j+1]
		if (s[i] = s[j + 1]) {
			j++;
		}
		if (j == -1 || s[i + 1] != s[j + 1]) {
			nextval[i] = j;
		}
		else {
			nextval[i] = nextval[j];
		}
	}
}
