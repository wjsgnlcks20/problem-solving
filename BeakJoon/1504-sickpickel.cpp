#include <bits/stdc++.h>
#define Max 80
#define INF 987654321

using namespace std;

typedef int(*parr)[Max];

int get_shortestWay_len(int start, int end, const int node_cnt, parr graph){
    int visited[Max] = {};

    priority_queue<pair<int, int>> pq; 
    pq.push({0, start});

    while(!pq.empty()){
        int now = pq.top().second;
        int dist_quickest = -pq.top().first;
        pq.pop();

        if(visited[now]) continue;
        visited[now] = 1;

        if(now == end) return dist_quickest;

        for(int i = 1; i <= node_cnt; i++){
            if(visited[i] || graph[now][i] == 0) continue;
            pq.push({-(dist_quickest + graph[now][i]), i});
        }
    }
    return INF;
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, E, v1, v2;
    int graph[Max][Max] = {};

    cin >> N >> E;
    for(int i = 0; i < E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    cin >> v1 >> v2;

    long long way1, way2, v1_to_v2 = get_shortestWay_len(v1, v2, N, graph);

    way1 = get_shortestWay_len(1, v1, N, graph) + v1_to_v2 + get_shortestWay_len(v2, N, N, graph);
    way2 = get_shortestWay_len(1, v2, N, graph) + v1_to_v2 + get_shortestWay_len(v1, N, N, graph);
    long long answer = min(way1, way2);
    if(answer >= INF) cout << "-1\n";
    else cout << answer << "\n";

    return 0;
}