#include <bits/stdc++.h>
#define Max 10001

using namespace std;

void solve(){
    int n, l, r;
    vector<int> a;
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++){
        int share = (l - 1) / (i + 1);
        a.push_back((share + 1) * (i + 1));
        if(a[i] > r) {cout << "NO\n"; return;}
    }
    cout << "YES\n";
    for(auto elem: a){
        cout << elem << " ";
    } 
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}    