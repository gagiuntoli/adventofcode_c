#include "stdg.h"
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: need to provide the input file path (only) as argument\n");
		return 1;
	}
	char *input_path = argv[1];

	Vector *lines = files_get_lines(input_path);

	char *solution1 = NULL;
	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);
		char *line = value->data;

		Vector *str_split = string_split(line, " ");

		Value *sue_v = vector_get(str_split, 1);
		string_trim_right(sue_v->data, ':');
		solution1 = strdup(sue_v->data);
		free(sue_v);

		int children = 3, cats = 7, samoyeds = 2, pomeranians = 3, akitas = 0, vizslas = 0, goldfish = 5, trees = 3, cars = 2, perfumes = 1;
		for (int i = 2; i < str_split->length; i+=2) {
			Value *value = vector_get(str_split, i+1);
			if (i != str_split->length-2) {
				string_trim_right(value->data, ',');
			}
			int val = atoi(value->data);
			free(value);

			Value *str = vector_get(str_split, i);
			string_trim_right(str->data, ':');
			if (strcmp(str->data, "children") == 0) {
				if (children != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "cats") == 0) {
				if (cats != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "samoyeds") == 0) {
				if (samoyeds != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "pomeranians") == 0) {
				if (pomeranians != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "akitas") == 0) {
				if (akitas != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "vizslas") == 0) {
				if (vizslas != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "goldfish") == 0) {
				if (goldfish != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "trees") == 0) {
				if (trees != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "cars") == 0) {
				if (cars != val) {
					solution1 = NULL;
					break;
				}
			} else if (strcmp(str->data, "perfumes") == 0) {
				if (perfumes != val) {
					solution1 = NULL;
					break;
				}
			}
			free(str);
		}
		if (solution1 != NULL) {
			break;
		}
	}

	char *solution2 = NULL;
	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);
		char *line = value->data;

		Vector *str_split = string_split(line, " ");

		Value *sue_v = vector_get(str_split, 1);
		string_trim_right(sue_v->data, ':');
		solution2 = strdup(sue_v->data);
		free(sue_v);

		int children = 3, cats = 7, samoyeds = 2, pomeranians = 3, akitas = 0, vizslas = 0, goldfish = 5, trees = 3, cars = 2, perfumes = 1;
		for (int i = 2; i < str_split->length; i+=2) {
			Value *value = vector_get(str_split, i+1);
			if (i != str_split->length-2) {
				string_trim_right(value->data, ',');
			}
			int val = atoi(value->data);
			free(value);

			Value *str = vector_get(str_split, i);
			string_trim_right(str->data, ':');
			if (strcmp(str->data, "children") == 0) {
				if (children != val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "cats") == 0) {
				if (cats >= val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "samoyeds") == 0) {
				if (samoyeds != val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "pomeranians") == 0) {
				if (pomeranians <= val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "akitas") == 0) {
				if (akitas != val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "vizslas") == 0) {
				if (vizslas != val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "goldfish") == 0) {
				if (goldfish <= val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "trees") == 0) {
				if (trees >= val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "cars") == 0) {
				if (cars != val) {
					solution2 = NULL;
					break;
				}
			} else if (strcmp(str->data, "perfumes") == 0) {
				if (perfumes != val) {
					solution2 = NULL;
					break;
				}
			}
			free(str);
		}
		if (solution2 != NULL) {
			break;
		}
	}

	printf("solution 1: %s\n", solution1);
	printf("solution 2: %s\n", solution2);
	return 0;
}
