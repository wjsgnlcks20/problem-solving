#include <bits/stdc++.h>
#define Max 501

using namespace std;

int main(void){
	int n, input;
	int dp[Max][Max];
	cin >> n;
	cin >> dp[0][0];
	for(int i = 1; i < n; i++){
		cin >> dp[i][0];
		dp[i][0] += dp[i - 1][0];
		for(int j = 1; j < i + 1; j++){
			cin >> dp[i][j];
			dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
		}
	}
	int answer = 0;
	for(int i = 0; i < n; i++){
		answer = max(answer, dp[n - 1][i]);
	}	
	cout << answer << "\n";
	return 0;
}