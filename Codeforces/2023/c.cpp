#include <bits/stdc++.h>
#define INF 9876543212345L
 
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    while(1){
        ll r = a%b;
        if(r==0) return b;
        a = b;
        b = r;
    }
}
vector<ll> getAllPrimeUntil(ll number){
    vector<ll> ret;
    for(ll cur = 2; cur <= number; cur++){
        ll divisor_cnt = 2;

        for(ll i = 2; i * i <= cur; i++){
            if(cur % i == 0) divisor_cnt++;
        } 
        if(divisor_cnt == 2) ret.push_back(cur);
    }
    return ret;
}
void solve(){
    int N;
    cin >> N;
    ll * arr = new ll[N];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i < N; i++){
        if(arr[i - 1] == arr[i]) {
            cout << "NO\n"; return;
        }
    }
    ll saveMinGCD = INF;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            ll nowgcd = gcd(arr[i], arr[j]);
            saveMinGCD = min(saveMinGCD, nowgcd);
        }
    }
    unordered_map<int, int> um;
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            ll nowgcd = gcd(arr[i], arr[j]);
            // 현재 gcd의 약수 중 minGcd보다 작다면 체크한다.
            vector<ll> divisors = getAllPrimeUntil(nowgcd);
            for(auto elem : divisors){
                if(elem <= saveMinGCD){
                    um[elem] = 1;
                }
            }
            // 이때 minGcd보다 작은 수 중 체크되지 않은 수가 있는 경우 x 존재
        }
    }
    for(int i = 0; i < saveMinGCD; i++){
        if(um[i] != 1) { cout << "YES\n"; return; }
    }    
    cout << "NO\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}