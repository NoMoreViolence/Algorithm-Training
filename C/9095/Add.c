// https://www.acmicpc.net/problem/9095			1,2,3 더하기: 9095
#include <stdio.h>
int main()
{
	int num, input;
	int i, j;
	int arr[11] = {0};
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	// 테스트 케이스 범위 숫자 입력
	scanf("%d", &input);

	// 테스트 케이스의 숫자만큼 입력을 받음
	while (input > 0)
	{
		// 테스트 케이스 입력
		scanf("%d", &num);

		// 점화식이 4 부터 되서 4 부터 함
		for (i = 4; i <= num; i++)
		{
			// 이미 전에 값을 채워넣었다면 다시 올라가서 시작
			if (arr[i] != 0)
				continue;

			// 점화식을 활용한 식 구하기
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}

		// 정답 출력
		printf("%d\n", arr[num]);

		// 인풋 값 --
		input--;
	}
}
