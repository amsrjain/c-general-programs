#pragma once

#define NUM_CHARS			26
#define CASE_SENSITIVE		true
#define CASE_INSENSITIVE	false

// function prototypes
int get_char_idx(const char* one_char, bool is_case_sensitive);
int get_char_cnt(const char* str);

bool String_chck_unique_chars(const char* stringRunner, bool caseSensitive);
bool String_chck_permutation(const char* strA, const char* strB, bool is_case_sensitive);
bool String_chk_edits(const char* strA, const char* strB);
