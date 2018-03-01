// https://www.acmicpc.net/problem/13900      순서쌍의 곱의 합: 13900
/*
  으아아아아악
  long 형은 반드시 %ld로 출력해야 합니다...
  푼 방식은
  먼저 숫자 범위값 받고
  그 범위값 만큼 숫자 받은 다음에
  계산을 하는 형식으로 했었는데
  그랬더니 시간초과가 날 수밖에 없는 환경이여서
  먼저 순서쌍의 숫자가 4개라고 가정합니다
  1 , 2, 3, 4

  그렇다면 1이 곱해져야 되는 순서쌍은 2 3 4인데
  그러면 1 * 2 + 1 * 3 + 1 * 4 가 됩니다
  하지만 이러면 계산이 복잡하니
  1 * (2 + 3 + 4) 이런식으로 하기로 했습니다
  그래서 저 pair라는 배열에
  첫번째 부터 i 번째 까지의 합을 담고
  그 합을 이용해서 다음 배열에서
  뒤에서 부터 처음까지 곱해서 내려오면 답을 구할 수 있습니다
*/
#include <stdio.h>
int main()
{
  int input,
      numbers[100000];

  long int pair[100000],
      sum = 0,
      temp = 0;

  scanf("%d", &input);

  for (int i = 0; i < input; i++)
  {
    scanf("%d", &numbers[i]);
    temp += numbers[i];
    pair[i] = temp;
  }

  for (int i = input - 1; i > 0; i--)
  {
    sum += pair[i - 1] * numbers[i];
  }

  printf("%ld", sum);
}