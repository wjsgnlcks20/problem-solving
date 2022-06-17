/* 재채점으로 인해 틀려 코드를 수정한 문제.
    N의 최대 크기가 50만이므로 더해질 크기가
    25만, 12.5만,,, 해서 총 약 50만이고,
    따라서 100만이었던 배열크기를 늘렸다.
*/
#include <stdio.h>
#define MAX 1100000

int main(void)
{
	int arr[MAX];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	int end = n;
	for (int i = 0; arr[i] > 0; i++)
	{
		if (i % 2) {
			arr[end] = arr[i];
			end++;
		}
	}
	printf("%d\n", arr[--end]);
}