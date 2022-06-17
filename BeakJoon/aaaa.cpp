// 효율적인 해킹
#include <bits/stdc++.h>
#define Max 10001

using namespace std;

vector<int> connection[Max];
int memoization[Max], visited[Max];
int N, M, A, B;

void UpdateMemoization(int value){
	for(int i = 1; i <= N; i++){
		if(visited[i] == 2){
			memoization[i] = value;
		}
	}
}

int cycleStart = 0;

// 이 부분이 너무 복잡.
int countHackable(int now){
	visited[now] = 1;
	
	int &ref = memoization[now];
	if(ref != 0) return ref;
	
	for(auto next : connection[now]){
		if(visited[next]) {
			cycleStart = next;
			visited[now] = 2;
		}
		else ref += countHackable(next);

		if(visited[next] == 2)	{
			visited[now] = 2;
		}
		if(now == cycleStart){
			UpdateMemoization(ref);
			for(int i = 1; i <= N; i++) if(visited[i] == 2) visited[i] = 0;
			cycleStart = 0;
		}
	}
	ref++;
	
	return ref;
}

void clear(){
	for(int i = 1; i <= N; i++) visited[i] = 0;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	
	for(int i = 0; i < M; i++){
		cin >> A >> B;
		connection[B].push_back(A);
	}
	int save_max = 0;	

	for(int i = 1; i <= N; i++){
		int hackables = countHackable(i);
		cout << i << " " << hackables << "\n";
		save_max = max(save_max, hackables);
		clear();
	}
	for(int i = 1; i <= N; i++){ if(save_max == countHackable(i)) cout << i << " "; }
	return 0;
}