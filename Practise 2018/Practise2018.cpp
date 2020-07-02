// Practise2018 Nikolaychuk copyright.

#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <math.h>

int N, X;

struct date
{
	int day;
	int month;
	int year;
};

struct Car
{
	char brand[20];
	int number;
	char destination[20];
	int massT;
	int costOfTonn;
	int costOfCargo;
	date departure;
	date arrive;
};

Car* buf = (Car*)calloc(N, sizeof(Car));

int NumberCheckInn() {
	int number;
	do
	{
		if (scanf("%d", &number)) return number;
		else printf(" �� � ������, ��������� �����: ");
		while (getchar() != '\n');
	} while (1);
	getchar();
}

void SaveFile()
{
	system("cls");
	FILE *file = fopen("d:\\File_Reis.bin", "w+b");
	fwrite(&N, sizeof(int), 1, file);
	fwrite(buf, sizeof(Car), N, file);
	fclose(file);
	FILE *ft;
	ft = fopen("D:\\Text_File_Reis.txt", "wt");
	for (int i = 0; i < N; i++)
	{
		fprintf(ft," ����[%2d] %-10s (%4d) - %-10s, ������� ����������:%3d(�) ������� ������� �������:%4d$ �������� �������:%6d$\n ³���������� (%2d.%2d.%4d) �������� (%2d.%2d.%2d)\n",
			i, buf[i].brand, buf[i].number, buf[i].destination, buf[i].massT, buf[i].costOfTonn, buf[i].costOfCargo, buf[i].departure.day,
			buf[i].departure.month, buf[i].departure.year, buf[i].arrive.day, buf[i].arrive.month, buf[i].arrive.year);
	}
	fclose(ft);
}

void LoadFile()
{
	system("cls");
	FILE *file;
	file = fopen("d:\\File_Reis.bin", "r+b");
	fread(&N, sizeof(int), 1, file);
	Car *buf1 = (Car*)malloc(N * sizeof(Car));
	fread(buf1, sizeof(Car), N, file);
	fclose(file);
	free(buf);
	buf = buf1;
}

void PreLoadFile()
{
	FILE *file;
	file = fopen("d:\\File_Reis.bin", "r+b");
	if (file)
	{
		LoadFile();
		printf("(���� ������ �����������.)\n");
	}
	else
	{
		printf("(���� �� ����, ������� ��� ����.)\n");
	}
}

void ReadReis(int Num)
{
	getchar();
	do {
		printf("  ����� ���������: ");
		gets_s(buf[Num].brand);
		X = true;
		X = isupper(*buf[Num].brand);
	} while (X != true);
	do {
		printf("  ����� ���������: ");
		buf[Num].number = NumberCheckInn();
	} while (buf[Num].number < 1000 || buf[Num].number > 9999);
	getchar();
	do {
	printf("  ����� �����������: ");
	gets_s(buf[Num].destination);
	X = isupper(*buf[Num].destination);
	} while (X != true);
	printf("  ����������������� (� �����): ");
	buf[Num].massT = NumberCheckInn();
	printf("  ������� ������� �������: ");
	buf[Num].costOfTonn = NumberCheckInn();
	printf("  �������� ������� �������: ");
	buf[Num].costOfCargo = NumberCheckInn();
	printf("  ���� �����������\n");
	do {
	printf("  ����: ");
	buf[Num].departure.day = NumberCheckInn();
	} while (buf[Num].departure.day < 0 || buf[Num].departure.day > 32);
	do {
	printf("  ̳����: ");
	buf[Num].departure.month = NumberCheckInn();
	} while (buf[Num].departure.month < 0 || buf[Num].departure.month > 13);
	do {
	printf("  г�: ");
	buf[Num].departure.year = NumberCheckInn();
	} while (buf[Num].departure.year < 2018 || buf[Num].departure.year > 2100);
	printf("  ���� ��������\n");
	do {
	printf("  ����: ");
	buf[Num].arrive.day = NumberCheckInn();
	} while (buf[Num].arrive.day < 0 || buf[Num].arrive.day > 32);
	do {
	printf("  ̳����: ");
	buf[Num].arrive.month = NumberCheckInn();
	} while (buf[Num].arrive.month < 0 || buf[Num].arrive.month > 13);
	do {
	printf("  г�: ");
	buf[Num].arrive.year = NumberCheckInn();
	} while (buf[Num].arrive.year < 2018 || buf[Num].arrive.year > 2100);
	getchar();
	system("cls");
}

void ReisPrint(int i)
{
	printf(" ����[%2d] %-10s (%4d) - %-10s, ������� ����������:%3d(�) ������� ������� �������:%4d$ �������� �������:%6d$\n ³���������� (%2d.%2d.%4d) �������� (%2d.%2d.%2d)\n",
		i, buf[i].brand, buf[i].number, buf[i].destination, buf[i].massT, buf[i].costOfTonn, buf[i].costOfCargo, buf[i].departure.day,
		buf[i].departure.month, buf[i].departure.year, buf[i].arrive.day, buf[i].arrive.month, buf[i].arrive.year);
}

void ReisPrints()
{
	system("cls");
	for (int i = 0; i < N; i++)
	{
		ReisPrint(i);
	}
}

void AddReisData() {
	Car *buf1 = (Car*)malloc((N + 1) * sizeof(Car));
	for (int i = 0; i < N; i++)
		buf1[i] = buf[i];
	free(buf);
	buf = buf1;
	ReadReis(N);
	N++;
}

void DeletReisData(int z)
{
	if (z >= 0 && z <= N - 1) {
		for (int i = z; i < N - 1; i++)
		{
			buf[i] = buf[i + 1];
		}
		Car *buf1 = (Car*)malloc((N - 1) * sizeof(Car));
		N--;
		for (int i = 0; i < N; i++)
			buf1[i] = buf[i];
		free(buf);
		buf = buf1;
	}
}

int EditData(int z)
{
	int choise;
	system("cls");
	printf("0: �������� �� ����\n");
	printf("1: ����� ���������\n");
	printf("2: ����� ���������\n");
	printf("3: ����� �����������\n");
	printf("4: ����������������� (� �����)\n");
	printf("5: ������� ������� �������\n");
	printf("6: �������� ������� �������\n");
	printf("7: ���� �����������\n");
	printf("8: ���� ��������\n");
	printf("9: ����� �� ����\n");
	printf("������� ���� ��� ��������� ����������: ");
	scanf("%d", &choise);
	system("cls");
	switch (choise)
	{
	case 0: ReadReis(z);
		break;
	case 1:
		getchar();
		do {
			printf("  ����� ���������: ");
			gets_s(buf[z].brand);
			X = true;
			X = isupper(*buf[z].brand);
		} while (X != true);
		break;
	case 2:
		do {
			printf("  ����� ���������: ");
			buf[z].number = NumberCheckInn();
		} while (buf[z].number < 1000 || buf[z].number > 9999);
		break;
	case 3:
		getchar();
		do {
			printf("  ����� �����������: ");
			gets_s(buf[z].destination);
			X = isupper(*buf[z].destination);
		} while (X != true);
		break;
	case 4:
		printf("  ����������������� (� �����): ");
		buf[z].massT = NumberCheckInn();
		break;
	case 5:
		printf("  ������� ������� �������: ");
		buf[z].costOfTonn = NumberCheckInn();
		break;
	case 6:
		printf("  �������� ������� �������: ");
		buf[z].costOfCargo = NumberCheckInn();
		break;
	case 7:printf("  ���� �����������\n");
		do {
			printf("  ����: ");
			buf[z].departure.day = NumberCheckInn();
		} while (buf[z].departure.day < 0 || buf[z].departure.day > 32);
		do {
			printf("  ̳����: ");
			buf[z].departure.month = NumberCheckInn();
		} while (buf[z].departure.month < 0 || buf[z].departure.month > 13);
		do {
			printf("  г�: ");
			buf[z].departure.year = NumberCheckInn();
		} while (buf[z].departure.year < 2018 || buf[z].departure.year > 2100);
		break;
	case 8:
		printf("  ���� ��������\n");
		do {
			printf("  ����: ");
			buf[z].arrive.day = NumberCheckInn();
		} while (buf[z].arrive.day < 0 || buf[z].arrive.day > 32);
		do {
			printf("  ̳����: ");
			buf[z].arrive.month = NumberCheckInn();
		} while (buf[z].arrive.month < 0 || buf[z].arrive.month > 13);
		do {
			printf("  г�: ");
			buf[z].arrive.year = NumberCheckInn();
		} while (buf[z].arrive.year < 2018 || buf[z].arrive.year > 2100);
		break;
	case 9:
		return 0;
		break;
	}
}

int SerchForElement()
{
	system("cls");
	ReisPrints();
	int num, z;
	printf("\t---���� ������---\n");
	do {
		printf("������� � ���� ������� ������ ����������/��������\n");
		printf("-> ");
		scanf_s("%d", &z);
	} while (z > N || z < 0);
	printf("1. ������ �����\n");
	printf("2. �������� �����\n");
	printf("0. �����\n");
	printf("-> ");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1: EditData(z); break;
	case 2: DeletReisData(z); break;
	case 0: break;
	default: SerchForElement(); break;
	}
	return 0;
}

int MeinMenu()
{
	int num;
	printf("\t---����---\n");
	printf("1. ������ ����� \n");
	printf("2. ��������� ����� �� ������ \n");
	printf("3. �������� \n");
	printf("4. ����������� \n");
	printf("5. ���������� \n");
	printf("6. ����������� ����� \n");
	printf("0. �����\n"); 
	printf("-> ");
	num = NumberCheckInn();
	return num;
}

void ChoiseMenu()
{
	system("cls");
	int choise, resCount = 0;
	printf("\t---���� ���������---\n");
	printf("1. �� ������ \n");
	printf("2. �� ������� ��������� \n");
	printf("3. �� ��������� ����� ������� \n");
	printf("0. �����\n");
	printf("-> ");
	choise = NumberCheckInn();
	switch (choise)
		do {
	case 1: 
		char searchBrand[20];
		char searchBrand2[20];
		int point;
		printf(" ������ ����� ��� ������: "); getchar(); gets_s(searchBrand);

		for (int i = 0; i < N; i++)
		{
			strcpy(searchBrand2, buf[i].brand);
			point = strcmp(searchBrand, searchBrand2);
			if (point == NULL)
			{
				ReisPrint(i);
				resCount++;
			}
		}
		if (resCount == 0)
			printf(" ����� � ����� ���������� �� ��������\n");
		break;
	case 2:
		int cNum;
		resCount = 0;
		printf(" ����� ���������: ");
		cNum = NumberCheckInn();
		for (int i = 0; i < N; i++)
			if (buf[i].number == cNum)
			{
				ReisPrint(i);
				resCount++;
			}
		if (resCount == 0)
			printf(" ����� � ����� ���������� �� ��������\n");
		break;
	case 3:
		int fCost;
		printf(" �������� ������� �������: ");
		fCost = NumberCheckInn();
		for (int i = 0; i < N; i++)
			if (buf[i].costOfCargo == fCost)
			{
				ReisPrint(i);
				resCount++;
			}
		if (resCount == 0)
			printf(" ����� � ����� ���������� �� ��������\n"); break;
	case 0: break;
	default: printf("������� ������\n");
		} while (choise != 0);
}

void PrintChoiseMenu()
{
	system("cls");
	int num;
	printf("\t---���� ���������---\n");
	printf("1. ��������� ��� ����� \n");
	printf("2. �� ����������� \n");
	printf("0. ����������� �� ���� \n");
	printf("-> ");
	num = NumberCheckInn();
	switch (num)
	do{
	case 1: ReisPrints(); break;
	case 2: ChoiseMenu(); break;
	} while (num != 0);
}

int Sort()
{
	system("cls");
	int choise; int index = 1;
	Car tmp;
	printf("\t---���� ����������---\n");
	printf("1: ���������� �� ���������\n");
	printf("2: ���������� �� ����������\n");
	printf("0: ����������� �� ��������� ����\n");
	do
	{
		printf("������� ������ ���� ");
		scanf("%d", &choise);
		if (choise == 3)
			return 0;
		if (choise == 1 || choise == 2)
			break;
		printf("�������� ����������� ����� ����\n");
	} while (true);
	switch (choise)
	{
	case 1: {
		while (index) 
		{
			index = 0;
			for (int i = 0; i + 1 < N; i++)
			{
				if (strcmp(buf[i].brand, buf[i + 1].brand) < 0)
				{
					tmp = buf[i];
					buf[i] = buf[i + 1];
					buf[i + 1] = tmp;
					index = 1;
				}
			}
		}
	} break;
	case 2: {
		while (index)
		{
			index = 0;
			for (int i = 0; i + 1 < N; i++)
			{
				if (strcmp(buf[i].brand, buf[i + 1].brand) > 0)
				{
					tmp = buf[i];
					buf[i] = buf[i + 1];
					buf[i + 1] = tmp;
					index = 1;
				}
			}
		}
	}break;
	}
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num;
	PreLoadFile();
	do
	{
		num = MeinMenu();
		switch (num)
		{
		case 1: AddReisData();break;
		case 2: PrintChoiseMenu(); break;
		case 3: SaveFile(); break;
		case 4: LoadFile(); break;
		case 5: Sort(); break;
		case 6: SerchForElement(); break;
		case 0: break;
		default: printf("������� ������\n");
		}
	} while (num != 0);
    return 0;
}