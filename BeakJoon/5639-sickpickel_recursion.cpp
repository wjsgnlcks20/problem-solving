#include <bits/stdc++.h>

using namespace std;

void preToPost(int start, int end, vector<int>& preorder){
    if(start > end) return;
    if(start == end){
        cout << preorder[start] << "\n";
        return;
    }
    int rootValue = preorder[start]; 
    int mid_idx = start + 1;
    while(mid_idx <= end){
        if(rootValue > preorder[mid_idx]) mid_idx++;
        else break;
    }
    preToPost(start + 1, mid_idx - 1, preorder);
    preToPost(mid_idx, end, preorder);
    cout << rootValue << "\n";
}

int main(void){

    int input;
    vector<int> preorder;
    while(cin >> input) {
        preorder.push_back(input);
    }
    preToPost(0, preorder.size() - 1, preorder);

    return 0;
}