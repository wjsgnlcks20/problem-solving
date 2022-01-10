#include <bits/stdc++.h>
#define Max 200001

using namespace std;

typedef long long ll;

int arr[Max];

ll calculateSum(const ll mid, const ll sum, const ll N){
	ll ret = sum;
	ll sub = 0;
	
	for(ll i = 0; i <= mid && i < N; i++){
		ll x = mid - i;	
		if(i) sub += arr[N - i];	
		ret = min(ret, sum - x + i * (arr[0] - x) - sub);
	}
	return ret;
}

void solve(){
	ll N, K, firstSum = 0;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> arr[i];	
		firstSum += arr[i];
	}
	if(firstSum <= K) { cout << "0\n"; return; }
	
	sort(arr, arr + N);
	ll left = 0, right = firstSum - K;
	ll answer = right;
		
	while(left <= right){
		ll mid = (left + right) / 2;
		
		ll sum = calculateSum(mid, firstSum, N);
	
		if(sum <= K){
			answer = min(answer, mid);
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << answer << "\n";
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}