#include <bits/stdc++.h>
#define Max 100001

using namespace std;

void solve(){
    int n, q;
    int tests[Max];
    vector<int> hard;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> tests[i];
        if(tests[i] > q) hard.push_back(i);
    }
    int left = 0, right = hard.size() - 1, min_idx = n;
    while(left <= right){
        int mid = (left + right) / 2;
        int cur_q = q, flag = 1;
        for(int i = hard[mid]; i < n; i++){
            if(cur_q == 0) { flag = 0; break;}
            if(tests[i] > cur_q) cur_q--;
        }
        if(flag){
            min_idx = hard[mid];
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    for(int i = 0; i < min_idx; i++){
        if(tests[i] > q) cout << "0";
        else cout << "1";
    } 
    for(int i = min_idx; i < n; i++){
        cout << "1";
    }
    cout << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) solve();
    return 0;
}

// define int long long, main -> signed로 했을 때 왜 런타임 에러가 가는건지...