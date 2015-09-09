/*************************************************************************
	> File Name: Algorithms/002_Add_Two_Numbers/test.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Tue 11 Aug 2015 04:26:44 PM CST
 ************************************************************************/

#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

#include "addTwoNumbers.II.c"

struct ListNode* createList(int num) {
	struct ListNode *res, *cur, *next;
	int i;

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

void printList(struct ListNode* l) {
	while (NULL != l) {
		printf("%d -> ", l->val);
		l = l->next;
	}
	printf("end\n");
}

int main(void) {
	int a1 = 81, a2 = 0;
	struct ListNode *l1, *l2, *res;

	l1 = createList(a1);
	l2 = createList(a2);

	res = addTwoNumbers(l1, l2);

	printf("input:\n\t");
	printList(l1);
	printf("\t");
	printList(l2);
	printf("output:\n\t");
	printList(res);

	//free();
}
