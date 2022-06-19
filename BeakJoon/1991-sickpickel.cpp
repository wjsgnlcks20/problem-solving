#include <bits/stdc++.h>
#define Max 50

using namespace std;

typedef struct _node{
	char data;
	struct _node * left;
	struct _node * right;
}Node;

Node * makeNewNode(char data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data =data;
	newNode->left =NULL;
	newNode->right =NULL; 
	return newNode;
}

void makeLeftChild(Node * parent, Node * child){
	parent->left = child;	
}
void makeRightChild(Node * parent, Node * child){
	parent->right = child;
}

void preorderTraverse(Node * now){
	if(now == NULL) return;
	cout << now->data;
	preorderTraverse(now->left);
	preorderTraverse(now->right);
}
void inorderTraverse(Node * now){
	if(now == NULL) return;
	inorderTraverse(now->left);
	cout << now->data;
	inorderTraverse(now->right);
}
void postorderTraverse(Node * now){
	if(now == NULL) return;
	postorderTraverse(now->left);
	postorderTraverse(now->right);
	cout << now->data;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int n;
	cin >> n;
	
	Node ** savePos = (Node**)malloc(sizeof(Node*) * n);
	for(int i = 0; i < n; i++){
		savePos[i] = makeNewNode('A' + i);
	}
	
	for(int i = 0; i < n; i++){
		char parent, left, right;
		cin >> parent >> left >> right;
		if(left!='.')makeLeftChild(savePos[parent - 'A'], savePos[left-'A']);
		if(right!='.')makeRightChild(savePos[parent - 'A'], savePos[right-'A']);
	}
	preorderTraverse(savePos[0]);
	cout << "\n";
	inorderTraverse(savePos[0]);
	cout << "\n";
	postorderTraverse(savePos[0]);
	cout << "\n";
	return 0;
}