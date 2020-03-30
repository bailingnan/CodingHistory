#include<cstdio>//超时，扣5分；
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(map<string, int>a, map<string, int>b) {
	map<string, int>::iterator ita;
	map<string, int>::iterator itb;
	ita = a.begin();
	itb = b.begin();
	return ita->second < itb->second;
}
int main() {
	int N;
	scanf("%d", &N);
	map<string, int>mp[10001];
	for (int i = 0; i < N; i++) {
		int ID;
		scanf("%d", &ID);
		getchar();
		string str;
		getline(cin, str);
		mp[i][str] = ID;
		getline(cin, str);
		mp[i][str] = ID;
		getline(cin, str);
		int k = 0;
		while (k < str.length()) {
			string word;
			while (str[k] != ' '&&k<str.length()) {
				word += str[k];
				k++;
			}
			if (word != "") {
				mp[i][word] = ID;
				word.clear();
			}
			k++;
		}
		getline(cin, str);
		mp[i][str] = ID;
		getline(cin, str);
		mp[i][str] = ID;
	}
	sort(mp, mp + N, cmp);
	int M;
	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; i++) {
		string str;
		getline(cin, str);
		cout << str << endl;
		string::iterator it = str.begin();
		int cnt = 0;
		while ((cnt == 1 && *it >= '0'&&*it <= '9' || *it>='a'&&*it<='z'||*it>='A'&&*it<='Z')==false) {
			if (*it >= '0'&&*it <= '9')
				cnt++;
			str.erase(it);
		}
		int flag = 0;
		for (int k = 0; k < N; k++) {
			map<string, int>::iterator it = mp[k].find(str);
			if (it != mp[k].end()) {
				printf("%07d\n", mp[k][str]);
				flag = 1;
			}
		}
		if (flag == 0)
			printf("Not Found\n");
	}
	return 0;
}
/*
//算法笔记
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
void query(map<string,set<int> >& mp, string& str) {
    if(mp.find(str) == mp.end()) printf("Not Found\n");
    else{
        for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++) {
            printf("%07d\n", *it);
        }
    }
}
int main() {
    int n, m, id, type;
    string title, author, key, pub, year;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        char c = getchar();
        getline(cin, title);
        mpTitle[title].insert(id);
        getline(cin, author);
        mpAuthor[author].insert(id);
        while(cin >> key) {
            mpKey[key].insert(id);
            c = getchar();
            if(c == '\n') break;
        }
        getline(cin, pub);
        mpPub[pub].insert(id);
        getline(cin, year);
        mpYear[year].insert(id);
    }
    string temp;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &type);
        getline(cin, temp);
        cout << type << ": " << temp << endl;
        if(type == 1) query(mpTitle, temp);
        else if(type == 2) query(mpAuthor, temp);
        else if(type == 3) query(mpKey, temp);
        else if(type == 4) query(mpPub, temp);
        else query(mpYear, temp);
    }
    return 0;
}
*/
