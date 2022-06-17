#include <bits/stdc++.h>
#define Max 100001

using namespace std;

int visited[Max];
int maxDist = 0, endVertex;
vector<pair<int,int>> tree[Max];

void dfs(int now, int dist){
    visited[now] = 1;
    if(maxDist < dist) {
        maxDist = dist;
        endVertex = now;
    }    
    for(auto next : tree[now]){
        if(visited[next.first]) continue;
        dfs(next.first, dist + next.second);
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V, vertex_num;
    cin >> V;
    for(int i = 0; i < V; i++){
        cin >> vertex_num;
        int to, length;
        while(1){
            cin >> to;
            if(to == -1) break;
            cin >> length;
            tree[vertex_num].push_back({to, length});
        }
    }
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(endVertex, 0);
    cout << maxDist << "\n";
    return 0;
}