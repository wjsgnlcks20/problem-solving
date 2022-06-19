#include <bits/stdc++.h>
#define Max 501
#define INF 987654321

using namespace std;

typedef int(*parr)[Max];
typedef pair<int, int> pii;

int N;

bool doesNegetiveCycleExist(int V, vector<pair<pii, int>> edges){
	bool update;
	int upper[Max];
	fill(upper + 1, upper + V + 1, INF);
	
	for(int i = 0; i < V; i++){
		update = 0;
		for(auto elem : edges){
			int now = elem.first.first;
			int next = elem.first.second;
			int cost = elem.second;
			if(upper[next] > upper[now] + cost){
				upper[next] = upper[now] + cost;
				update = 1;
			}
		}
		if(!update) return 0;
	}
	if(update) return 1;
	return 0;	
}

void solve(){
	int N, M, W;
	vector<pair<pii,int>> edges;
	cin >> N >> M >> W;
	for(int i = 0; i < M; i++){
		int S, E, T;
		cin >> S >> E >> T;
		edges.push_back({{S, E}, T});
		edges.push_back({{E, S}, T});
	}
	
	for(int i = 0; i < W; i++){
		int S, E, T;
		cin >> S >> E >> T;
		edges.push_back({{S, E}, -T});
	}
	
	cout << (doesNegetiveCycleExist(N, edges) ? "YES" : "NO") << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int tc; cin >> tc;
	while(tc--) solve();
	return 0;
}