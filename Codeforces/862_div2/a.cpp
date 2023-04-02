#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n, maxx = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = arr[0];
    for (int i = 1; i < n; i++){
        ans ^= arr[i];
    }
    if (n % 2 == 0 && ans != 0){
        cout << "-1\n";
        return ;
    }
    cout << ans << "\n";

}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}