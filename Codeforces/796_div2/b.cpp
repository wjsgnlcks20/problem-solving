#include <bits/stdc++.h>
#define Max 200001
#define INF 1000

using namespace std;

int arr[Max];

int countEven(int * arr, int size){
	int ret = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] % 2 == 0) ret++;
	}
	return ret;
}

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int evenCount = countEven(arr, n);
	if(evenCount == n){
		int answer = INF;
		for(int i = 0; i < n; i++){
			int tmp = arr[i], divdCnt = 0;
			while(tmp % 2 == 0){
				tmp /= 2;	
				divdCnt++;
			}
			answer = min(answer, divdCnt);
		}	
		answer += n - 1;
		cout << answer << "\n";
	}
	else {
		cout << evenCount << "\n";
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}