/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
bool dateValidation(char*);
int compareDate(char *Arr, char *date);
int numValidate(char ch);
bool checkYear(int);
int getDay(char, char);
int getMonth(char, char);
int getYear(char, char, char, char);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (dateValidation(date)){
		int count = 0;
		for (int i = 0; i < len; i++){
			count += compareDate(Arr[i].date, date);
		}
		return count;
	}
	return NULL;
}
int compareDate(char *Arr, char *date){
	int ptr[8] = { 6, 7, 8, 9, 3, 4, 0, 1 };
	for (int i = 0; i < 8; i++){
		if (date[ptr[i]] != Arr[ptr[i]]){
			if (date[ptr[i]] < Arr[ptr[i]])
				return 1;
			break;
		}
	}
	return 0;
}
bool dateValidation(char *date){
	if ((date[2] == '-') && (date[5] == '-')){
		int day, month, year;
		day = getDay(date[0], date[1]);
		month = getMonth(date[3], date[4]);
		year = getYear(date[6], date[7], date[8], date[9]);
		if ((day > 0) && (month > 0) && (year > 0) && (month < 13) && (day<32)){
			bool leapyearFlag = false;
			if (checkYear(year)){
				leapyearFlag = true;
			}
			if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day <= 31)){
				return true;
			}
			else if ((month == 2) && ((leapyearFlag && (day <= 29)) || (day <= 28))){
				return true;
			}
			else{
				return true;
			}
		}
	}
	return false;
}
int getDay(char ch1, char ch2){
	//------------get date in month-----------------
	int temp1, temp2;
	temp1 = numValidate(ch1);
	temp2 = numValidate(ch2);
	//-----------checks for returned value from numvalidate func--------------
	if ((temp1>-1) && (temp2>-1)){
		return temp1 * 10 + temp2;
	}
	return -1;
}
int getMonth(char ch1, char ch2){
	return getDay(ch1, ch2);
}
int getYear(char ch1, char ch2, char ch3, char ch4){
	int temp1 = getDay(ch1, ch2);
	int temp2 = getDay(ch3, ch4);
	if ((temp1 > -1) && (temp2 > -1)){
		return temp1 * 100 + temp2;
	}
	return -1;
}
int numValidate(char ch){
	int num = ch - '0';
	//---------checks for numerical value----------
	if ((num > -1) && (num < 10)){
		return num;
	}
	else{
		return -1;
	}
}
bool checkYear(int year){
	if (year % 400 == 0){
		return true;
	}
	else if ((year % 4 == 0) && (year % 100 != 0)){
		return true;
	}
	else{
		return false;
	}
}