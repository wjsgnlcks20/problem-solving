#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){  
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    int inc = 1, dec = N * N;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0){
            for(int j = 0; j < N; j++){
                if(j % 2 == 0) arr[i][j] = inc++;
                else arr[i][j] = dec--;
            }
        }
        if(i % 2){
            for(int j = N - 1; j >= 0; j--){
                if(j % 2) arr[i][j] = inc++;
                else arr[i][j] = dec--;
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}