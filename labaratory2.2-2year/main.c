#include<Windows.h>
#include<stdio.h>
#include"function.h"
#include"FileFunction.h"
int main(int argc,char* argv[]) {
	printf("Print number, number 1 - print for keyboard, number 2 - print for main, number 3 print Names of file in file 'FileNames.txt'\n");
	int exc;
	scanf_s("%d", &exc);
	if (exc == 1) {
		int c;
		int size = 0;
		char* Name = (char*)malloc(size * sizeof(char));
		while (1) {
			c = getch();
			printf("%c", c);
			size++;
			Name = (char*)realloc(Name, size * sizeof(char));
			if (c == 13) {
				printf("\n");
				Name[size - 1] = '\0';
				break;
			}
			Name[size - 1] = (char)c;
		}
		if (ErrorInFile(Name) == 0) {
			MakeLabExc(Name);
		}
	}
	if (exc == 2) {
		for (int i = 1; i < argc; i++) {
			if (argv[i] != NULL && ErrorInFile(argv[i]) == 0){
				MakeLabExc(argv[i]);
			}
		}
	}
	if (exc == 3) {
		if (ErrorInFile("FileNames.txt") == 0) {
			int NumberOfString = GetNumberOfStringInFile("FileNames.txt");
			ArrOfCount* ArrStringSize = GetSizeOfStringInFile("FileNames.txt", NumberOfString);
			char** NamesOfFile = GetArrayOfStrInFile("FileNames.txt", ArrStringSize, NumberOfString);
			for (int i = 0; i < NumberOfString; i++) {
				if (ErrorInFile(NamesOfFile[i]) == 0) {
					MakeLabExc(NamesOfFile[i]);
				}
			}
		}
	}
	if (exc < 1 || exc>3) {
		printf("ERROR! You choose wrong number");
	}
	system("pause");
	return 0;
}