//c语言malloc函数
#include<stdlib.h>
typename *p = (typename*)malloc(sizeof(typename));
int *p = (int*)malloc(10 * sizeof(int));
//C++ new运算符
typename *p = new typename;
int *p = new int[10];
//c语言对应malloc函数free函数
#include<stdlib.h>
free(p);
//c++对应new运算符delete运算符
delete(p);
//创建链表
#include<cstdio>
struct node {
	int data;
	node* next;
};
node* create(int Array[]) {
	node *p, *pre, *head;
	head = new node;
	head->next = NULL;
	pre = head;
	for (int i = 0; i < 5; i++) {
		p = new node;
		p->data = Array[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}
int main() {
	int Array[5] = { 5,3,6,1,2 };
	node *L = create(Array);
	L = L->next;
	while (L != NULL) {
		printf("%d", L->data);
		L = L->next;
	}
	return 0;
}
//查找元素
int search(node* head, int x) {
	int count = 0;
	node *p = head->next;
	while (p != NULL) {
		if (p->data == x) {
			count++;
		}
		p = p->next;
	}
	return count;
}
//插入元素
void insert(node *head, int pos, int x) {
	node *p = head;
	for (int i = 0; i < pos; i++) {
		p = p->next;
	}
	node *q = new node;
	q->data = x;
	q->next = p->next;
	p->next = q;
}
//删除元素
void del(node *head, int x) {
	node p = head->next;
	node *pre = head;
	while (p != NULL) {
		if (p->data == x) {
			pre->next = p->next;
			delete(p);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//静态链表
struct Node {
	typename data;
	int next;
}node[size];
