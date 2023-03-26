#include <bits/stdc++.h>
#define MAX // 200001 
#define INF 987654321
 
using namespace std;
 
void solve(){
    int M;
    cin >> M;
    vector<vector<int>> data;
    map<int, int> mp;
    for (int i = 0; i < M; i++){
        int N;
        cin >> N;
        vector<int> parti(N);
        for (int j = 0; j < N; j++){
            cin >> parti[j];
            if (mp.find(parti[j]) == mp.end())
                mp.insert({parti[j], 0});
        }
        data.push_back(parti);
    }
    vector<int> answer;
    reverse(data.begin(), data.end());
    for (vector<int>& elem : data){
        int flag = 0;
        for(int i = 0; i < elem.size(); i++){
            if(mp[elem[i]] == 0 && !flag){
                answer.push_back(elem[i]);
                flag = 1;
            }
            mp[elem[i]]++;
        }
        if (flag == 0){
            cout << "-1\n";
            return ;
        }
    }
    reverse(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
}
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}