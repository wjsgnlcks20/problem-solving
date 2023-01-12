#include <bits/stdc++.h>
#define INF 987654321
 
using namespace std;
 
void solve(){
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N / 2; i++){
        cout << N - i << " " << i + 1 << " ";
    }
    if(N % 2 == 1) cout << N / 2 + 1;
    cout << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}