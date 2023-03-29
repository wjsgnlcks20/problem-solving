#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

int getlucky(int i){
    int mx = 0, mn = 10;
    while (i){
        mx = max(mx , i % 10);
        mn = min(mn , i % 10);
        i /= 10;
    }
    return (mx - mn);
}
 
void solve(){
    int l, r;
    int savemax = 0, answer = 0;
    int limit = 101;
    cin >> l >> r;
    for (int i = l; i <= r && limit--; i++){
        int current = getlucky(i);
        if (savemax <= current){
            savemax = current;
            answer = i;
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