#include "stdg.h"

void print_matrix_int(int **matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("\t%3d", matrix[i][j]);
		}
		printf("\n");
	}
}

int compute_points(int **point_matrix, int *permutation, int n) {
	int points = 0;

	for (int i = 0; i < n; i++) {
		int p = permutation[i];
		int i1 = permutation[(n + i - 1) % n];
		int i2 = permutation[(n + i + 1) % n];
		assert(p != i1 && p != i2 && i1 != i2);
		assert(p >= 0 && p < n);
		assert(i1 >= 0 && i1 < n);
		assert(i2 >= 0 && i2 < n);
		points += point_matrix[p][i1];
		points += point_matrix[p][i2];
	}

	return points;
}

void swap(int *arr, int i, int j) {
	int aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
}

int compute_max_points(int **point_matrix, int n) {
	int *c = calloc(n, sizeof(int));
	int *A = malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		A[i] = i;
	}

        int max_points = compute_points(point_matrix, A, n);
	int i = 1;
	while (i < n-1) {
		if (c[i] < i) {
			if (i % 2 == 0) {
				swap(A, 0, i);
			} else {
				swap(A, c[i], i);
			}
			int points = compute_points(point_matrix, A, n);
			if (points > max_points) {
				max_points = points;
			}
			c[i]++;
			i = 1;
		} else {
			c[i] = 0;
			i++;
		}
	}


	free(c);
	free(A);
	return max_points;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: need to provide the input file path (only) as argument\n");
		return 1;
	}
	char *input_path = argv[1];

	Vector *lines = files_get_lines(input_path);
	Vector *names = vector_create();
	
	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);
		char *line = value->data;

		Vector *str_split = string_split(line, " ");
		assert(str_split->length == 11);

		Value *from = vector_get(str_split, 0);

		vector_push_unique(names, from);
		free(value);
	}

	int n = names->length;

	int **point_matrix = malloc((n+1) * sizeof(int *));
	for (int i = 0; i < n+1; i++) {
		point_matrix[i] = calloc(n+1, sizeof(int));
	}

	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);
		char *line = value->data;

		Vector *str_split = string_split(line, " ");
		assert(str_split->length == 11);

		Value *from = vector_get(str_split, 0);
		Value *to = vector_get(str_split, 10);
		string_trim_right(to->data, '.');
		
		Value *to_t = malloc(sizeof(Value) + strlen(to->data) + 1);
		to_t->size = strlen(to->data) + 1;
		memcpy(to_t->data, to->data, strlen(to->data) + 1);

		Value *sign_s = vector_get(str_split, 2);
		Value *points_s = vector_get(str_split, 3);

		int sign = !strcmp(sign_s->data, "gain") ? 1 : -1;
		int points = sign * atoi(points_s->data);

		int i = vector_get_index(names, from);
		int j = vector_get_index(names, to_t);
		point_matrix[i][j] = points;
	}

	for (int i = 0; i < n+1; i++) {
		point_matrix[i][n] = 0;
	 	point_matrix[n][i] = 0;
	}

	int solution1 = compute_max_points(point_matrix, names->length);
	int solution2 = compute_max_points(point_matrix, names->length+1);

	printf("solution1: %d\n", solution1);
	printf("solution2: %d\n", solution2);
	return 0;
}
