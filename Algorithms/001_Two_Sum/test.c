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

#include"twoSum.III.c"

int main(void) {
	int *nums, *index, numsSize, target;
	int a[] = {1, 272, 540, 4};
	int i;

	nums = a;
	numsSize = sizeof(a)/sizeof(int);
	target = 544;

	printf("input:\n");
	printf("\tnums = {");
	for (i = 0; i < numsSize; i++) {
		printf("%d", nums[i]);
		if (i != numsSize - 1) {
			printf(",");
		}
	}
	printf("}, target = %d\n", target);
	index = twoSum(nums, numsSize, target);
	printf("output:\n");
	printf("\tindex1 = %d, index2 = %d\n", index[0], index[1]);
	
	free(index);
}
