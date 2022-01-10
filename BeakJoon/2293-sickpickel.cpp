#include <bits/stdc++.h>
#define Max 101 

using namespace std;

int N, K;
int value[Max];
int dp[10001];

int main(void){
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> value[i];
	}
	
	dp[0] = 1;
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			if(value[i] <= j){
				dp[j] += dp[j - value[i]];
			}
		}	
	}

	cout << dp[K] << "\n";
	return 0;
}