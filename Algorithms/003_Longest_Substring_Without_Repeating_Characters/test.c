/*************************************************************************
	> File Name: Algorithms/003_Longest_Substring_Without_Repeating_Characters/test.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Tue 11 Aug 2015 04:26:44 PM CST
 ************************************************************************/

#include<stdio.h>

#include "longestSubstringWithoutRepeatingCharacters.c"


int main(void) {
	char *s = "abbacb";
	int res;

	res = lengthOfLongestSubstring(s);

	printf("input:\n");
	printf("\t%s\n", s);
	printf("output:\n");
	printf("\t%d\n", res);
}
