#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;

typedef long long ll;

ll min(ll a, ll b){
    if(a > b) return a;
    else return b;
}
void printArr(vector<int>&arr, string arrayName){
    cout << "print " << arrayName << "\n";
    int len = arr.size();
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
 
void solve(){
    int N;
    ll M, input;
    int a[MAX] = {};
    cin >> N >> M;
    vector<pair<ll, ll>> arr(N);
    vector<int> mywincheck(N), wincnt(N, 0);
    for(int i = 0; i < N; i++){
        cin >> input;
        arr[i] = {input, i};
        wincnt[i] = i;
    }
    sort(arr.begin(), arr.end());

    // 마지막 1개 전까지 최대한 많은 승리.
    ll sum = 0, idx = 0, mywincnt = 0;
    while(idx < N) {
        if(sum + arr[idx].first > M) {
            idx--;
            sum -= arr[idx].first;
            mywincheck[arr[idx].second] = 0;
            break;
        }
        sum += arr[idx].first;
        mywincheck[arr[idx].second] = 1;
        idx++;
    }
    for(int i = 0; i < N; i++){
        if(mywincheck[i]) mywincnt++;
    }
    // 승리할 수 있는 1개 중 가장 높은 최종 순위를 할 수 있는 것.
    // 경기하지 않은 사람 중, 더했을 때 m이 넘지 않으면서 승리 횟수가 1회 높은 사람
    int flag = 0;
    for(int i = idx; i < N; i++){
        if(sum + arr[i].first > M) break;
        if(wincnt[arr[i].second] - 1 == mywincnt) {
            mywincnt++;
            mywincheck[arr[i].second] = 0;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        for(int i = idx; i < N; i++){
            if(sum + arr[i].first > M) break;
            mywincnt++;
            mywincheck[arr[i].second] = 0;
            break;
        }
    }
    printArr(wincnt, "wincnt");
    for(int i = 0; i < N; i++){
        if(mywincheck[i] == 0) wincnt[i]++;
    }
    int answer = 1;
    for(int i = 0; i < N; i++){
        if(mywincnt < wincnt[i]) answer++;
    }
    cout << answer << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}