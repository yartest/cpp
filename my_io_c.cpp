#include <stdio.h>
#include <string.h>

void output_data_c();
void input_data_c();
void input_output_file_c();

void input_output_data_c() {
	//output_data_c();
	//input_data_c();
	//input_output_file_c();
}

void output_data_c() {
	char ch = 'A';
	char str[20] = "fresh2refresh.com";
	float flt = 10.234;
	int no = 150;
	double dbl = 20.123456;
	printf("Character is %c \n", ch);
	printf("String is %s \n" , str);
	printf("Float value is %f \n", flt);
	printf("Integer value is %d\n" , no);
	printf("Double value is %lf \n", dbl);
	printf("Octal value is %o \n", no);
	printf("Hexadecimal value is %x \n", no);
}

void input_data_c() {
	char ch;
	char str[100];
	printf("Enter any string (up to 100 character) \n");
	// with '\n'
	fgets (str, 100, stdin);
	printf("Entered string is \"%s\"", str);
	printf("Enter any string (up to 100 character) \n");
	// without '\n'
	scanf("%[^\n]s",str);
	printf("Entered string is \"%s\" \n", str);
	// read '\n' from stdin
	fgets (str, 100, stdin);
	printf("Enter any character \n");
	scanf("%c", &ch);
	printf("Entered character is %c \n", ch);
}

void input_output_file_c() {
	char file_name[] = "/home/test/workspace/test_file.dat";
	FILE *pFile;
	pFile = fopen(file_name, "rw");
	if (!pFile) {
		printf("input_output_file(): fopen() error.\n");
		return;
	}
	char data[100];

	fseek(pFile, 0L, SEEK_END);
	int file_size = ftell(pFile);
	fseek(pFile, 0L, SEEK_SET);
	printf("size=%d\n", file_size);
	while (fgets(data, 100, pFile)) {
		static int counter = 1;
		printf("counter=%d\n", counter);
		printf("data=%s", data);
		counter++;
	}
	printf("\n");
	fseek(pFile, 0L, SEEK_SET);
	while (fscanf(pFile, "%s", data) != EOF) {
		static int c = 1;
		printf("c=%d\n", c);
		printf("data=%s\n", data);
		c++;
	}
	fclose (pFile);
}

