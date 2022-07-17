#include <bits/stdc++.h>
#define Max 100001

using namespace std;

int inorder_idx[Max];
int inorder[Max];
int postorder[Max];

void getPreorder(int in_left, int in_right, int post_left, int post_right){
    if(in_left > in_right || post_left > post_right){
        return;
    }
    int mid = postorder[post_right];
    int mid_in_idx = inorder_idx[mid];
    int len = mid_in_idx - in_left;
    cout << mid << " ";
    getPreorder(in_left, mid_in_idx - 1, post_left, post_left + len - 1);
    getPreorder(mid_in_idx + 1, in_right, post_left + len, post_right - 1);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> inorder[i];
        inorder_idx[inorder[i]] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> postorder[i];
    }
    getPreorder(0, N - 1, 0, N - 1);
    return 0;
}