#include <stdio.h>
#include <string.h>

#include "StringTring.h"

/* 
 * Write a method to decide if one string is permutation of another
 */

bool String_chck_permutation(const char* strA, const char* strB, bool is_case_sensitive)
{
	int		str_a_char_cnt = 0;
	int		str_b_char_cnt = 0;
	int		char_count[NUM_CHARS * 2] = { 0 };
	int		char_idx;
	int		loop;

	// check all chars of first string and count each occurrence
	while (*strA != '\0') {
		char_idx = get_char_idx(strA, is_case_sensitive);
		if (char_idx == -1)
			return false;

		char_count[char_idx]++;

		// printf("Char %c = %d \n", (char) *strA, char_count[char_idx]);

		str_a_char_cnt++;
		strA++;
	}

	// for each character in 2nd string, decrement their count from 1st string
	while (*strB != '\0') {
		char_idx = get_char_idx(strB, is_case_sensitive);
		if (char_idx == -1)
			return false;

		// if character wasn't in 1ts string, string cannot be a permutation
		if (char_count[char_idx] == 0)
			return false;

		char_count[char_idx]--;
		
		// printf("Char %c = %d \n", (char) *strB, char_count[char_idx]);

		str_b_char_cnt++;
		strB++;
	}

	// if the length differes, they cannot be permutation of each other
	if (str_a_char_cnt != str_b_char_cnt) {
		printf("string length differs \n");
		return false;
	}

	// if any character is non-zero, the permutation check fails
	for (loop = 0; loop < (NUM_CHARS * 2); loop++)
		if (char_count[loop])
			return false;

	return true;

}



