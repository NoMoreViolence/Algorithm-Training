// https://www.acmicpc.net/problem/4673     셀프 넘버: 4673번
#include <stdio.h>
// 셀프 넘버 찾는 함수
int SN(int d);
// 담을 배열
int self_number[10001];

int main()
{
  // for 문 변수
  int i;

  // 1 부터 9999 까지 셀프 넘버 찾는 함수를 통해서 그 숫자의 배열의 값을 더해줌 리턴되는 값은 셀프 넘버가 아니기 때문
  for (i = 1; i < 10000; i++)
  {
    self_number[SN(i)]++;
  }

  // 배열이 0인 배열만 셀프 넘버이기 때문이다
  for (i = 1; i < 10000; i++)
  {
    if (self_number[i] == 0)
    {
      printf("%d\n", i);
    }
  }
}

// 셀프 넘버 찾는 함수
int SN(int d)
{
  d = d + d / 1000 + (d % 1000 / 100) + (d % 100 / 10) + (d % 10);
  return d;
}