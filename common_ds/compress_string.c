/*
	Uber simple string compression - Angelo Poerio <angelo.poerio@gmail.com>
	Example: 
	./compress_string aaabb gggggggggggggggggggggggggggggggggggg poirrrrrtttt
	Original: aaabb | Compressed: a3b2 | Saved: 80.00 % 
	Original: gggggggggggggggggggggggggggggggggggg | Compressed: g36 | Saved: 8.33 % 
	Original: poirrrrrtttt | Compressed: poir5t4 | Saved: 58.33 % 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *helper(char c, int occ){
	char *out = (char *)malloc(20); /* should be enough */
	if(occ > 1)
		sprintf(out,"%c%d",c,occ);
	else
		sprintf(out,"%c",c);
	return out;
}

void compress(char *in,char *out) {
	int len = strlen(in), i, counter = 1;
        char current_char = in[0], *tmp;

	for(i = 1;i < len;i++) {
		if(in[i] == current_char) 
		{	
			counter++;
		}
		else {
			tmp = helper(current_char,counter);
			strcat(out, tmp);
			free(tmp);
			counter = 1;
			current_char = in[i];
		}
	}

	strcat(out,helper(current_char,counter));
}

int main(int argc, char **argv) {
	char *compressed_string;
	int or_len,com_len,i;
	for(i = 1;i < argc;i++) {
		or_len = strlen(argv[i]);
		compressed_string = (char *)malloc(or_len * 2); /* it could crash in some cases */
		memset(compressed_string,0,or_len*2);
		compress(argv[i],compressed_string);
		com_len = strlen(compressed_string);
		printf("Original: %s | Compressed: %s | Saved: %.2f % \n", argv[i],
							compressed_string,
							((double)com_len/(double)or_len) * 100.0);
		free(compressed_string);
	}
}
