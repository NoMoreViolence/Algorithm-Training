// https://www.acmicpc.net/problem/4504     배수 찾기: 4504
#include <stdio.h>
int main()
{
  int standard,         // 기준값
      list[1000000][2], // 인풋값들을 넣을 배열
      add = 0,          // 인풋값의 개수
      i;                // for 문

  // 기준값 받기
  scanf("%d", &standard);

  // 인풋값이 0이 아닐 때까지 반복함   * || 뒤의 식은 처음에 받을때는 무조건 거짓이 되므로 넣어줌 *
  while (list[add - 1][0] != 0 || add == 0)
  {
    // 인풋값 입력
    scanf("%d", &list[add][0]);

    // 만약 배수가 맞다면
    if (list[add][0] % standard == 0)
    {
      // 참의 값을 넣고
      list[add][1] = 1;
    }
    else // 아니라면
    {
      // 거짓 값을 넣는다
      list[add][1] = 0;
    }
    // 개수 증가
    add++;
  }
  // while문 에서 걸러지기 때문에 한개 빼야한다
  add--;

  // 한번에 출력
  for (i = 0; i < add; i++)
  {
    // 배수라면
    if (list[i][1] == 1)
    {
      printf("%d is a multiple of %d.\n", list[i][0], standard);
    }
    // 아니라면
    else
    {
      printf("%d is NOT a multiple of %d.\n", list[i][0], standard);
    }
  }
}
