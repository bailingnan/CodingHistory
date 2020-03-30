#include<cstdio>
#include<algorithm>
using namespace std;
struct Node {
	int data;
	int h;
	Node*l, *r;
};
Node* NewNode(int x) {
	Node* root =new Node;
	root->data = x;
	root->l = root->r = nullptr;
	root->h = 1;
	return root;
}
int getHeight(Node* root) {
	if (root == nullptr) return 0;
	else return root->h;
}
void updateHeight(Node* root) {
	root->h = max(getHeight(root->l), getHeight(root->r)) + 1;
}
int getFac(Node*root) {
	return (getHeight(root->l) - getHeight(root->r));
}
void L(Node*&root) {
	Node*temp = root->r;
	root->r = temp->l;
	temp->l = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(Node*&root) {
	Node*temp = root->l;
	root->l = temp->r;
	temp->r = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(Node*&root, int data) {
	if (root == nullptr) {
		root = NewNode(data);
		return;
	}
	if (data < root->data) {
		insert(root->l, data);
		updateHeight(root);
		if (getFac(root) == 2) {
			if (getFac(root->l) == 1) {
				R(root);
			}
			else if (getFac(root->l) == -1) {
				L(root->l);
				R(root);
			}
		}	
	}
	else {
		insert(root->r, data);
		updateHeight(root);
		if (getFac(root) == -2) {
			if (getFac(root->r) == 1) {
				R(root->r);
				L(root);
			}
			else if (getFac(root->r) == -1) {
				L(root);
			}
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	Node* root = nullptr;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		insert(root, temp);
	}
	printf("%d", root->data);
	return 0;
}
//算法笔记
/*
#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int v, height;
    node *left, *right;
} *root , *null;
node* newNode(int v) {
    node* t = new node();
    t->v = v;
    t->height = 1;
    t->left = t->right = null;
    return t;
}
void getNewHeight(node* root) {
    root->height = max(root->left->height, root->right->height) + 1;
}
void L(node*& root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    getNewHeight(root);
    getNewHeight(temp);
    root = temp;
}
void R(node*& root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    getNewHeight(root);
    getNewHeight(temp);
    root = temp;
}
void insert(node*& root, int v) {
    if(root == null) {
        root = newNode(v);
        return;
    }
    if(v < root->v) {
        insert(root->left, v);
        getNewHeight(root);
        if((root->left->height) - (root->right->height) == 2) {
            if((root->left->left->height)-(root->left->right->height)==1) {
                R(root);
            } else if((root->left->left->height) - (root->left->right->height) == -1) {
                L(root->left);
                R(root);
            }
        }
    } else {
        insert(root->right, v);
        getNewHeight(root);
        if((root->left->height) - (root->right->height) == -2) {
            if((root->right->left->height) - (root->right->right->height) == 1) {
                R(root->right);
                L(root);
            } else if((root->right->left->height) - (root->right->right->height) == -1) {
                L(root);
            }
        }
    }
}
void init() {
    null = new node;
    null -> height = 0;
    root = null;
}
int main() {
    init();
    int n, v;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d\n", root->v);
    return 0;
}
*/
