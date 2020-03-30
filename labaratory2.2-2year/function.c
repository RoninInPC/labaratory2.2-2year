#include<windows.h>
#include<stdio.h>
#include "function.h"

int GetNumberOfStringInFile(char* FileName) {
	FILE* f;
	fopen_s(&f, FileName, "r");
	int k = 0;
	char c;
	while (!feof(f)) {
		fscanf_s(f, "%c", &c, 1);
		if (c == '\n') {
			k++;
		}
	}
	fclose(f);
	return k + 1;
}
ArrOfCount* GetSizeOfStringInFile(char* FileName,int NumberOfString) {
	FILE* f;
	fopen_s(&f, FileName, "r");
	ArrOfCount* Arr = (ArrOfCount*)malloc(NumberOfString * sizeof(ArrOfCount));
	char c;
	int k = 0;
	int SizeStr = 0;
	while (!feof(f)) {
		fscanf_s(f, "%c", &c);
		SizeStr++;
		if (c == '\n') {
			Arr[k].Num = SizeStr;
			Arr[k].I = k;
			SizeStr = 0;
			k++;
		}
	}
	Arr[k].Num = SizeStr;
	Arr[k].I = k;
	fclose(f);
	return Arr;
}
char** GetArrayOfStrInFile(char* FileName,ArrOfCount* ArrSizeOfString,int NumberOfString) {
	FILE* f;
	fopen_s(&f, FileName, "r");
	char** Ans = (char**)malloc(NumberOfString * sizeof(char*));
	for (int i = 0; i < NumberOfString; i++) {
		Ans[i] = (char*)malloc(ArrSizeOfString[i].Num+1 * sizeof(char));
		fgets(Ans[i], (ArrSizeOfString[i].Num+1)*sizeof(char), f);
	}
	fclose(f);
	return Ans;
}
ArrOfCount* SortArrOfCountOfNum(ArrOfCount** A, int Size) {
	ArrOfCount* Ans = *A;
	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - 1; j++) {
			if (Ans[j].Num > Ans[j + 1].Num) {
				ArrOfCount t = Ans[j];
				Ans[j] = Ans[j + 1];
				Ans[j + 1] = t;
			}
		}
	}
	return Ans;
}
void PrintArrOfString(char** ArrOfString, ArrOfCount* ArrSizeOfString, int Size) {
	for (int i = 0; i < Size; i++) {
		printf("%s", ArrOfString[ArrSizeOfString[i].I]);
	}
}
void MakeLabExc(char* FileName) {
	int NumberOfString = GetNumberOfStringInFile(FileName);
	ArrOfCount* ArrSize = GetSizeOfStringInFile(FileName, NumberOfString); 
	char** Text = GetArrayOfStrInFile(FileName, ArrSize, NumberOfString);
	SortArrOfCountOfNum(&ArrSize, NumberOfString);
	PrintArrOfString(Text, ArrSize, NumberOfString);
}