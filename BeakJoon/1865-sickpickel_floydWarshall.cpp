#include <bits/stdc++.h>
#define Max 501
#define INF 10001

using namespace std;

void solve(){
	int N, M, W;	
	cin >> N >> M >> W;
	int ways[Max][Max];
	for(int i = 1; i <= N; i++) 
		for(int j = 1; j <= N; j++) 
		{ ways[i][j] = INF; if(i == j) ways[i][j] = 0; }
	
	int S, E, T;
	for(int i = 0; i < M; i++){
		cin >> S >> E >> T;
		if(ways[S][E] < T) continue;
		ways[S][E] = T;
		ways[E][S] = T;
	}
	
	for(int i = 0; i < W; i++){
		cin >> S >> E >> T;
		ways[S][E] = -T;
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 1; k <= N; k++)	{
				ways[j][k] = min(ways[j][k], ways[j][i] + ways[i][k]);
			}
		}
	}
	for(int i = 1; i <= N; i++){
		if(ways[i][i] != 0) { cout << "YES\n"; return; }
	}
	cout << "NO\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int tc; cin >> tc;
	while(tc--) solve();
	return 0;
}