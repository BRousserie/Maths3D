#pragma once
#include "Maths3D.h"

#define d 3 // d for dimension
#define vec array<double, d>

array<vec, d> orthogonalize(const array<vec, d>& vectorsSet);

vec projection(const vec& P, const vec& Q);

vec perpendicularComp(const vec& P, const vec& Q);

double dotProduct(const vec& P, const vec& Q);

double norm(const vec& P);

void testOrthogonalize();

void printVec(const vec& P);

double triangleArea(const vec& A, const vec& B, const vec& C);

void testTriangleArea();