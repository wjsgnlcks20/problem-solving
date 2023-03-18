#include <iostream>

using namespace std;

void solve(){
    int a, b, c, d;
    int ans = 0;
    int temp = 0;
    cin >> a >> b >> c >> d;
    temp = d - b;
    if (temp < 0) {
        cout << "-1\n";
        return ;
    }
    a += temp;
    ans += temp;
    temp = a - c; 
    if (temp < 0){ 
        cout << "-1\n";
        return ;
    }
    ans += temp;
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}