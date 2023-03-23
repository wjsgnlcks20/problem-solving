#include <bits/stdc++.h>

using namespace std;

int N, K;

int getsum(vector<int>& arr, pair<int, int> se){
    int ret = 0;
    for (int i = se.first; i <= se.second; i++){
        ret += arr[i];
    }
    return (ret);
}

void dfs(vector<int>& arr, int depth, vector<int> idx, int *pos, int *neg){
    if (depth == 2){
        int sum = getsum(arr, {idx[0], idx[1]});
        if (sum > 0)
            *pos = *pos + 1;
        else if (sum < 0)
            *neg = *neg + 1;
    }
    int before = idx.back();
    for(int i = before; i < N; i++){
        idx.push_back(i);
        dfs(arr, depth + 1, idx, pos, neg);
        idx.pop_back();
    }
}

void count_k(int * pos, int * neg, vector<int>& arr){
    vector<int> idx;
    dfs(arr, 0, idx, pos, neg);
}

void solve(){
    cin >> N >> K;
    vector<int> arr(N, 0);
    // binary search?
    int left, right;
    while (left <= right){
        int mid = (left + right);
        int positive, negative;
        count_k(&positive, &negative, arr);
        if (N * (N + 1) / 2 != positive + negative){

        }
        if (positive < K) {

        }
        else {

        }
    }
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}