// 프로그래머스 사칙연산
#include <vector>
#include <iostream>
#include <string>
#define Max 1000
#define INF 987654321
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    int min_dp[Max][Max] = {};
    int max_dp[Max][Max] = {};
    for(int i = 0; i < arr.size(); i++){
        for(int j = i; j < arr.size(); j++){
            min_dp[i][j] = INF;
            max_dp[i][j] = -INF;
        }
    }
    for(int i = 0; i < arr.size(); i += 2){
       min_dp[i][i] = max_dp[i][i] = stoi(arr[i]);
    }
    int operator_cnt = arr.size() / 2;
    for(int len = 1; len <= operator_cnt; len++){
        for(int start = 0; start < arr.size() - len * 2; start += 2){
            int end = start + len * 2;
            int save_min = INF, save_max = -INF;
            for(int oper_idx = start + 1; oper_idx < end; oper_idx += 2){
                if(arr[oper_idx] == "+"){
                    save_min = min(save_min, min_dp[start][oper_idx-1] + min_dp[oper_idx+1][end]);
                    save_max = max(save_max, max_dp[start][oper_idx-1] + max_dp[oper_idx+1][end]);
                }
                else{
                   	save_min = min(save_min, min_dp[start][oper_idx-1] - max_dp[oper_idx+1][end]) ;
                   	save_max = max(save_max, max_dp[start][oper_idx-1] - min_dp[oper_idx+1][end]) ;
                }
            }
            min_dp[start][end] = min(min_dp[start][end], save_min);
            max_dp[start][end] = max(max_dp[start][end], save_max);
        }
    }
   	answer = max_dp[0][arr.size() - 1]; 
    return answer;
}


/*
    <처음에 풀려고 했던 방식과 그 방법의 논리적 오류>

    백준에 이 문제와 비슷하게 괄호를 자유롭게 쳐서 수식의 최솟값을 구하는 문제가 있다. 
    이 경우에는 제일 처음 나온 음수부터 모든 수를 괄호를 사용해 음수로 만듦으로써 
    (음수가 나오기 전 양수 뭉텅이) - (음수 이후의 수들의 합) 으로 최솟값을 구했다.
    이에 착안하여 단순하게 (양수) - (첫 음수부터 이후의 수) 형태에서 
    (첫 음수부터 이후의 수) 부분의 최솟값을 구한다면 전체 식의 최댓값을 구할 수 있을 것이라고 착각했다.

    다만 이 논리의 반례는, 
    (양수) = S, (첫 음수부터의 수) = m, (구하려는 최댓값) = M이라 할 때,
    S - m = M이라고 가정하자.
    m의 구성이 (a, +b, +c, - k) 이고 이들의 합이 m_s일때, (a, b, c, k는 모두 양수이며 m도 양수) 
    m의 최솟값은 괄호를 칠 필요도 없이 m_s임을 알 수 있고, 전체 식에서
    [S - (a + b + c - k)] 보다 [S - a + b + c - k]로 더 큰 값을 구할 수 있음을 알 수 있다.
    따라서 위의 방식으로는 식의 최댓값을 구할 수 없다.

*/