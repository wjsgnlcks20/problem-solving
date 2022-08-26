#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    vector<int> test{1, 2, 3, 4, 5};
    sort(test.begin(), test.end(), greater<int>());
    for(int elem : test){
        cout << elem << " ";
    }
    return 0;
}