/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
bool _isEqual(char *Arr, char *date);
bool _isOlder(char *A, char *B);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = NULL;
	int k = 0;
	if ((A != NULL) && (B != NULL) && (ALen > 0) && (BLen > 0)){
		for (int i = 0; i < ALen; i++){
			for (int j = 0; j < BLen; j++){
				if (!_isOlder(A[i].date, B[j].date)){
					if (_isEqual(A[i].date, B[j].date)){
						result = (struct transaction *)realloc(result, sizeof(struct transaction)*(k + 1));
						result[k++] = B[j];
						break;
					}
					else{
						break;
					}
				}
			}
		}
		if (k>0){
			return result;
		}
	}
	return NULL;
}
bool _isEqual(char *Arr, char *date){
	int count = 0;
	int ptr[8] = { 6, 7, 8, 9, 3, 4, 0, 1 };
	for (int i = 0; i < 8; i++){
		if (date[ptr[i]] == Arr[ptr[i]]){
			count++;
		}
	}
	if (count == 8){
		return true;
	}
	return false;
}
bool _isOlder(char *A, char *B){
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