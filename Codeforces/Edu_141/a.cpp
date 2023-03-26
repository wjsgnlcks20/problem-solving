#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int N;
    cin >> N;
    int * arr = new int[N + 1];

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);
    reverse(arr, arr + N);
    if(arr[N - 1] == arr[0]) {cout << "NO\n"; return; }

    cout << "YES\n";
    cout << arr[N - 1] << " ";
    for(int i = 0; i < N - 1; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}