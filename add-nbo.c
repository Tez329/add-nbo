#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE* five = fopen(argv[1], "rb");
	if ( five == NULL ) {
		perror("error fopen");
		exit(0);
	}

	FILE* thou = fopen(argv[2], "rb");
	if ( thou == NULL ) {
		perror("error fopen");
		exit(0);
	}

	uint32_t five_hex, thou_hex, result;
	fread(&five_hex, 4, 1, five);
	fread(&thou_hex, 4, 1, thou);

	five_hex = ntohl(five_hex);
	thou_hex = ntohl(thou_hex);
	result = five_hex + thou_hex;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", thou_hex, thou_hex, five_hex, five_hex, result, result);

	return 0;
}

