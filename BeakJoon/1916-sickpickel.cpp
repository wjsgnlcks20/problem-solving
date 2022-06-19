#include <bits/stdc++.h>
#define Max 1001
#define INF 100001

using namespace std;

typedef int(*parr)[Max];

int djik(int start, int end, int N, parr bus){

	int visited[Max] = {};
	priority_queue<pair<int,int>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int now = pq.top().second;
		int dist_quickest = -pq.top().first;
		pq.pop();
		
		if(visited[now]) continue;
		visited[now] = 1;
		
		if(now == end){
			return dist_quickest;
		}
		
		for(int i = 1; i <= N; i++){
			if(visited[i] || bus[now][i] == INF) continue;
			pq.push({-(dist_quickest + bus[now][i]), i});
		}
	}
	return -1;	
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	int N, M, bus[Max][Max];
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) bus[i][j] = INF;
	
	for(int i = 0; i < M; i++){
		int s, e, c;
		cin >> s >> e >> c;	
		bus[s][e] = min(bus[s][e], c);
	}
	
	int start, end;
	cin >> start >> end;
	cout << djik(start, end, N, bus) << "\n";
	
	return 0;
}