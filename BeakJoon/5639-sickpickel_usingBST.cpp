#include <bits/stdc++.h>

using namespace std;

typedef struct _node{
    int data;
    struct _node * left;
    struct _node * right;
}Node;

Node * makeNewNode(int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addNewNode(Node * root, Node * newNode){
    Node * parent = root, * current = root;
    while(current != NULL){
        if(current->data > newNode->data){
            parent = current;
            current = current->left;
        }
        else {
            parent = current;
            current = current->right;
        }
    }
    if(parent->data > newNode->data){
        parent->left = newNode;
    }
    else parent->right = newNode;
}

void postorderTraversal(Node * now){
    if(now == NULL) return;
    postorderTraversal(now->left);
    postorderTraversal(now->right);
    cout << now->data << "\n";
}

int main(void){

    int input;
    vector<int> preorder;
    while(cin >> input) {
        preorder.push_back(input);
    }
    Node * root = makeNewNode(preorder[0]);
    for(int i = 1; i < preorder.size(); i++){
        Node * newNode = makeNewNode(preorder[i]);
        addNewNode(root, newNode);
    }
    postorderTraversal(root);
    return 0;
}