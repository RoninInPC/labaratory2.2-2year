#ifndef H_FUNCTION
#define H_FUNCTION
struct arrOfCount {
	int Num;
	int I;
};
typedef struct arrOfCount ArrOfCount;
int GetNumberOfStringInFile(char* FileName);
ArrOfCount* GetSizeOfStringInFile(char* FileName, int NumberOfString);
char** GetArrayOfStrInFile(char* FileName, ArrOfCount* ArrSizeOfString, int NumberOfString);
ArrOfCount* SortArrOfCountOfNum(ArrOfCount** A, int Size);
void QuickSortOfCountOfNum(ArrOfCount** numbers, int left, int right);
void PrintArrOfString(char** ArrOfString, ArrOfCount* ArrSizeOfString, int Size);
void MakeLabExc(char* FileName);
#endif