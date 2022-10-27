#ifndef KNIGHT_H_FILE
#define KNIGHT_H_FILE

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define TABLE_SIZE 8

bool isAvailable(int32_t path[TABLE_SIZE + 1][TABLE_SIZE + 1], int32_t x_pos, int32_t y_pos);
bool knightTour(int32_t path[TABLE_SIZE + 1][TABLE_SIZE + 1], int32_t x_pos, int32_t y_pos, int32_t x_move[], int32_t y_move[], int32_t step_cnt);
bool putKnight(int32_t path[TABLE_SIZE + 1][TABLE_SIZE + 1], int32_t x_pos, int32_t y_pos);

#endif
