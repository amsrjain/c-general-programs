#include <stdio.h>
#include <string.h>

#include "StringTring.h"

/* This file holds generic utility functions for strings logic */

/*
 * function to return a characters index between A to Z
 */
int get_char_idx(const char* one_char, bool is_case_sensitive)
{
	int char_idx;

	// figure out the index of the character in the string
	// consider if case sensitive uniqueness is requested

	if ((*one_char >= 'a') && (*one_char <= 'z')) {
		char_idx = *one_char % 'a';
	}
	else if ((*one_char >= 'A') && (*one_char <= 'Z')) {
		if (!is_case_sensitive)
			char_idx = *one_char % 'A';
		else
			char_idx = (*one_char % 'A') + NUM_CHARS;
	}
	else {
		char_idx = -1; // this is error
	}

	return char_idx;
}

/*
 * get number of characters in a string
 */
int get_char_cnt(const char* str) {

	int count = 0;
	while (*str != '\0') {
		count++;
		str++;
	}

	// printf("count = %d \n", count);

	return count;
}