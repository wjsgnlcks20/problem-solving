#include <bits/stdc++.h>
#define INF 1000001
#define Max 1001

using namespace std;

void djik(int start, int * dist, vector<vector<pair<int,int>>>& map){

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    for(int i = 1; i <= map.size(); i++) dist[i] = INF;
    dist[start] = 0;

    while(!pq.empty()){
        int dist_quickest = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist[now] != dist_quickest) continue;

        for(auto next_info : map[now]){
            int next = next_info.first, cost = next_info.second;
            if(dist[next] <= dist_quickest + cost) continue;
            dist[next] = dist_quickest + cost;
            pq.push({dist[next], next});
        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, X;
    cin >> N >> M >> X;
    vector<vector<pair<int, int>>> roads(N+1), roads_rev(N+1);

    for(int i = 0; i < M; i++){
        int s, e, t;
        cin >> s >> e >> t;
        roads[s].push_back({e, t});
        roads_rev[e].push_back({s, t});
    }
    int dist[Max] = {}, dist_rev[Max] = {};
    djik(X, dist_rev, roads_rev);
    djik(X, dist, roads);
    int answer = 0;
    for(int i = 1; i <= N; ++i){
        answer = max(answer, dist[i] + dist_rev[i]);
    }
    cout << answer << "\n";
    return 0;
}