// https://www.acmicpc.net/problem/2018     수들의 합: 2108
#include <stdio.h>
int main()
{
    int input,      // 수들의 합을 구할 인풋값
        answer = 0, // 수들의 합의 개수
        i,          // for
        j;          // for

    scanf("%d", &input);

    // (i+1) + (i+2) + ... + (i+n) = input
    // (1 + 2 + ... + n) + i * n = input
    for (i = 1, j = 0; (j += i) <= input; i++)
    {
        // (input - (1 + 2 + ... + n) ) % n == 0
        if ((input - j) % i == 0)
        {
            // 조건성립
            answer++;
        }
    }

    printf("%d", answer);
}