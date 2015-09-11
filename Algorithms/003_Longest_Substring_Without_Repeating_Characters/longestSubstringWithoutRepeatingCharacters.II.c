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
	int leftBottom, leftTop, rightBottom, rightTop;
	char *p;
	unsigned char value;

	for (i = 0; i < 256; i++) {
		ht[i] = -1;
	}

	size = strlen(s);
	leftBottom = leftTop = rightBottom = rightTop = 0;
	leftlen = rightlen = 0;
	for (i = 0; i < size; i++) {
		value = (unsigned char)s[i];
		if (-1 == ht[value]) {
			rightlen += 1;
			rightTop += 1;
		} else {
			if (leftlen > rightlen) {

			} else {
				leftlen = rightlen;
				leftBottom = rightBottom;
				leftTop = rightTop;
			}

			if (i - ht[value] > rightlen) {
				rightlen += 1;
			} else {
				rightlen = i - ht[value];
				rightBottom = ht[value] + 1;
			}
			rightTop += 1;
		}
		ht[value] = i;
	}
	
	/* printf("%d, %d, %d, %d\n", leftBottom, leftTop, rightBottom, rightTop);
	printf("%.*s\n", leftlen, s+leftBottom);
	printf("%.*s\n", rightlen, s+rightBottom); */

	if (leftlen > rightlen) {
		printf("longest substring whitout repeating is : %.*s\n", leftlen, s + leftBottom);
		return leftlen;
	} else {
		printf("longest substring without repeating is : %.*s", rightlen, s + rightBottom);
		return rightlen;
	}
}
