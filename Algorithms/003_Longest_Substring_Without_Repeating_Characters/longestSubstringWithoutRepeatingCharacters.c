/*************************************************************************
	> File Name: longestSubstringWithoutRepeatingCharacters.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Wed 09 Sep 2015 06:55:54 PM CST
 ************************************************************************/

/*
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include<stdio.h>
#include<string.h>

/*
 * hashtable : key = char value; map to pos
 */

int lengthOfLongestSubstring(char* s) {
	int ht[256], i, size, leftlen, rightlen;
	char *p;
	unsigned char value;

	for (i = 0; i < 256; i++) {
		ht[i] = -1;
	}

	size = strlen(s);
	leftlen = rightlen = 0;
	for (i = 0; i < size; i++) {
		value = (unsigned char)s[i];
		if (-1 == ht[value]) {
			rightlen += 1;
		} else {
			leftlen = leftlen > rightlen ? leftlen : rightlen;
			rightlen = i - ht[value] > rightlen ? rightlen + 1: i- ht[value];
		}
		ht[value] = i;
	}

	return leftlen > rightlen ? leftlen : rightlen;
}
