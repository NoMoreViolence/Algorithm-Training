// https://www.acmicpc.net/problem/2292			벌집: 2292
#include <stdio.h>
int main()
{
	int input,
			Bee = 0,
			i = 0;
	scanf("%d", &input);

	while (1)
	{
		// 중앙에서 번호까지의 벌집 거리 계산 변수
		i++;
		// 이 공식을 이용하면 벌집중앙에서 입력받은 벌집의 번호 까지 몇번째에 도달하는지 알 수 있게 된다
		Bee = 3 * i * i - 3 * i + 1;

		// 인풋 값과 비교
		if (input <= Bee)
		{
			// Done!
			printf("%d", i);
			break;
		}
	}
}
