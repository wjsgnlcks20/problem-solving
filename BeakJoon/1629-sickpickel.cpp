#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll multiplyBigNum(ll a, ll b, ll c){
	ll ret = 1;	
	while(b){
		if(b&1){
			(ret *= a) %= c;
			b--;
		}
		else{
			(a *= a) %= c;	
			b /= 2;	
		}
	}
	return ret;
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	
	ll A, B, C;
	cin >> A >> B >> C;
	cout << multiplyBigNum(A, B, C);
	
	return 0;
}