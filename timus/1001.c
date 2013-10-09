#include <stdio.h>
#include <math.h>

int main() {
	freopen("input.txt", "r", stdin);

	long long int number = -1, degree;
	int factor, length, i;

	char *buffer;

	fseek(stdin, 0, SEEK_END);
	length = ftell(stdin);
	rewind(stdin);

	buffer = (char*)malloc(sizeof(char)*length);
	fread(buffer, 1, length, stdin);

	for(i = length-1; i >= 0; i--) {
		factor = buffer[i] - '0';

		if(factor >= 0 && factor <= 9) {
			number = number >= 0 ? number : 0;
			number += degree * factor;
			degree *= 10;
		} else {
			if(number >= 0) {
				printf("%.4lf\n", sqrt(number));
			}

			degree = 1;
			number = -1;
		}
	}

	if(number >= 0) {
		printf("%.4lf\n", sqrt(number));
	}

	fclose(stdin);

	return 0;
}