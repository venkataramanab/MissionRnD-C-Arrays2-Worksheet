/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct hash{
	int num;
	int count;
}*var;
bool checkHash(int a, int len);
int findSingleOccurenceNumber(int *A, int len)
{
	if (A){
		int oneOccur = 0, twoOccur = 0, commonBit = 0;
		for (int i = 0; i < len; i++){
			twoOccur |= oneOccur&A[i];
			oneOccur ^= A[i];
			commonBit = ~(oneOccur&twoOccur);
			oneOccur &= commonBit;
			twoOccur &= commonBit;
		}
		return oneOccur;
	}
	return -1;
}
/*
int findSingleOccurenceNumber(int *A, int len) {
	if (A && (len%3 == 1)){
		int hashLen = 0;
			do{
				if (!checkHash(A[len-1], hashLen)){
					var = (hash*)realloc(var, sizeof(hash)*(hashLen + 1));
					var[hashLen].num = A[len-1];
					var[hashLen++].count=1;
				}
			} while (--len);
			do{
				if (var[hashLen].count == 1){
					return var[hashLen].num;
				}
			} while (hashLen--);
	}
	return -1;
}
*/
/*
int findSingleOccurenceNumber(int *A, int len)
{
	if (A){
		int oneOccur = 0, twoOccur = 0;
			for (int i = 0; i<len; i++){
				if ((oneOccur&A[i]) == A[i]){
					twoOccur |= A[i];
					oneOccur &= ~A[i];
				}
				else if ((twoOccur&A[i]) == A[i]){
					twoOccur &= ~A[i];
				}
				else{
					oneOccur |= A[i];
				}
			}
			return oneOccur;
		}
	return -1;
}
*/
/*
bool checkHash(int a, int len){
	for (int i = 0; i < len; i++){
		if (var[i].num == a){
			var[i].count++;
			return true;
		}
	}
	return false;
}*/