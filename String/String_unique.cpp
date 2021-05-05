#include <stdio.h>
#include <string.h>

#include "StringTring.h"

/*
 * Write an algorithm to determine if a string has all unique characters.
 * What if it cannot use any additional data structure
 */

bool String_chck_unique_chars(const char* string_runner, bool is_case_sensitive)
{
	int char_count[NUM_CHARS * 2] = { 0 };

	while (*string_runner != '\0') {

		int char_idx;

		// figure out the index of the character in the string
		// consider if case sensitive uniqueness is requested

		char_idx = get_char_idx(string_runner, is_case_sensitive);
		if (char_idx == -1) {
			printf("character violation. Exiting \n");
			return false;
		}

		// count up the character's count
		char_count[char_idx]++;
		
		// printf("Char %c = %d \n", (char) *string_runner, char_count[char_idx]);

		// check if the character is repeating
		if (char_count[char_idx] > 1) {
			printf("\n  : %c repeated", (char) *string_runner);
			return false;
		}

		string_runner++;
	}

	return true;
}

