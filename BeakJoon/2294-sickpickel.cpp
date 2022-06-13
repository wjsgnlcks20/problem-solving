#include <bits/stdc++.h>
#define Max 101
#define INF 10001 

using namespace std;

int value[Max];
int dp[10001];

int main(void){
	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> value[i];
	}
	
	dp[0] = 0;
	for(int i = 1; i <= K; i++){
		dp[i] = INF;
		for(int j = 1; j <= N; j++){
			if(value[j] <= i){
				dp[i] = min(dp[i], dp[i - value[j]] + 1);
			}
		}
	}	
	if(dp[K] == INF) cout << "-1\n";
	else cout << dp[K] << "\n";
	return 0;
}