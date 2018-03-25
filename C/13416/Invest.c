// https://www.acmicpc.net/problem/13416      주식 투자: 13416
#include <stdio.h>
int main()
{
  int input,
      testcase,
      answer[100000],
      cmp = 0,
      temp = 0,
      a;

  // 처음 테스트 케이스 값 이 말인즉슨 테스트 케이스가 input 만큼 들어가기에 출력도 input 값 만큼 해줘야 한다는 뜻
  scanf("%d", &input);

  // 테스트 케이스 만큼 for 문이 돌고
  for (int i = 0; i < input; i++)
  {
    // 이건 각 테스트 케이스의 a b c 회사의 며칠간 입력을 받을지 결정하는 변수, testcase의 값이 3 이라면 a b c 회사의 3일간의 결과값을 데이터로 받는 것임
    scanf("%d", &testcase);
    // 그렇게 데이터를 받습니다
    for (int j = 0; j < testcase; j++)
    {
      // 이건 각 날짜마다 받는것 만약
      for (int k = 0; k < 3; k++)
      {
        scanf("%d", &a);
        // cmp의 의미: 최적의 투자 결과 변수, cmp를 0으로 해놓으면, a b c 회사의 모든 값이 마이너스라도 마이너스에 투자하지 않게 됨
        if (a > cmp)
        {
          cmp = a;
        }
      }
      // 그렇게 템프 값에 더해주고
      temp += cmp;
      // 다시 이 값을 초기화 시켜서 다음 for 문을 대비
      cmp = 0;
    }
    // 이런식으로 다 모은 temp 최적의 주식 데이터를 answer[i]에 담는데, 이 값은 정답 데이터가 됨
    answer[i] = temp;
    // 다시 temp 주식 데이터도 초기화를 해 주어야 하고
    temp = 0;
  }

  // 정답 데이터를 순서대로 출력하면 끝
  for (int i = 0; i < input; i++)
  {
    printf("%d\n", answer[i]);
  }
}