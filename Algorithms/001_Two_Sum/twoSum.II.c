/*************************************************************************
	> File Name: Algorithms/001_Two_Sum/twoSum.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Mon 7 Sep 2015 04:26:44 PM CST
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

/*
 * hashTable: key = num value, mapping to the pos of nums array. 
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct linkListNode* plistNode;
typedef struct linkListNode {
	int index;
	plistNode next;
}listNode;

#define PRIME 271

void hashTableFree(plistNode hashTable) {
	int i;
	plistNode tailNode, tmp;

	for (i = 0; i < PRIME; i++) {
		tailNode = hashTable[i].next;
		while (NULL != tailNode) {
			tmp = tailNode;
			tailNode = tailNode->next;
			free(tmp);
		}
	}

	free(hashTable);
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int* index;
	int i, num;
	plistNode hashTable, tailNode;

	if (numsSize < 2) {
		printf("numsSize error\n");
		return 0;
	}

	if (NULL == (index = (int*)malloc(sizeof(int) * 2))) {
		printf("malloc failed\n");
		return 0;
	}

	hashTable = (plistNode)malloc(sizeof(listNode) * PRIME);
	if (NULL == hashTable){
		printf("malloc hashTable failed\n");
		return 0;
	}

	for (i = 0; i < PRIME; i++) {
		hashTable[i].index = -1;
		hashTable[i].next = NULL;
	}

	for (i = 0; i < numsSize; i++) {
		num = abs(nums[i] % PRIME);
		if (-1 == hashTable[num].index) {
			hashTable[num].index = i;
		} else {
			tailNode = (plistNode)malloc(sizeof(listNode));
			if (NULL == tailNode) {
				hashTableFree(hashTable);
				printf("malloc tailNode failed\n");
				return 0;
			}
			tailNode->index = i;
			tailNode->next = hashTable[num].next;
			hashTable[num].next = tailNode;
		}
	}

	for (i = 0; i < numsSize - 1; i++) {
		num = abs((target - nums[i]) % PRIME);
		if (-1 == hashTable[num].index) {
			continue;
		} else {
			if (((target - nums[i]) == nums[hashTable[num].index]) && (hashTable[num].index != i)) {
				index[0] = i + 1;
				index[1] = hashTable[num].index + 1;
				hashTableFree(hashTable);
				return index;
			} else {
				tailNode = hashTable[num].next;
				while (tailNode != NULL) {
					if (((target - nums[i]) == nums[tailNode->index]) && (tailNode->index != i)) {
						index[0] = i + 1;
						index[1] = tailNode->index + 1;
						hashTableFree(hashTable);
						return index;
					} else {
						tailNode = tailNode->next;
					}
				}
			}
		}
	}

	hashTableFree(hashTable);
	return 0;
}

