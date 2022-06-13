#include <bits/stdc++.h>
#define Max 100001

using namespace std;

void solve(){
	int n, arr[Max];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];	
	}
	
	sort(arr, arr + n);
	int mostCnt = 1, nowCnt = 1, now = arr[0]; 
	for(int i = 1; i < n; i++){
		if(now == arr[i]) nowCnt++;
		else {
			now = arr[i];
			nowCnt = 1;
		}
		mostCnt = max(mostCnt, nowCnt);
	}
	int leftCnt = n - mostCnt, answer = 0;
	while(leftCnt > 0) {
        answer += (min(mostCnt, leftCnt) + 1);
		leftCnt -= mostCnt;
		mostCnt *= 2;
	}
	cout << answer << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}