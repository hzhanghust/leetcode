/*************************************************************************
	> File Name: Algorithms/001_Two_Sum/twoSum.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Tue 11 Aug 2015 04:26:44 PM CST
 ************************************************************************/

/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and 
 * index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include<stdio.h>
#include<stdlib.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int* index;
	int i, j;

	if (NULL == (index = (int*)malloc(sizeof(int) * 2))) {
		printf("malloc failed\n");
		return 0;
	}

	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				index[0] = i + 1;
				index[1] = j + 1;
				return index;
			}
		}
	}
}

