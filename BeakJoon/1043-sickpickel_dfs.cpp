#include <bits/stdc++.h>
#define Max 51

using namespace std;

int N, M, answer;
int arr[Max][Max];
int visited[Max];

void dfs(int now_party){
    visited[now_party] = 1;
    answer--;
    for(int i = 1; i <= N; i++){
        if(arr[now_party][i] == 0) continue;
        for(int j = 1; j <= M; j++){
            if(visited[j] || arr[j][i] == 0) continue;
            dfs(j);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int truthCnt, knowTruth[Max] = {};
    vector<int> truth_party;
    cin >> N >> M >> truthCnt;
    answer = M;

    for(int i = 0; i < truthCnt; i++){
        int input;
        cin >> input;
        knowTruth[input] = 1;
    }

    for(int i = 1; i <= M; i++){
        int party_pool, party_member;
        cin >> party_pool;
        for(int j = 0; j < party_pool; j++){
            cin >> party_member;
            arr[i][party_member] = i;
            if(knowTruth[party_member]) truth_party.push_back(i);
        }
    }
    for(auto party_idx : truth_party){
        if(visited[party_idx]) continue;
        dfs(party_idx);
    }
    cout << answer << "\n";
    return 0;
}