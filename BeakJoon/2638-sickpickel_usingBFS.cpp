#include <bits/stdc++.h>
#define Max 101

using namespace std;

typedef int(*parr)[Max];

int N, M;
int cheese[Max][Max];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int cnt_out_sides(int y, int x){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(cheese[ny][nx] == 2) ret++;
    }
    return ret;
}

int refreash_air(int sy, int sx){
    int is_cheese = 0, visited[Max][Max] = {};
    visited[sy][sx] = 1;
    cheese[sy][sx] = 2;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx]) continue;
            if(cheese[ny][nx] == 1) {
                is_cheese = 1;
                continue;
            }
            visited[ny][nx] = 1;
            cheese[ny][nx] = 2;
            q.push({ny, nx});
        } 
    }
    return is_cheese;
}

void printCheese(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << cheese[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int after_a_hour(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cheese[i][j] != 1) continue;
            int outside_cnt = cnt_out_sides(i, j);
            if(outside_cnt >= 2) cheese[i][j] = 3;
        }
    }
    return refreash_air(0, 0);
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> cheese[i][j];
        }
    }
    int answer = 0;
    refreash_air(0, 0);
    while(after_a_hour()){
        answer++;
    }
    cout << answer + 1 << "\n";
    return 0;
}