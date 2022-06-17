#include <bits/stdc++.h>
#define Max 51

using namespace std;

int root[Max];

int find(int x){
    if(x == root[x]) return x;
    return root[x] = find(root[x]);
}

void unify(int x, int y){
    x = find(x);
    y = find(y);
    if(x < y) root[y] = x;
    else root[x] = y;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M, truthCnt;
    vector<int> knowTruth, partyHead;
    cin >> N >> M;
    cin >> truthCnt;
    for(int i = 1; i <= N; i++) root[i] = i;
    for(int i = 0; i < truthCnt; i++){
        int input;
        cin >> input;
        knowTruth.push_back(input);
    }

    for(int i = 0; i < M; i++){
        int input, u, e;
        cin >> input;
        for(int j = 0; j < input; j++){
            cin >> e;
            if(j==0) {
                partyHead.push_back(e);
            }
            else unify(u, e);
            u = e;
        }
    }
    int answer = 0;
    for(auto head : partyHead){
        bool flag = true;
        for(auto truth : knowTruth){
            if(find(truth) == find(head)) {
                flag = false; break;
            }
        }
        if(flag) answer++; 
    }
    cout << answer << "\n";
    return 0;
}