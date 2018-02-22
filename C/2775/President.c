// https://www.acmicpc.net/problem/2775     부녀회장이 될테야: 2775
#include <stdio.h>
int main()
{
  unsigned int i, j, k;
  unsigned int Case, Fl, Ho;
  unsigned int Apt[15][15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // 첫 층의 아파트 배열

  scanf("%d", &Case); // 테스트 케이스 숫자 입력

  for (i = 1; i <= 14; i++) // 모든 아파트 데이터 채우기
  {
    for (j = 1; j <= 14; j++)
    {
      for (k = 1; k <= j; k++)
      {
        Apt[i][j] += Apt[i - 1][k];
      }
    }
  }

  // 테스트 케이스만큼 입력받기
  for (i = 1; i <= Case; i++)
  {
    scanf("%d", &Fl);
    scanf("%d", &Ho);
    // 미리 저장해 놓은 데이터 베이스 출력
    printf("%d\n", Apt[Fl][Ho]);
  }
}
