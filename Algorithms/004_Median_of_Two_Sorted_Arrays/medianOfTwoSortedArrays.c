/*************************************************************************
	> File Name: medianOfTwoSortedArrays.c
	> Author: Hans
	> Mail: hzhang.hust@gmail.com
	> Created Time: Fri 11 Sep 2015 04:20:18 PM CST
 ************************************************************************/

/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity 
 * should be O(log (m+n)).
 */

#include<stdio.h>

/* 
 * find the k-th smallest elements of arrays nums1 & nums2 
 * we assume k must small than total/2
 */
double findKth(int *nums1, int nums1Size, int *nums2, int nums2Size, int k) {
	int pa, pb;

	if (nums1Size > nums2Size) {
		return findKth(nums2, nums2Size, nums1, nums1Size, k);
	}

	if (0 == nums1Size) {
		return nums2[k - 1];
	}
	if (1 == k) {
		return nums1[0] > nums2[0] ? nums2[0] : nums1[0];
	}

	pa = nums1Size > k/2 ? k/2 : nums1Size;
	pb = k - pa;

	if (nums1[pa - 1] < nums2[pb -1]) {
		return findKth(nums1 + pa, nums1Size - pa, nums2, nums2Size, k - pa);
	} else if (nums1[pa -1] > nums2[pb -1]) {
		return findKth(nums1, nums1Size, nums2 + pb, nums2Size - pb, k - pb);
	} else {
		return nums1[pa -1];
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int total;
	
	total = nums1Size + nums2Size;

	if (total & 0x1) {
		return findKth(nums1, nums1Size, nums2, nums2Size, total/2 + 1);
	} else {
		return (findKth(nums1, nums1Size, nums2, nums2Size, total/2)
			+ findKth(nums1, nums1Size, nums2, nums2Size, total/2 + 1))/2;
	}
}
