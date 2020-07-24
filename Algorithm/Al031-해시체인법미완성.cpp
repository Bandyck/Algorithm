#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **arr = NULL;
	size_t n = 0;
	size_t strLength = 0;
	printf("입력할 문자열의 개수 : ");
	scanf("%d%*c", &n);
	arr = (char **)malloc(sizeof(char *) * n);
	printf("\n입력할 문자열의 최대 길이 : ");
	scanf("%d%*c", &strLength);
	printf("\n");

	for (int i = 0; i < n; i++) {
		printf("No.%d String : ", i + 1);
		arr[i] = (char *)malloc(sizeof(char) * (strLength + 1));
		scanf("%[^\n]s", arr[i]);
		rewind(stdin);
	}

	system("cls");

	for (int i = 0; i < n; i++) {
		printf("No.%d String : %s\n", i + 1, arr[i]);
		free(arr[i]);
	}
	free(arr);
}