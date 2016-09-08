/*
	print anagrams of given strings
	Angelo Poerio
*/

#include <stdio.h>
#include <string.h>

void swap_char(char *a, char *b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_anagrams(char *str,int start, int len) {
	int i;
	if(start == len) { 
		printf("%s\n",str);
		return;
	}

	for(i = start;i < len;i++) {
		swap_char(&str[start], &str[i]);
		print_anagrams(str, start + 1, len);
		swap_char(&str[start], &str[i]);
	}
	
}

int main(int argc, char *argv[]) {
	int i;
	if(argc < 2) {
		printf("Usage: %s word_1 word_2 ... word_n ...\n",argv[0]);
		return 1;
	}

	for(i = 1;i < argc;i++) {
		printf("Anagrams of %s\n", argv[i]);
		print_anagrams(argv[i],0,strlen(argv[i]));
	}
}
