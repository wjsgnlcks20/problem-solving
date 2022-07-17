#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct _node{
    int node_num;
    int data;
    struct _node * left;
    struct _node * right;
}Node;

Node * makeNewNode(int node_num, int data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->node_num = node_num;
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
    else { 
        parent->right = newNode;
     }

}

void preorderTraverse(Node * now, vector<int>&save){
    if(now == NULL){
        return;
    }
    save.push_back(now->node_num);
    preorderTraverse(now->left, save);
    preorderTraverse(now->right, save);
}

void postorderTraverse(Node * now, vector<int>&save){
    if(now == NULL){
        return;
    }
    postorderTraverse(now->left, save);
    postorderTraverse(now->right, save);
    save.push_back(now->node_num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<pair<int, int>, int>> nodes; 
    for(int i = 0; i < nodeinfo.size(); i++){
        // 이진트리에 데이터를 넣을 때의 순서를 위해 y기준 정렬이 필요
        nodes.push_back({{nodeinfo[i][1], nodeinfo[i][0]}, i + 1});
    }
    sort(nodes.begin(), nodes.end());
    reverse(nodes.begin(), nodes.end());

    Node * root = makeNewNode(nodes[0].second, nodes[0].first.second);
    for(int i = 1; i < nodes.size(); i++){
        Node * newNode = makeNewNode(nodes[i].second, nodes[i].first.second);
        addNewNode(root, newNode);
    }
    vector<int>pre, post;
    preorderTraverse(root, pre);
    postorderTraverse(root, post);

    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}