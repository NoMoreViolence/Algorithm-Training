// https://www.acmicpc.net/problem/9507     Generations of Tribbles: 9507
/* 
  처음에는 그냥 함수를 이용해서 하려는데
  엄청난 시간초과의 벽에 부딛혀 포기하려다가
  점화식을 이용해서 겨우 풀었다..
  다이나믹 프로그래밍은 점화식 아니면 못풀듯..
*/
#include <stdio.h>
int main()
{
  int i,      // for
      input,  // 계산 횟수 정하는 값
      number; // 계산 할 숫자 입력받을 값

  // 점화식 데이터 채워넣을 변수
  unsigned long int numbers[68];

  // 초기 데이터 구성 점화식 이용하기 위함
  numbers[0] = 1;
  numbers[1] = 1;
  numbers[2] = 2;
  numbers[3] = 4;

  // 점화식을 활용 데이터 채워넣기
  for (i = 4; i < 68; i++)
  {
    numbers[i] = numbers[i - 1] + numbers[i - 2] + numbers[i - 3] + numbers[i - 4];
  }

  // 계산 횟수 입력
  scanf("%d", &input);

  for (i = 0; i < input; i++)
  {
    // 꿍 계산을 할 값들 입력
    scanf("%d", &number);

    // unsigned long int 형을 출력할 때는 이렇게 해야한다 %lu
    printf("%lu\n", numbers[number]);
  }
}