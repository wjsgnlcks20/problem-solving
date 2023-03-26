#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    if (b[n - 1] < a[n - 1]){
        int temp = b[n - 1];
        b[n - 1] = a[n - 1];
        a[n - 1] = temp;
    }
    for (int i = 0; i < n; i++){
        if (a[n - 1] < a[i]){
            if (a[n - 1] < b[i]){
                cout << "NO\n";
                return ;
            }
            int temp = b[i];
            b[i] = a[i];
            a[i] = temp;
        }
    }
    int b_last = b[n - 1];
    sort(b.begin(), b.end());
    if(b_last != b.back()){
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}