#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n, flag = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] <= i + 1){
            flag = 1;
        }
    }
    if (flag) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}