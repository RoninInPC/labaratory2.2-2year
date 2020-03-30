#include<stdio.h>
int ErrorNoFile(char* fname){
	if (_access(fname, 0) == -1)
	{
		printf("ERROR! File %s don't found\n", fname);
		return 1;
	}
	return 0;
}
int ErrorNotRight(char* fname){
	if (_access(fname, 4) == -1) 
	{
		printf("ERROR! File %s restrict for administrator\n", fname);
		return 1;
	}
	return 0;
}
int ErrorFileEmpty(char* fname){
	FILE* f;
	fopen_s(&f, fname, "r");
	if (getc(f) == EOF)
	{
		printf("ERROR! File %s is empty\n", fname);
		return 1;
	}
	fclose(f);
	return 0;
}
int ErrorInFile(char* fname) {
	return ErrorNoFile(fname) || ErrorNotRight(fname) || ErrorFileEmpty(fname);
}