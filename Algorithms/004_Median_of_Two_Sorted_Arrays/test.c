/*************************************************************************
	> File Name: Algorithms/004_Median_of_Two_Sorted_Arrays/test.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Tue 11 Aug 2015 04:26:44 PM CST
 ************************************************************************/

#include<stdio.h>

#include "medianOfTwoSortedArrays.c"

int main(void) {
	int nums1[] = {3};
	int nums2[] = {4,5};
	int nums1Size, nums2Size, i;
	double res;

	nums1Size = sizeof(nums1)/sizeof(int);
	nums2Size = sizeof(nums2)/sizeof(int);

	printf("input:\n");
	printf("\tnums1 = {");
	for (i = 0; i < nums1Size; i++) {
		printf("%d", nums1[i]);
		if (i != nums1Size - 1) {
			printf(",");		
		}
	}
	printf("}\n");
	printf("\tnums2 = {");
	for (i = 0; i < nums2Size; i++) {
		printf("%d", nums2[i]);
		if (i != nums2Size - 1) {
			printf(",");		
		}
	}
	printf("}\n");
	
	res = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);

	printf("output:\n");
	printf("\t%lf\n", res);
}
