#include "stdg.h"

int min(int a, int b) {
	return a < b ? a : b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

typedef struct Params_ {
	int speed, fly_time, pause_time;
} Params;

int compute_points(Params *params, int n) {
	int *dists = calloc(n, sizeof(int));
	int *points = calloc(n, sizeof(int));
	for (int t = 0; t < 2503; t++) {
		for (int i = 0; i < n; i++) {
			int T = params[i].fly_time + params[i].pause_time;
			int r = t % T;
			if (r < params[i].fly_time) {
				dists[i] += params[i].speed * 1;
			}
		}

		int max_dist = dists[0];
		for (int i = 1; i < n; i++) {
			if (dists[i] > max_dist) {
				max_dist = dists[i];
			}
		}

		for (int i = 0; i < n; i++) {
			if (dists[i] == max_dist) {
				points[i]++;
			}
		}
	}

	int max_points = points[0];
	for (int i = 1; i < n; i++) {
		max_points = max(max_points, points[i]);
	}

	free(dists);
	free(points);
	return max_points;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: need to provide the input file path (only) as argument\n");
		return 1;
	}
	char *input_path = argv[1];

	Vector *lines = files_get_lines(input_path);

	Params *params = malloc(lines->length * sizeof(Params));
	
	int time = 2503;
	int max_dist = 0;
	for (int i = 0; i < lines->length; i++) {
		Value *value = vector_get(lines, i);
		char *line = value->data;

		Vector *str_split = string_split(line, " ");
		assert(str_split->length == 15);

		Value *speed_s = vector_get(str_split, 3);
		Value *fly_time_s = vector_get(str_split, 6);
		Value *pause_time_s = vector_get(str_split, 13);

		int speed = atoi(speed_s->data);
		int fly_time = atoi(fly_time_s->data);
		int pause_time = atoi(pause_time_s->data);
		int T = fly_time + pause_time;
		int n = time / T;
		int r = min(time % T, fly_time);
		int dist = n * speed * fly_time + r * speed;

		params[i].speed = speed;
		params[i].fly_time = fly_time;
		params[i].pause_time = pause_time;

		max_dist = max(max_dist, dist);

		free(value);
	}

	int solution1 = max_dist;
	int solution2 = compute_points(params, lines->length);

	printf("solution1: %d\n", solution1);
	printf("solution2: %d\n", solution2);
	return 0;
}
