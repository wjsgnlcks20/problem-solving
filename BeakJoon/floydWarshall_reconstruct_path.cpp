#include <bits/stdc++.h>
#define INF 100000
#define Max 100

using namespace std;

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int N, M, start, end;
	int arr[Max][Max], pi[Max][Max];
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) arr[i][j] = INF;
	for(int i = 0; i < M; i++){
		int S, E, W;
		cin >> S >> E >> W;
		if(arr[S][E] < W) continue;
		arr[S][E] = W;
		arr[E][S] = W;
		pi[S][E] = S;
	}
	
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(arr[i][j] > arr[i][k] + arr[k][j]){
					arr[i][j] = arr[i][k] + arr[k][j];	
					pi[i][j] = pi[j][k];
				}
			}
		}
	}
	
	int now;	
	vector<int> save;

	cin >> start >> end;
	now = end;
	save.push_back(end);
	while(pi[start][now] != start)	{
		save.push_back(pi[start][now]);
		now = pi[start][now];
	}
	cout << "shortest path : ";
	for(auto nodes : save){
		cout << nodes << " ";
	}
	return 0;
}