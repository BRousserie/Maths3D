#include "Vectors.h"

#define setSize 3 // number of vectors in the set to be orthogonalized
array<vec, setSize> orthogonalize(array<vec, setSize> vectorsSet)
{
	array<vec, d> result;

	for (int i = 0; i < setSize; i++)
	{
		result[i] = vectorsSet[i];
		for (int k = 0; k < i; k++)
		{
			vec proj = projection(vectorsSet[i], result[k]); // proj(ei, ek')
			
			for (int axis = 0; axis < d; axis++) 
				result[i][axis] -= proj[axis]; // ei' -= proj(ei, ek'), axis by axis
		}
	}

	return result;
}
vec projection(vec P, vec Q)
{
	double factor = dotProduct(P, Q) / (norm(Q) * norm(Q));
	vec result;

	for (int i = 0; i < d; i++)
		result[i] = factor * Q[i];
	cout << "Projection of \n";
	printVec(P);
	cout << "With \n";
	printVec(Q);
	cout << "Results in : \n";
	printVec(result);
	cout << "\n\n\n";
	return result;
}

double dotProduct(vec P, vec Q)
{
	double result = 0;

	for (int i = 0; i < d; i++)
		result += P[i] * Q[i];

	return result;
}

double norm(vec P)
{
	double sumOfSquares = 0;
	for (int i = 0; i < d; i++)
		sumOfSquares += P[i] * P[i];

	return sqrt(sumOfSquares);
}

void testOrthogonalize()
{
	vec e1 = { sqrt(2) / 2, sqrt(2) / 2, 0 };
	vec e2 = { -1, 1,-1 };
	vec e3 = { 0,-2,-2 };
	array<vec, 3> vectorsSet = { e1, e2, e3 };
	array<vec, 3> orthogonalizedSet = orthogonalize(vectorsSet);

	cout << "The set of vectors : \n";
	for (int i = 0; i < 3; i++)
	{
		printVec(vectorsSet[i]);
		if (i != 2)  cout << ",";
		cout << endl;
	}
	cout << "Turns into the following set when orthogonalized : \n";
	for (int i = 0; i < 3; i++)
	{
		printVec(orthogonalizedSet[i]);
		if (i != 2)  cout << ",";
		cout << endl;
	}
}

void printVec(vec P)
{
	cout << "    { ";
	for (int j = 0; j < 3; j++)
	{
		cout << P[j];
		if (j != 2)  cout << ", ";
	}
	cout << " }";
}