#include <bits/stdc++.h>
#define INF 200001
#define Max 20001

using namespace std;

int V, E, K;

void djik(int start, int * dist, vector<vector<pair<int,int>>> & graph){
	fill(dist + 1, dist + V + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int now = pq.top().second;
		int dist_quickest = pq.top().first;
		pq.pop();
		
		if(dist_quickest != dist[now]) continue;
		
		for(auto next_info : graph[now]){
			int next = next_info.first, cost = next_info.second;
			if(dist[next] <= dist_quickest + cost) continue;
			dist[next] = dist_quickest + cost;
			pq.push({dist[next], next});
		}
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int u, v, w;
	cin >> V >> E >> K;
	
	vector<vector<pair<int,int>>> graph(V+1);
	
	for(int i = 0; i < E; i++){
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}	
	
	int dist[Max] = {};
	djik(K, dist, graph);
	
	for(int i = 1; i <= V; i++){
		if(dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	  
	return 0;
}