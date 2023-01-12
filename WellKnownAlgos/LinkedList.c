#include <stdio.h>

typedef int Data;

typedef struct _node{
    Data data;
    struct _node * next;
}Node;

/**
 * @brief 
 * linkedList crud.
 * 생성은 tail에 1개씩 추가해 나가는 방식으로 구현한다.
 * 조회는 head 위치에서 cur 포인터를 받아서 이동한다.
 * 수정은 조회로 해당 노드를 찾은 뒤 수정하고
 * 삭제는 현재 노드의 이전노드와 그 다음 노드를 연결해주고,
 * 현재 노드의 메모리를 할당 해제해줌으로써 완료한다.
 */

typedef struct _list{
    Node node;
    Node * head;
    Node * tail;
    Node * before;
}List;

Node * makeNewNode(Data data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->right = NULL;
    return newNode;
}

List * makeList(){
    List * newList = (List*)malloc(sizeof(List));
}

List * initList(Data firstData){
    List * newList = makeList();
    Node * dummy = makeNewNode(firstData);
    Node * newNode = makeNewNode(0);
    newList->before = dummy;
    newList->head = newNode;
    newList->tail = newNode;
    newList->before->next = newList->head;
    return newList;
}

void addNodeToList(List * list, Data data){
    Node * newNode = makeNewNode(data);
    list->tail->next = newNode;
    list->before = list->tail;
    list->tail = newNode;
}

Node * getNodeFromList(Data data){

}

void printList(List * list){
    Node * cur = list->head;
    Node * before = list->before;
    while(list->tail != NULL) {
        printf("%d", cur->data);
        cur->next = 
    }
}

void updateNodeFromList(Data data){

}

void deleteNodeFromList(Data data){

}




int main(void){

}