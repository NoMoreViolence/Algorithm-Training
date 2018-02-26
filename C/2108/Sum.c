// https://www.acmicpc.net/problem/2018     수들의 합: 2108

// (i+1) + (i+2) + ... + (i+n) = input
// 이걸 바꾸면
// (1 + 2 + ... + n) + i * n = input
// 밑의 식으로 된다면 가능한 것이다
// (input - (1 + 2 + ... + n) ) % n == 0

#include <stdio.h>

int main()
{
    int input,
        answer = 0,
        i,
        j,
        n;

    scanf("%d", &input);

    for (i = 1, j = 0; (j += i) <= input; i++)
    {
        if ((input - j) % i == 0)
        {
            answer++;
        }
    }

    printf("%d", answer);
}