#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<double> num;
int main() {
	int N;
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		string str;
		cin >> str;
		bool flag = true;
		double n=0;
		int tag = 1, cntd = 0, cntn = 1;
		for (int i= 0; i < str.length(); i++) {
			if (i==0&&str[i] == '-') { 
				tag = -1; 
				continue;
			}
			if (str[i] == '.') {
				if (cntd == 0) {
					cntd++;
					continue;
				}
				else if (cntd == 1) {
					flag = false;
					break;
				}
			}
			if (!(str[i] >= '0'&&str[i] <= '9')&&str[i] != '.'){
				flag = false;
				break;
			}
			if (str[i] >= '0'&&str[i] <= '9') {
				if (cntd == 0) {
					n = n * 10 + str[i] - '0';
					if (n > 1000) {
						flag = false;
						break;
					}
				}
				else {
					double temp=str[i]-'0';
					if (cntn <= 2) {
						int t = cntn;
						while (t) {
							temp /= 10;
							t--;
						}
						n += temp;
						if (n > 1000) {
							flag = false;
							break;
						}
						cntn++;
					}
					else {
						flag = false;
						break;
					}
					
				}
			}
		}
		if (flag == false) {
			cout << "ERROR: " << str << " is not a legal number"<<endl;
		}
		else {
			num.push_back(tag*n);
		}
	}
	if (num.size() == 0) {
		printf("The average of 0 numbers is Undefined\n");
	}
	else if(num.size()>1){
		double sum=0;
		for (int i = 0; i < num.size(); i++) {
			sum += num[i];
		}
		printf("The average of %d numbers is %.2f\n", num.size(), sum / num.size());
	}
	else {
		printf("The average of 1 number is %.2f\n", num[0]);
	}
	return 0;
}
//算法笔记
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// isLegal函数判断是否合法
bool isLegal(string input) {
    if(input[0] == '-') {     // 如果开头是负号
        input.erase(input.begin());     // 去掉开头的负号
    }
    if(input.length() == 0) {
        return false;       // 去掉负号后如果长度为0,那么不合法
    }
    int dotPos = -1;        // dotPos记录小数点的下标
    for(int i = 0; i < input.length(); i++) {
        if(!(input[i] == '.' || (input[i] >= '0' && input[i] <= '9'))) {
            return false;       // 如果出现了小数点或者0到9以外的字符,那么不合法
        }
        if(input[i] == '.') {     // 如果当前位置是小数点
            if(dotPos != -1) {      // 如果前面已经出现过小数点,那么不合法
                return false;
            } else {        // 否则小数点的位置为i
                dotPos = i;
            }
        }
    }
    if(dotPos != -1 && dotPos + 3 < input.length()) {
        return false;       // 存在小数点且小数点后超过2位小数时,不合法
    }
    double tempNumber;
    sscanf(input.c_str(), "%lf", &tempNumber);    // 将字符串转换为double型
    return tempNumber <= 1000;      // 如果该数字不超过1000(已经去掉负号),那么合法;否则不合法
}
int main() {
    int n, num = 0;     // n为输入的数的个数,num为合法的数的个数
    cin >> n;           // 输入n
    double sum = 0, tempNumber;     // sum为合法的数的和,tempNumber用来临时存放数字
    string input;         // 输入的字符串
    for(int i = 0; i < n; i++) {    // 输入n个字符串
        cin >> input;     // 输入字符串
        if(isLegal(input)) {      // 如果合法
            sscanf(input.c_str(), "%lf", &tempNumber);    // 将该字符串转换为double型
            sum += tempNumber;      // 累加合法的数
            num++;      // 合法的数的个数加1
        } else {
            printf("ERROR: %s is not a legal number\n", input.c_str());   // 输出不合法信息
        }
    }
    if(num == 0) {      // 不存在合法的数
        printf("The average of 0 numbers is Undefined\n");
    } else if(num == 1) {       // 只有一个合法的数
        printf("The average of 1 number is %.2f\n", sum);
    } else {        // 2个以上合法的数
        printf("The average of %d numbers is %.2f\n", num, sum / num);
    }
    return 0;
}
