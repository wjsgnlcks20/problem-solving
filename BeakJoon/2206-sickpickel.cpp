#include <bits/stdc++.h>
#define Max 1001

using namespace std;

typedef char(*parr)[Max];

int N, M;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int visited[Max][Max][2] = {};

int bfs(parr map){
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    visited[0][0][0] = 1;

    while(!q.empty()){
        int now_y = q.front().first.first;
        int now_x = q.front().first.second;
        int broke = q.front().second;
        int dist = visited[now_y][now_x][broke];
        q.pop();
        
        if(now_y == N - 1 && now_x == M - 1) return dist;

        for(int i = 0; i < 4; i++){
            int next_y = now_y + dy[i];
            int next_x = now_x + dx[i];
            int newbroke = broke;
            if(next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
            if(visited[next_y][next_x][broke]) continue;
            if(map[next_y][next_x] == '1'){
                if(broke) continue;
                newbroke = 1;
            }
            visited[next_y][next_x][newbroke] += dist + 1;
            q.push({{next_y, next_x}, newbroke});
        }
    }
    return -1;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char map[Max][Max];
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    cout << bfs(map) << "\n";
    return 0;
}