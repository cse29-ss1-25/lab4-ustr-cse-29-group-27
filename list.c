#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ustr.h"
#include "list.h"

/*
Returns an empty list of initial_capacity
*/
List new_list(int32_t initial_capacity) {
    List list;
    list.size = 0;
    list.capacity = initial_capacity;
    list.data = malloc(initial_capacity * sizeof(struct UStr));
    return list;
}

/*
Initializes an list of length size with elements from array
*/
List new_list_from_array(struct UStr* array, int32_t size) {
    List list = new_list(size);
    for (int32_t i = 0; i < size; i++) {
        list.data[i] = array[i];
    }
    list.size = size;
    return list;
}


/*
Given a list of strings and a separator string, returns a single string 
containing all the strings in list joined by the separator.
*/
UStr join(List* list, UStr separator) {
	Ustr result;

	if(!list || list->size == 0){
		result.codepoints = 0;
		result.bytes = 0;
		result.is_ascii = 1;
		result.contents = malloc(1);
		result.contents[0] = '\0';
		return result;
	}

	int total_bytes = 0;

	for (int i = 0; i < list->size; i++){
		total_bytes += list->data[i].bytes;
		if (I < list->size - 1){
			total_bytes += seperator.bytes;
		}
	}
	char* buffer = malloc(total_bytes + 1);
	if (!buffer){
		result.codepoints = 0;
		result.bytes = 0;
		result.is_ascii = 1;
		result.contents = NULL;
		return result;
	}

	int offset = 0;
	for (int i = 0; i < list->size; i++){
		memcpy(buffer + offset, list->data[i].contents, list->data[i].bytes);
		offset+= list->data[i].bytes;

		if (i < list->size - 1){
			memcpy(buffer+offset, seperator.contents, seperator.bytes);
		offset+= seperator.bytes;	
		}
	}
	buffer[offset] = '\0';

	result.contents = buffer; 
	result.bytes = total_bytes;
	int codepoints_total = 0;

	for (int i = 0; i < list->size, i++){
		codepoints_total += list->data[i].codepoints;
		if (i < list->size - 1){
			codepoints_total += seperator.codepoints;
		}
	}

	result.is_ascii = 1;
	for (int i =0; i < list->size; i++){
		if (!list->data[i].is_ascii){
			result.is_ascii = 0;
			break;
		}
	}
	if (seperator.is_ascii == 0){
		result.is_ascii = 0;
	}
	return result;

}

/*
Inserts string s into list at index s, shifting elements to the right.
Expands the list's capacity if necessary (double the capacity, or set to 1 if 0).

Returns 1 on success, 0 if the index is invalid (out of bounds).
*/
int8_t insert(List* list, UStr s, int32_t index) {
	if (!list || index < 0 || index > list->size){
		return 0;
	}

	if (list->size >= list->capacity){
		int32_t newCapacity;
		if (list->capacity == 0){
			newCapacity = 1;
		}
		else{
			newCapacity = list->capacity * 2;
		}

		struct UStr* newData = realloc(list->data, newCapacity * sizeof(UStr));
		if (!new_data){
			return 0;
		}
		list->data = new_data;
		list->capacity = newCapacity;
	}

	for (int32_t i = list->size; i > index; --i){
		list->data[i] = list->data[i-1];
	}

	list->data[index] = s;
	list->size++;

	return 1;

}

/*
Removes the element at the given index and shifts all subsequent elements left.

Returns 1 on success, 0 if the index is invalid (out of bounds).
*/
int8_t listRemoveAt(List* list, int32_t index) {
    // TODO: implement this

}

/*
Splits the given string s into substrings separated by the given delimiter string.

Returns a List of String objects, each containing a segment between delimiters.

If the delimiter is the empty string, return a list containing the original 
string as a single element.

If the input string ends with the delimiter, include an empty string at the 
end of the result.

Note that the delimiter could be of a length of more than 1 character
*/
List split(UStr s, UStr separator) {
    // TODO: implement this

}
