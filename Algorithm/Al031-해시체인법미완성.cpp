#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **arr = NULL;
	size_t n = 0;
	size_t strLength = 0;
	printf("�Է��� ���ڿ��� ���� : ");
	scanf("%d%*c", &n);
	arr = (char **)malloc(sizeof(char *) * n);
	printf("\n�Է��� ���ڿ��� �ִ� ���� : ");
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