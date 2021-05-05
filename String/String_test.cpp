#include <stdio.h>
#include <string.h>

#include "StringTring.h"

/*
 * Test function to check if a string has all unique characters (case sensitive, insensitive)
 */

#define TEST1_STRINGS		{"interview","abcdefghijklmnopqrstuvwxyz","abcdefghijklmnoPqrstuvwxyza","aA","zZ","zA","pQrsSTt","abcxyzZ","aAbcxyzz","abxyzZACc"}
#define TEST1_NUM_STRINGS	10

void string_test_1(void)
{
	const char* inputString[] = TEST1_STRINGS;
	int loop;

	printf("\n ==== STIRING TEST 1 ==== ");

	printf("\n ---- CASE_SENSITIVE ---- ");
	for (loop = 0; loop < TEST1_NUM_STRINGS; loop++) {
		printf("\n%s:", inputString[loop]);

		printf("\n  : is %s",
			(String_chck_unique_chars(inputString[loop], CASE_SENSITIVE) ? "Unique" : "Not Unique"));

		printf("\n");
	}

	printf("\n ---- CASE_INSENSITIVE ---- ");
	for (loop = 0; loop < TEST1_NUM_STRINGS; loop++) {
		printf("\n%s:", inputString[loop]);

		printf("\n  : is %s",
			(String_chck_unique_chars(inputString[loop], CASE_INSENSITIVE) ? "Unique" : "Not Unique"));

		printf("\n");
	}

	printf("\n");
	return;
}


/*
 * Test function to check if a string is permutation of another string (case sensitive, insensitive)
 */

#define TEST2_NUM_STRINGS	10
#define TEST2_STRING_A		{"ABCDE", "AABCDE", "JOKE","OWN","OWNER","ABC","AAA","zzz","Looop","AmitJain"}
#define TEST2_STRING_B		{"EBCDA", "ABCDEE", "oKJe","CLOWN","clown","AAA","aAa","ZZZ","Poool","jAaMiInT"}

void string_test_2(void)
{
	const char* test_string_A[] = TEST2_STRING_A;
	const char* test_string_B[] = TEST2_STRING_B;

	int loop;

	printf("\n ==== STIRING TEST 2 ==== ");

	printf("\n ---- CASE_INSENSITIVE ---- ");
	for (loop = 0; loop < TEST2_NUM_STRINGS; loop++) {
		printf("\n%s is %s a Permutation of %s",
			test_string_A[loop],
			(String_chck_permutation(test_string_A[loop], test_string_B[loop], CASE_INSENSITIVE) ? "" : "NOT"),
			test_string_B[loop]);
	}

	printf("\n");

	printf("\n ---- CASE_SENSITIVE ---- ");
	for (loop = 0; loop < TEST2_NUM_STRINGS; loop++) {
		printf("\n%s is %s a Permutation of %s",
			test_string_A[loop],
			(String_chck_permutation(test_string_A[loop], test_string_B[loop], CASE_SENSITIVE) ? "" : "NOT"),
			test_string_B[loop]);
	}

	printf("\n");
	return;
}


/*
 * Test function to determine if two strings are One edit away (1 insertion/removal/replacement)
 */

#define TEST3_NUM_STRINGS	5
#define TEST3_STRING_A		{"pale", "pales", "PALE","pale","abc"}
#define TEST3_STRING_B		{"ple", "pale", "bALE", "bake","abc"}

void string_test_3(void)
{
	const char* test_string_A[] = TEST3_STRING_A;
	const char* test_string_B[] = TEST3_STRING_B;

	int loop;

	printf("\n ==== STIRING TEST 3 ==== \n");

	for (loop = 0; loop < TEST3_NUM_STRINGS; loop++) {
		printf("%s is %s One edit away from %s\n",
			test_string_A[loop],
			(String_chk_edits(test_string_A[loop], test_string_B[loop]) ? "" : "NOT"),
			test_string_B[loop]);

		printf("\n");
	}

	printf("\n");
	return;
}