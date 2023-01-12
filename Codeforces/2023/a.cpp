#include <bits/stdc++.h>
#define INF 987654321
 
using namespace std;
 
void solve(){
    int N, M, input;
    long long sum = 0;
    cin >> N >> M;
    priority_queue<int> a;
    for(int i = 0; i < N; i++){
        cin >> input;
        a.push(-input);
    }
    for(int i = 0; i < M; i++){
        cin >> input;
        a.pop();
        a.push(-input);
    }
    while(!a.empty()){
        sum += -a.top();
        a.pop();
    }
    
    cout << sum << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}