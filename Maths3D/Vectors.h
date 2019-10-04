#pragma once
#include "Maths3D.h"

#define d 3 // d for dimension
#define vec array<double, d>

array<vec, d> orthogonalize(array<vec, d> vectorsSet);

vec projection(vec P, vec Q);

double dotProduct(vec P, vec Q);

double norm(vec P);

void testOrthogonalize();

void printVec(vec P);