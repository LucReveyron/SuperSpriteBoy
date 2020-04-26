/*
 * P_matrix.h
 *
 *  Created on: Dec 22, 2019
 *  Author: Simón Prêcheur Llarena
 *
 *  This module deals with the creation of the occupancy grids/masks,
 *  For each level.
 *
 */

#ifndef MATRIX_H_
#define MATRIX_H_

void matrix_add_borders(int* OCCUPANCY_GRID);
void create_forest_mask(int* OCCUPANCY_GRID);
void create_castle_mask(int* OCCUPANCY_GRID);
void create_boss_mask(int *OCCUPANCY_GRID);

#endif /* MATRIX_H_ */
