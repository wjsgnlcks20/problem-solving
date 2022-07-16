// 프로그래머스 쿠키구입
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    
    for(int i = 0; i < cookie.size() - 1; i++){
       	int left_idx = i; 
        int right_idx = i + 1;
        int left_sum = cookie[left_idx], right_sum = cookie[right_idx];
       	while(left_idx >= 0 && right_idx < cookie.size()){
            cout << left_idx << " " << right_idx << "\n"; 
            if(left_sum <= right_sum){
                if(left_sum == right_sum) answer = max(answer, left_sum);
                if(left_idx == 0) break;
                left_sum += cookie[--left_idx];
            }
            else {
               	if(right_idx == cookie.size() - 1) break;
                right_sum += cookie[++right_idx];
            }
        }
    }
    return answer;
}

/*

    <처음에 풀려고 했던 방식과 그 방법의 논리적 오류>

    문제를 아예 잘못 읽음으로써 접근이 어긋났다.
    m까지, 그리고 m + 1부터 2개의 쿠기 집합이 서로 붙어있다는 사실을 모르고
    서로 겹치지 않은 가능한 모든 2개의 집합의 경우에서 두 집합의 합이 같은 경우를 찾으려고하여
    정답을 얻을 수 없었다.
    위의 조건만 제대로 읽었더라면 투포인터로 빠르게 해결할 수 있었던 문제...

*/
