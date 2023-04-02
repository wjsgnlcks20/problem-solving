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
        maxx = max(maxx, arr[i]);
    }
    int check = 1;
    int ans = 0;
    if (n % 2 == 0){
        while (maxx * 2) {
            int cur = 0;
            for (int i = 0; i < n; i++){
                cur += arr[i] % 2;
                arr[i] /= 2;
            }
            if (cur % 2) {
                cout << "-1\n";
                return ;
            }
            maxx /= 2;
        }
        cout << "0\n";
    }
    else {
        while (maxx * 2){
            int cur = 0;
            for (int i = 0; i < n; i++){
                cur += arr[i] % 2;
                arr[i] /= 2;
            }
            if (abs(cur - (n - cur)) == 1) {
                ans += check * (cur % 2 ? 1 : 0);
            }
            else if (abs(cur - (n - cur)) != 0){
                cout << "-1\n";
                return ;
            }
            check *= 2;
            maxx /= 2;
        }
        cout << ans << "\n";
    }
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}