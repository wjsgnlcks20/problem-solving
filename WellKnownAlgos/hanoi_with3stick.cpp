#include <stdio.h>
#include <math.h>

int move_cnt = 0;

void hanoi_tower(int n, int cur, int mid, int desti){
    if(n == 0) return;
    hanoi_tower(n - 1, cur, desti, mid);
    printf("%d -> %d\n", n, desti);
    move_cnt++;
    hanoi_tower(n - 1, cur, mid, desti);
}

void validate_algorithm(int n){
    const int validated_move_cnt = (int)pow(2, n) - 1;
    printf("%d %d\n", move_cnt, validated_move_cnt);

    if(move_cnt == validated_move_cnt) 
        printf("the algorithm is correct\n");
    else 
        printf("the algorithm is wrong\n");
}

int main(void){
    // cur은 현재 타워가 위치한 기둥
    // desti는 타워를 위치시키려고 하는 기둥
    // mid는 그 이외 거쳐가는 기둥
    int n, cur = 1, mid = 2, desti = 3;
    scanf("%d", &n);
    if(n % 2) hanoi_tower(n, cur, mid, desti);
    else hanoi_tower(n, cur, desti, mid);

    validate_algorithm(n);
    return 0;
}