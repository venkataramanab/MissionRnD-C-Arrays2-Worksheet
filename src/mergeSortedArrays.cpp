/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
bool __isOlder(char *A, char *B);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if ((A != NULL) && (B != NULL) && (ALen > 0) && (BLen > 0)){
		transaction *result = NULL;
		int A_index = 0, B_index = 0, R_index = 0;
		while ((A_index < ALen) && (B_index < BLen)){
			result = (transaction*)realloc(result, sizeof(transaction)*(R_index + 1));
			if (__isOlder(A[A_index].date, B[B_index].date)){
				result[R_index++] = B[B_index++];
			}
			else{
				result[R_index++] = A[A_index++];
			}
		}
		while (A_index < ALen){
			result = (transaction*)realloc(result, sizeof(transaction)*(R_index + 1));
			result[R_index++] = A[A_index++];
		}
		while (B_index < BLen){
			result = (transaction*)realloc(result, sizeof(transaction)*(R_index + 1));
			result[R_index++] = B[B_index++];
		}
		return result;
	}
	else{
		return NULL;
	}
}
bool __isOlder(char *A, char *B){
	int ptr[8] = { 6, 7, 8, 9, 3, 4, 0, 1 };
	for (int i = 0; i < 8; i++){
		if (B[ptr[i]] != A[ptr[i]]){
			if (B[ptr[i]] < A[ptr[i]])
				return true;
			break;
		}
	}
	return false;
}