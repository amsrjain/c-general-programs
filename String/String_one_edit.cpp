#include <stdio.h>
#include <string.h>

#include "StringTring.h"

/*
 * Function to determine if two strings are One edit away (1 insertion/removal/replacement)
 */

bool String_chk_edits(const char* strA, const char* strB)
{
	int		str_a_char_cnt = get_char_cnt(strA);
	int		str_b_char_cnt = get_char_cnt(strB);

	bool	one_replacement = false;
	bool	one_insert = false;
	bool	one_remove = false;

	int		num_edit = 0;

	// make initial assessment based on the count of characters in both strings
	if (str_a_char_cnt == str_b_char_cnt)
		one_replacement = true;
	else if ((str_a_char_cnt - str_b_char_cnt) == 1)
		one_insert = true;
	else if ((str_b_char_cnt - str_a_char_cnt) == 1)
		one_remove = true;
	else
		return false;

	// check each char in both strings and compare to decide if there are more than one change
	while ((*strA != '\0') || (*strB != '\0')) {

		if (*strA == *strB) {
			strA++;
			strB++;
			continue;
		}
		else {
			num_edit++;
			if (num_edit > 1) {
				printf("%c and %c \n", (char)*strA, (char)*strB);
				return false;
			}

			if (one_replacement) {
				strA++;
				strB++;
			}
			else if (one_insert)
				strA++;
			else if (one_remove)
				strB++;
			else
				// should never come here
				printf("Unexpected \n");
		}
	}

	printf("one_replacement: %d,  one_insert: %d, one_remove: %d \n", one_replacement, one_insert, one_remove);
	return true;
}



