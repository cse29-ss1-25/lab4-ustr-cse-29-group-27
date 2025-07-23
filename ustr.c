#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ustr.h"
#include "pset1.h"

/*
Initializes a new UStr with contents
*/
UStr new_ustr(char* contents) {
	int32_t bytes = strlen(contents);
	int32_t codepoints = utf8_strlen(contents);
	uint8_t all_ascii = bytes == codepoints;
	char* contents_copy = malloc(bytes + 1);
	strcpy(contents_copy, contents);
	UStr s = {
		codepoints,
		bytes,
		all_ascii,
		contents_copy
	};
	return s;
}

/*
Returns length of string
*/
int32_t len(UStr s) {
	return s.codepoints;
}

/*
Returns a substring of str, starting at index start (inclusive) 
and ending at index end (exclusive).

Returns an empty string on invalid range.
*/
UStr substring(UStr s, int32_t start, int32_t end) {
	// TODO: implement this
	if (start >= s.codepoints || end > s.codepoints) {
		UStr temp = new_ustr("");
		return temp;
	}
	int starti = 0;
	for (int i = 0; i < start; i++) {
		int8_t temp = utf8_codepoint_size(s.contents[starti]);
		starti += temp;
	}
	int total = end - start;
	int endi = starti;
	for (int i = 0; i < total; i++) {
		endi += utf8_codepoint_size(s.contents[endi]);
	}
	int counter = 0;
	char* newarr = malloc(endi - starti + 1);
	for (int i = starti; i < endi; i++) {
		newarr[counter] = s.contents[i];
		counter++;
	}
	newarr[endi - starti] = '\0';
	UStr sub = new_ustr(newarr);
	return sub;
}

/*
Given 2 strings s1 and s2, returns a string that is the result of 
concatenating s1 and s2. 
*/
UStr concat(UStr s1, UStr s2) {
	// TODO: implement this

}

/*
Given a string s and an index, return a string with the character at index 
removed from the original string. 

Returns the original string if index is out of bounds.
*/
UStr removeAt(UStr s, int32_t index) {
	// TODO: implement this

}

/*
Given a string s, return s reversed. 

Example: reverse("apples🍎 and bananas🍌") = "🍌sananab dna 🍎selppa")
*/
UStr reverse(UStr s) {
	// TODO: implement this

}


void print_ustr(UStr s) {
	printf("%s [codepoints: %d | bytes: %d]", s.contents, s.codepoints, s.bytes);
}

void free_ustr(UStr s) {
	if (s.contents != NULL) {
		free(s.contents);
		s.contents = NULL;
	}
}

