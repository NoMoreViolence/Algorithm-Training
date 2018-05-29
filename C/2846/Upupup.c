// https://www.acmicpc.net/problem/2846     오르막길: 2846
#include <stdio.h>
int main(void)
{
  int range,            // 입력 범위 정하기
      numbers[10000],   // 담는 그릇
      tempStarting = 0, // 스타팅
      tempEnding = 0,   // 끝
      bestUp = 0,       // 가장 큰 오르막길 저장 변수
      temp = 0;         // 비교햐려고 담는 오르막길 저장 변수

  // 오르막길을 오르는 중인지 내리막을 가는 중인지 오르막 가다가 내리막인지 내리막 가다가 오르막인지 판단하는 변수
  int running = 0;

  // 배열을 저장할 숫자를 받는다
  scanf("%d", &range);

  // 일단 먼저 담는다
  scanf("%d", &numbers[0]);

  // 포문을 돌자 포문을 돌자 !
  for (int i = 1; i < range; i++)
  {
    scanf("%d", &numbers[i]);

    // 일단 처음 오르막길이 시작임을 알려줍니다
    if (numbers[i] > numbers[i - 1] && running == 0)
    {
      // 처음 오르막길 시작이니까 스타팅 넘버를 부여
      tempStarting = numbers[i - 1];
      tempEnding = numbers[i];
      // 당연이 오르막길 올라가는 중이니까 true로 변경
      running = 1;
    }
    // 오르막길이기는한데 전부터 이어져오던 오르막길 일 때
    tempEnding = numbers[i] > numbers[i - 1] && running == 1 ? numbers[i] : tempEnding;

    // 오르막길 올라가는 도중 내리막길 만났을 때
    if (numbers[i] <= numbers[i - 1] && running == 1)
    {
      // 가뭄의 단비
      // 비교해줄 temp 값, 사실 이거 없이도 가능하나 코드가 너무 번잡해져서 변수 하나 만들어 담았습니다.
      temp = tempEnding - tempStarting;
      // 최고 오르막 기록에 도달하면 기록갱신, 아닐 때는 기존 기록 유지
      bestUp = bestUp < temp ? temp : bestUp;

      tempStarting = numbers[i];
      running = 0;
    }
  }

  // 맨 마지막 요소까지 검사, 마지막에서 오르막길 이였을 수도 있는 예외 핸들러
  if (running == 1 && numbers[range - 1] > numbers[range - 2])
  {
    temp = numbers[range - 1] - tempStarting;
    bestUp = bestUp < temp ? temp : bestUp;
  }

  printf("%d", bestUp);
}