// https://www.acmicpc.net/problem/1912     연속합: 1912
// 시간초과가 난 나의 소스에게 애도를 빕니다..
/*
#include <stdio.h>
int main()
{
  int range,
      input[100000],
      answer = 0,
      temp = 0,
      flag = 0,
      i,
      j,
      k;

  scanf("%d", &range);

  for (i = 0; i < range; i++)
  {
    scanf("%d", &input[i]);
  }

  for (i = 0; i < range; i++)
  {
    for (j = 0; j < range; j++)
    {
      if (j + flag > range)
        break;
      if (j == 0)
      {
        for (k = 0; k <= flag; k++)
        {
          temp += input[k];
        }
      }
      else
      {
        temp -= input[j - 1];
        temp += input[j + flag];
      }

      answer = temp > answer ? temp : answer;
    }
    temp = 0;
    flag++;
  }

  printf("%d", answer);
}
*/
/*
  문제를 다시 접근해 보기로 했다
  시간초과가 난 이유는 아마도 모든 경우의 수를 비교했기 때문인 것 같다.
  예를들어 10개의 수 라면 숫자1개일 때 1의자리 1부터 10번째까지 
                     숫자2개일 때 12, 23, 34 이런식으로 10자리까지 모두 비교해서 가장 큰 값을 구했다
  그러나 이건 시간초과가 나는 방법이여서 다른 방법을 생각해 냈는데,
  다이나믹 프로그래밍 기법을 이용해서 점화식을 세웠다
  input 10개 라고 하고
  10개의 숫자를 입력받는다
  (예제: 10, -4, 3, 1, 5, 6, -35, 12, 21, -1)
  
  SUM(i) = i 번째 수 까지의 최대 부분 합 이라고 할 때
  i번째 수 까지의 부분합은
  SUM(i) = SUM(i - 1) + i 이 될 수도 있고
  그냥 i 일 수도 있다
*/

#include <stdio.h>
int main()
{
  int input,                // 숫자 개수 입력
      numbers[100000] = {}, // 숫자 데이터 입력
      temp[100000] = {0},   // 각 부분합이 들어갈 배열
      answer = -1000,       // 정답 숫자, -1000까지 입력 될 수 있디고 했기에 -1000을 주었다. 처음에 0으로 주고 시작했는데 오류가 나서... 테스트 케이스가 0보다 작은 경우도 있는 것 같다
      i;                    // for 문

  scanf("%d", &input);

  for (i = 0; i < input; i++)
  {
    scanf("%d", &numbers[i]);
  }

  // temp[0 - 1]은 할 수가 없으므로 for 문 전에 첫 번째 숫자인 temp[0] 을 number[0]으로 맞추어 넣었다
  temp[0] = numbers[0];
  // for 문에서 첫 번째 비교를 못해서 이것만 넣었다. 사실 for 문 안에서도 할 수 있지만 if를 input값 만큼 돌려야 하기에 비효율적이다
  answer = temp[0] > answer ? temp[0] : answer;
  for (i = 1; i < input; i++)
  {
    // 삼항 연산자를 이용하여 보기 껄끄럽지만 SUM(i - 1) + i 이것과 i 의 크기 차이를 분석해 큰 값을 넣어주는 것이다
    temp[i] = temp[i - 1] + numbers[i] > numbers[i] ? temp[i - 1] + numbers[i] : numbers[i];
    // 이것도 가장 큰 값과 지금 찍힌 값을 비교해서 넣어주는 것이다
    answer = temp[i] > answer ? temp[i] : answer;
  }
  // 출력
  printf("%d", answer);
}