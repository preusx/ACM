#include <stdio.h>

#define DT double
#define _for(i, from, to) for(DT i = (from); i < (to); i++)

int main() {
	int length = 0, i;
	char buf, word[256];

	// freopen("input.txt", "r", stdin);

	while(scanf("%c", &buf) != EOF) {
		if(((buf-'a'>=0) && (buf-'a'<26)) || ((buf-'A'>=0) && (buf-'A'<26))) {
			word[length] = buf;
			length++;
			// printf("\n11\n");
		} else {
			if(length>0) {
				for(i = length-1; i >= 0; i--) {
					printf("%c", word[i]);
				}
				length = 0;
			}
			printf("%c", buf);
		}
	}
	if(length>0) {
		for(i = length-1; i >= 0; i--) {
			printf("%c", word[i]);
		}
		length = 0;
	}

	// fclose(stdin);

	return 0;
}