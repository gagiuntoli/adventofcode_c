#include "stdg.h"

int compute_max_score(int (*properties)[5], int n) {
	int max_score = 0;
	for (int q0 = 0; q0 <= 100; q0++) {
		for (int q1 = 0; q1 <= 100; q1++) {
			for (int q2 = 0; q2 <= 100; q2++) {
				int sum = q0 + q1 + q2;
				if (sum >= 0 && sum <= 100) {
					int q3 = 100 - sum;
					assert(q0 + q1 + q2 + q3 == 100);
					int score = 1;
					for (int p = 0; p < 4; p++) {
						score *= max(0, q0 * properties[0][p] + q1 * properties[1][p] + q2 * properties[2][p] + q3 * properties[3][p]);
					}
					max_score = max(max_score, score);
				}
			}
		}
	}

	return max_score;
}

int compute_max_score_with_calories(int (*properties)[5], int n) {
	int max_score = 0;
	for (int q0 = 0; q0 <= 100; q0++) {
		for (int q1 = 0; q1 <= 100; q1++) {
			for (int q2 = 0; q2 <= 100; q2++) {
				int sum = q0 + q1 + q2;
				if (sum >= 0 && sum <= 100) {
					int q3 = 100 - sum;
					assert(q0 + q1 + q2 + q3 == 100);
					int calories = q0 * properties[0][4] + q1 * properties[1][4] + q2 * properties[2][4] + q3 * properties[3][4];
					if (calories == 500) {
						int score = 1;
						for (int p = 0; p < 4; p++) {
							score *= max(0, q0 * properties[0][p] + q1 * properties[1][p] + q2 * properties[2][p] + q3 * properties[3][p]);
						}
						max_score = max(max_score, score);
					}
				}
			}
		}
	}

	return max_score;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: need to provide the input file path (only) as argument\n");
		return 1;
	}
	char *input_path = argv[1];

	Vector *lines = files_get_lines(input_path);

	int (*properties)[5] = malloc(lines->length * sizeof(int[5]));

	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);
		char *line = value->data;

		Vector *str_split = string_split(line, " ");
		assert(str_split->length == 11);

		Value *param = vector_get(str_split, 2);
		string_trim_right(param->data, ',');
		properties[i][0] = atoi(param->data);
		free(param);

		param = vector_get(str_split, 4);
		string_trim_right(param->data, ',');
		properties[i][1] = atoi(param->data);
		free(param);

		param = vector_get(str_split, 6);
		string_trim_right(param->data, ',');
		properties[i][2] = atoi(param->data);
		free(param);

		param = vector_get(str_split, 8);
		string_trim_right(param->data, ',');
		properties[i][3] = atoi(param->data);
		free(param);

		param = vector_get(str_split, 10);
		string_trim_right(param->data, ',');
		properties[i][4] = atoi(param->data);
		free(param);
	}

	int solution1 = compute_max_score(properties, lines->length);
	int solution2 = compute_max_score_with_calories(properties, lines->length);

	printf("solution 1: %d\n", solution1);
	printf("solution 2: %d\n", solution2);
	return 0;
}
