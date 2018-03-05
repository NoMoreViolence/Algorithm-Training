// https://www.acmicpc.net/problem/1977     완전제곱수: 1977
#include <stdio.h>
int main()
{
  int input_min, input_max,
      min = 100000, sum = 0;

  scanf("%d %d", &input_min, &input_max); // N <= 제곱수 <= M 의 값 영역 입력

  // N의 루트 부터 시작할 수도 있었지만 그냥 1부터 하는게 편해서 1부터 시작
  // 제곱을 했을때 완전제곱수가 되는 가장 큰 경우는 2 * 2 = 4 가 되는 경우로 1 / 2의 경우라 M / 2 까지만 숫자를 비교했다
  for (int i = 1; i <= input_max / 2; i++)
  {
    if (i * i >= input_min && i * i <= input_max) // 완전 제곱수라면
    {
      min = min > (i * i) ? i * i : min; // 가장 작은 완전제곱수
      sum += i * i;                      // 합
    }
  }

  if (sum != 0) // 제곱수가 하나라도 있었다면
  {
    printf("%d\n%d", sum, min);
  }
  else //없다면
  {
    printf("%d", -1);
  }
}