#define _CRT_SECURE_NO_WARNINGS
#define PATH "..\\x64\\Debug\\DecisionKvYrav.exe"

#include <Windows.h>
#include <stdio.h>


int main()
{
	system("chcp 1251>nul");
	const char* fileNameStart = "..\\VhodData.txt";
	const char* fileNameResult = "..\\Result.txt";
	float d[3];
	FILE* fileStart = fopen(fileNameStart, "r");
	if (fileStart == NULL)
	{
		printf("��� �������� ����� �������� ������!");
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{
		fscanf(fileStart, " %f", &d[i]);
	}
	fclose(fileStart);
	char* str = calloc(100, sizeof(char));
	sprintf(str, "%f %f %f", d[0], d[1], d[2]);
	char* command_line = str;
	LPSTARTUPINFOA sti = calloc(1, sizeof(STARTUPINFO));
	LPPROCESS_INFORMATION li = calloc(1, sizeof(PROCESS_INFORMATION));
	CreateProcessA(
		PATH,
		command_line,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		sti,
		li
	);
	WaitForSingleObject(li->hProcess, 1);
	printf("� ������� ���������� ��������� ��������");
	DWORD ecode;
	GetExitCodeProcess(li->hProcess, &ecode);
	CloseHandle(li->hProcess);
	CloseHandle(li->hThread);
	float r[2];
	FILE* fileResult = fopen(fileNameResult, "r");
	if (fileResult == NULL)
	{
		printf("��� �������� ����� �������� ������!");
		return 0;
	}
	fseek(fileResult, -1, SEEK_END);
	while (1)
	{
		if (fgetc(fileResult) != '\n')
		{
			fseek(fileResult, -2, SEEK_CUR);
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		fscanf(fileStart, " %f", &r[i]);
	}
	if (r[0] != -107374176. && r[1] != -107374176.)
	{
		printf("\n��������� ����� ��� �����: %g � %g", r[0], r[1]);
	}
	else if(r[0] != -107374176.)
	{
		printf("\n��������� ����� ���� ������: %g", r[0]);
	}
	else
	{
		printf("\n��������� �� ����� �� ������ �����");
	}
	return 0;
}