#include <bits/stdc++.h>
#define Max 100
#define INF 100000

using namespace std;

vector<int> sumVec(vector<int> arr1, vector<int> arr2){
	
	vector<int> tmp;
    int left = 0, right = 0;
	while(left < arr1.size() || right < arr2.size()){
		if(arr1[left] < arr2[right])	{
			tmp.push_back(arr1[left++]);
		}
		else if(arr1[left] > arr2[right]){
			tmp.push_back(arr2[right++]);
		}
		else { 
            tmp.push_back(arr1[left]);
            left++; right++; 
        }
	}	
		
	while(left < arr1.size()){
		tmp.push_back(arr1[left++]);
	}
	while(right < arr2.size()){
		tmp.push_back(arr2[right++]);
	}
	return tmp;
}

int main(void){
	int n;
	cin >> n;
	vector<int> arr[Max];
	
	for(int i = 1; i <= n; i++){
		arr[i].push_back(i);
	}
    vector<int> test1, test2, answer;    
    for(int i = 0; i < 10; i++) test1.push_back(i);
    for(int k = 4; k < 10; k++) test2.push_back(k);
    answer = sumVec(test1, test2);
    cout << "answer : ";
    for(auto elem : answer) cout << elem << " ";
    cout << endl;
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int left = 0, right = 0;	
				vector<int> tmp = sumVec(arr[i], arr[k]);
				arr[i].clear();
				for(auto elem: tmp) arr[i].push_back(elem);
				tmp.clear();
				tmp = sumVec(arr[j], arr[k]);
				arr[j].clear();
				for(auto elem: tmp) arr[j].push_back(elem);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << "node #" << i << "\n";
		cout << "connected node : ";
		sort(arr[i].begin(), arr[i].end());
		for(int j = 0; j < arr[i].size(); j++){
			if(j && arr[i][j-1] == arr[i][j] ) continue;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}