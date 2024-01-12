#include "stdg.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: need to provide the input file path (only) as argument\n");
		return 1;
	}
	char *input_path = argv[1];

	Vector *lines = files_get_lines(input_path);

	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);

		printf("%s\n", value->data);
	}

	int solution1 = 0;
	int solution2 = 0;

	printf("solution 1: %d\n", solution1);
	printf("solution 2: %d\n", solution2);
	return 0;
}
