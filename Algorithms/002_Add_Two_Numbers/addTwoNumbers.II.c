/*************************************************************************
	> File Name: addTwoNumbers.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Tue 08 Sep 2015 08:09:35 PM CST
 ************************************************************************/

/*
 * You are given two linked lists representing two non-negative numbers. The digits are 
 * stored in reverse order and each of their nodes contain a single digit. Add the two 
 * numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */

#include<stdio.h>
#include<stdlib.h>

int getValueAndMoveToNext(struct ListNode** l) {
	int x = 0;
	if (NULL != *l) {
		x = (*l)->val;
		*l = (*l)->next;
	}
	return x;
}

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *		int val;
 *		struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *res, *cur, *next;
	int carry = 0, sum = 0, x, y;

	if (NULL == l1 || NULL == l2) {
		printf("input error\n");
		return NULL;
	}
	res = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (NULL == res) {
		printf("malloc failed\n");
		return NULL;
	}
	cur = res;

	while (NULL != l1 || NULL != l2) {
		x = getValueAndMoveToNext(&l1);
		y = getValueAndMoveToNext(&l2);
		sum = x + y + carry;
		cur->val = sum % 10;
		carry = sum / 10;
		if (0 == carry && NULL == l1 && NULL == l2) {
			cur->next = NULL;
			return res;
		}
		next = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (NULL == next) {
			printf("malloc failed\n");
			return NULL;
		}
		cur->next = next;
		cur = next;
	}

	/* carry = 1, l1 = l2 = NULL*/
	cur->val = carry;
	cur->next = NULL;

	return res;
}
