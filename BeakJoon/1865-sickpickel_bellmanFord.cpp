#include <bits/stdc++.h>
#define Max 501
#define INF 987654321

using namespace std;

typedef int(*parr)[Max];
typedef pair<int, int> pii;

int N;

bool doesNegetiveCycleExist(int V, vector<pair<pii, int>> edges){
	bool flag = 0;
	int dist[Max];
	fill(dist + 1, dist + V + 1, INF);
		
	for(int i = 0; i < V; i++){
		for(auto edge : edges){
			int now = edge.first.first;
			int next = edge.first.second;
			int cost = edge.second;
			if(dist[next] > dist[now] + cost){
				dist[next] = dist[now] + cost;	
				if(i == V - 1) flag = 1;
			}
		}	
	}
	return flag;
}

void solve(){
	int M, W;
	vector<pair<pii, int>> arr;
	cin >> N >> M >> W;
	
	for(int i = 0; i < M; i++){
		int S, E, T;
		cin >> S >> E >> T;
		arr.push_back({{S, E}, T});
		arr.push_back({{E, S}, T});
	}
	for(int i = 0; i < W; i++){
		int S, E, T;
		cin >> S >> E >> T;
		arr.push_back({{S, E}, -T});
	}
	cout << (doesNegetiveCycleExist(N, arr) ? "YES" : "NO") << "\n";	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int tc; cin >> tc;
	while(tc--) solve();
	return 0;
}