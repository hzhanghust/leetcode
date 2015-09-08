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
 *
 * Remove the traversal numbers array of build hashTable. We can dynamic
 * add it.
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

int hashTableFind(plistNode hashTable, int *nums, int target) {
	int i, num;
	plistNode tailNode;

	num = abs(target % PRIME);	
	if (-1 == hashTable[num].index) {
		return -1;
	} else {
		if (nums[hashTable[num].index] == target) {
			return hashTable[num].index;
		} else {
			tailNode = hashTable[num].next;
			while (NULL != tailNode) {
				if (nums[tailNode->index] == target) {
					return tailNode->index;
				} else {
					tailNode = tailNode->next;
				}
			}
		}
	}

	return -1;
}

void hashTableInsert(plistNode hashTable, int num, int pos) {
	int tmp;
	plistNode tailNode;

	tmp = abs(num % PRIME);
	if (-1 == hashTable[tmp].index) {
		hashTable[tmp].index = pos;
	} else {
		tailNode = (plistNode)malloc(sizeof(listNode));
		if (NULL == tailNode) {
			printf("malloc tailNode failed\n");
			return;
		}
		tailNode->index = pos;
		tailNode->next = hashTable[tmp].next;
		hashTable[tmp].next = tailNode;
	}
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int* index;
	int i, pos;
	plistNode hashTable;

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
		pos = hashTableFind(hashTable, nums, target - nums[i]);
		if (-1 == pos) {
			hashTableInsert(hashTable, nums[i], i);
		} else {
			index[0] = pos + 1;
			index[1] = i + 1;
			hashTableFree(hashTable);
			return index;
		}
	}

	hashTableFree(hashTable);
	return 0;
}

