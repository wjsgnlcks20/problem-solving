#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int R, C, answer = 0;

void dfs(int y, int x, int * visited, vector<vector<char>>& arr, int depth){
    answer = max(answer, depth);
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if(visited[arr[ny][nx] - 'A']) continue;

        visited[arr[ny][nx] - 'A'] = 1;
        dfs(ny, nx, visited, arr, depth + 1);
        visited[arr[ny][nx] - 'A'] = 0;
    }
}

void solve(int test_case){
    answer = 0;

    cin >> R >> C;

    int visited[26] = {};
    vector<vector<char>> arr(R + 1, vector<char>(C + 1));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> arr[i][j];
        }
    }

    visited[arr[0][0] - 'A'] = 1;
    dfs(0, 0, visited, arr, 1);
    
    cout << "#" << test_case << " ";
    cout << answer << "\n";
}

int main(void){
    int t; cin >> t;
    int tidx = 0;
    while(t--) solve(++tidx);
    return 0;
}