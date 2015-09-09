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

long listToNumber(struct ListNode * l) {
	long num = 0, tmp = 1;
	while (NULL != l) {
		num += (l->val)*tmp;
		tmp *= 10;
		l = l->next;
	}
	return num;
}

struct ListNode* numberToList(long num) {
	struct ListNode *res, *cur, *next;
	long i;

	res = (struct ListNode*)malloc(sizeof(struct ListNode));
	cur = res;

	while (num > 9) {
		i = num % 10;
		num = num / 10;
		cur->val = i;
		next= (struct ListNode*)malloc(sizeof(struct ListNode));
		cur->next = next;
		cur = next;	
	}
	cur->val = num;
	cur->next = NULL;
	return res;
}

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *		int val;
 *		struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *res;
	long x, y;

	if (NULL == l1 || NULL == l2) {
		printf("input error\n");
		return NULL;
	}
	res = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (NULL == res) {
		printf("malloc failed\n");
		return NULL;
	}
	x = listToNumber(l1);
	y = listToNumber(l2);
	res = numberToList(x + y);

	return res;
}
