#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a_idx = 2, notA_idx = 3 * n;
    int cal_cnt = 0;
    vector<pair<int, int>> iandj;
    while(a_idx < notA_idx) {
        iandj.push_back({a_idx, notA_idx});
        cal_cnt++;
        notA_idx -= 3;
        a_idx += 3;
    }
    cout << cal_cnt << "\n";
    for(auto elem : iandj){
        cout << elem.first << " " << elem.second << "\n";
    } 
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}