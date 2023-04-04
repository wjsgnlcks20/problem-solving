#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n, t;
    string s;
    cin >> n >> t >> s;
    int idx = -1;
    int flag = 0;
    for (int i = 0; i < n; i++){
        if (t > s[i] - '0') {
            idx = i;
            break ;
        }
    }
    if (idx < 0) {
        idx = n;
    }
    s.insert(s.begin() + idx, t + '0');
    cout << s << "\n";

    // if (idx == n) {
    //     cout << s << t << "\n";
    // }
    // else {
    //     }
    // s.insert(idx, t + '0');
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}