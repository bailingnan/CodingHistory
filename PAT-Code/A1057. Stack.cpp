#include<cstdio>//超时
#include<cstring>
#include<set>
#include<stack>
using namespace std;
stack<int> St, tSt;
set<int> od;
char str[3][20] = { "Push","Pop","PeekMedian" };
int N;
int main() {
	scanf("%d", &N);
	while (N--) {
		char temp[20];
		scanf("%s", temp);
		if (strcmp(temp, str[0]) == 0) {
			int t;
			scanf("%d", &t);
			St.push(t);
		}
		else if (strcmp(temp, str[1]) == 0) {
			if (St.size() == 0) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", St.top());
				St.pop();
			}
		}
		else {
			if (St.size() == 0) {
				printf("Invalid\n");
			}
			else {
				while (St.size()) {
					od.insert(St.top());
					tSt.push(St.top());
					St.pop();
				}
				int K;
				if (od.size() % 2 == 0) {
					K = od.size() / 2;
				}
				else {
					K = (od.size() + 1) / 2;
				}
				set<int>::iterator it=od.begin();
				int cnt = 0;
				while (cnt != K-1) {
					it++;
					cnt++;
				}
				printf("%d\n", *it);
				od.clear();
				while (tSt.size()) {
					St.push(tSt.top());
					tSt.pop();
				}
			}
		}
	}
	return 0;
}
/*
#include<cstdio>
#include<cstring>
#include<set>
#include<stack>
using namespace std;
stack<int> St, tSt;
set<int> od;
char str[3][20] = { "Push","Pop","PeekMedian" };
int N, table[100010] = { 0 }, block[317] = { 0 };
int main() {
	scanf("%d", &N);
	while (N--) {
		char temp[20];
		scanf("%s", temp);
		if (strcmp(temp, str[0]) == 0) {
			int t;
			scanf("%d", &t);
			St.push(t);
			table[t]++;
			int m = t / 316;
			block[m]++;
		}
		else if (strcmp(temp, str[1]) == 0) {
			if (St.size() == 0) {
				printf("Invalid\n");
			}
			else {
				printf("%d\n", St.top());
				int m = St.top() / 316;
				block[m]--;
				table[St.top()]--;
				St.pop();
			}
		}
		else {
			if (St.size() == 0) {
				printf("Invalid\n");
			}
			else {
				int K;
				if (St.size() % 2 == 0) {
					K = St.size() / 2;
				}
				else {
					K = (St.size() + 1) / 2;
				}
				int i,sum=0;
				for (i = 0; i < 317; i++) {
					if (sum + block[i] < K) {
						sum += block[i];
					}
					else {
						break;
					}
				}
				int tp = 316 * i;
				for (; tp < 316 * (i + 1); tp++) {
					sum += table[tp];
					if (sum >= K) {
						break;
					}
				}
				printf("%d\n", tp);
			}
		}
	}
	return 0;
}
*/
//算法笔记
/*
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int lim = 317;
stack<int> st;
int x, query;
int bucket[lim];
int table[100005];
void peekMedian() {
    int K = st.size();
    if(K % 2 == 1) K = (K + 1) / 2;
    else K = K / 2;
    int sum = 0;
    int idx = 0;
    for(idx = 0; idx < lim; idx++) {
        if (sum + bucket[idx] < K) {
            sum += bucket[idx];
        }
        else break;
    }
    int b = idx * lim;
    while(1) {
        sum += table[b];
        if(sum >= K) {
            printf("%d\n", b);
            break;
        }
        b++;
    }
}
int main() {
    memset(bucket, 0, sizeof(bucket));
    memset(table, 0, sizeof(table));
    char cmd[20];
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        scanf("%s", cmd);
        if(strcmp(cmd, "Push") == 0) {
            scanf("%d", &x);
            st.push(x);
            bucket[x / lim]++;
            table[x]++;
        } else if(strcmp(cmd, "Pop") == 0) {
            if (st.empty() == true) {
                printf("Invalid\n");
            } else {
                x = st.top();
                st.pop();
                bucket[x/lim]--;
                table[x]--;
                printf("%d\n", x);
            }
        } else {
            if(st.empty() == true) {
                printf("Invalid\n");
            } else {
                peekMedian();
            }
        }
    }
    return 0;
}
*/
