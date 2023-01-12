#include <bits/stdc++.h>
#define Max 1000000

using namespace std;

int N, M;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end)    // 노드가 리프 노드인 경우
        return tree[node] = arr[start];    // 배열의 그 원소를 가져야 함

    int mid = (start + end) / 2;
    return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

long long getmin(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return INT_MAX;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return min(getmin(tree, node*2, start, mid, left, right) + getmin(tree, node*2+1, mid+1, end, left, right));
}

int isPossible(int mid, vector<vector<int>>& arr, vector<int>& node, vector<int>&tree){
    for(int i = 0; i < N - mid + 1; i++){
        for(int j = 0; j < M - mid + 1; j++){
            int mmin = Max;
            for(int k = i; k < i + mid; k++){
                mmin = getmin(tree, node, 0, N * M - 1, k * M + j, k * M + j + mid);
            }
        }
        return mmin;
    }
    return 0;
}

void solve(){
    cin >> N >> M;

    vector<int> v(M + 1, 0);
    vector<vector<int>> arr(N + 1, v);
    vector<int> node(N * M, 0);
    vector<int> tree(4 * N * M, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
            node[i * M + j] = arr[i][j];
        }
    }
    init(node, tree, 0, 0, N * M - 1);

    int left = 0, right = 1000000;
    int ans = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        if(isPossible(mid, arr, node, tree)){
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}