#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

/*
Max Consecutive Ones
	Given a binary array, find the maximum number of consecutive 1s in this array.
Example 1:
	Input: [1,1,0,1,1,1]
	Output: 3
	Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

int findMaxConsecutiveOnes(vector<int>& nums) {
	int max = 0, maxCur = 0;
	for (int num : nums) {
		if (num == 1) {
			maxCur++;//当前元素为1，记录连续变量
		}
		else {
			max = std::max(max, maxCur);//每次更新最大的连续值
			maxCur = 0;
		}
	}
	max = std::max(max, maxCur);
	return max;
}

/*
Find Numbers with Even Number of Digits
	Given an array nums of integers, return how many of them contain an even number of digits.
Example 1:
	Input: nums = [12,345,2,6,7896]
	Output: 2 ————（12，7896）
Example 2:
	Input: nums = [555,901,482,1771]
	Output: 1 ————（1771）
*/

int findNumbers(vector<int>& nums) {
	int d, count = 0;
	for (int a : nums) {
		d = 0;
		while (a > 0) {
			a /= 10;
			d++;//记录位数
		}
		if (d % 2 == 0) {
			count++;
		}
	}
	return count;
}

/*
Squares of a Sorted Array
	Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
Example 1:
	Input: [-4,-1,0,3,10]
	Output: [0,1,9,16,100]
Example 2:
	Input: [-7,-3,2,3,11]
	Output: [4,9,9,49,121]
*/

vector<int> sortedSquares(vector<int>& A) {
	vector<int> ans(A.size());
	int i, j, i2, j2, k;
	i = 0;
	j = A.size() - 1;
	k = j;
	while (k >= 0) {
		i2 = A[i] * A[i];
		j2 = A[j] * A[j];
		if (i2 > j2) {		//比较平方大小
			ans[k--] = i2;	//从后往前添加数组元素
			i++;
		}
		else {
			ans[k--] = j2;
			j--;
		}
	}
	return ans;
}

/*
Duplicate Zeros
	Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
	Note that elements beyond the length of the original array are not written.
	Do the above modifications to the input array in place, do not return anything from your function.
Example 1:
	Input: [1,0,2,3,0,4,5,0]
	Output: null
	Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:
	Input: [1,2,3]
	Output: null
	Explanation: After calling your function, the input array is modified to: [1,2,3]
*/

void duplicateZeros(vector<int>& arr) {
	int count = 0, n = arr.size();
	for (int i : arr) {
		if (i == 0) {
			++count;//计算0个数
		}
	}
	//j指向拓展后的数组最后的值，i指向原数组的最后的值
	for (int i = n - 1, j = n - 1 + count; i >= 0; --i, --j) {
		if (j < n) {
			arr[j] = arr[i];
		}
		if (arr[i] == 0 && --j < n) {	//如果arr[i]==0，j往左移动，则复制0
			arr[j] = 0;
		}
	}
	//////////////Solution2//////////////
/*	int i, j, n;
	n = arr.size();
	j = n - 1;
	for (i = 0; i < j; i++) {//首先找到最右边的元素在原数组中的位置；
		if (arr[i] == 0) {
			j--;
		}
	}
	int left = n - 1;
	if (i == j && arr[j] == 0) {//如果最后一位0只复制1次
		arr[n - 1] = 0;
		left--;
		j--;
	}
	for (i = left; i >= 0; i--) {
		arr[i] = arr[j];
		if (arr[j] == 0) {//如果为0，复制两次
			i--;
			arr[i] = 0;
		}
		j--;
	}*/
}

/*
Merge Sorted Array
	Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
Note:
	The number of elements initialized in nums1 and nums2 are m and n respectively.
	You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:
	Input:
	nums1 = [1,2,3,0,0,0], m = 3
	nums2 = [2,5,6],       n = 3
	Output: [1,2,2,3,5,6]
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i, j,k;
	i = m - 1, j = n - 1, k = m + n - 1;//从后往前比较
	while (i >= 0 && j>=0) {
		if (nums1[i] > nums2[j]) {
			nums1[k--] = nums1[i--];
		}
		else {
			nums1[k--] = nums2[j--];
		}
	}
	while (i >= 0) {				//其中一个数组全部放置完全
		nums1[k--] = nums1[i--];
	}
	while (j >= 0) {
		nums1[k--] = nums2[j--];
	}
}

/*
Remove Element
	Given an array nums and a value val, remove all instances of that value in-place and return the new length.
	Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example 1:
	Input: nums = [3,2,2,3], val = 3,
	Output: 2
	Your function should return length = 2, with the first two elements of nums being 2.
Example 2:
	Input: nums = [0,1,2,2,3,0,4,2], val = 2,
	Output: 5
	Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
Note that the order of those five elements can be arbitrary.
It doesn't matter what values are set beyond the returned length.
*/

int removeElement(vector<int>& nums, int val) {
	int i=0;
	for (int j = 0; j < nums.size(); j++) {
		if (nums[j] != val) {
			nums[i++] = nums[j];//仅需添加不为val的值
		}
	}
	return i;

	///////////fater solution/////////////
	/*
	int i = 0, j = nums.size() - 1;
	while (i < j) {
		while (j > i && nums[j] == val) {	//找到值不为val的index
			j--;
		}
		while (i < j && nums[i] != val) {	//找到值为val的index
			i++;
		}
		if (i < j) {
			swap(nums[i++], nums[j--]);
		}
	}
	if (i < nums.size() && nums[i] != val) {	//添加未比较的值
		i++;
	}
	return i;
	*/
}

/*
Remove Duplicates from Sorted Array
	Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
	Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
	Input: [1,1,2],
	Output: 2
Example 2:
	Input: [0,0,1,1,1,2,2,3,3,4],
	Output: 5
*/

int removeDuplicates(vector<int>& nums) {
	int n = nums.size();
	int i = 0;
	for (int num : nums) {
		if (i<1 || num >nums[i - 1]) {//覆盖不重复的值
			nums[i++] = num;
		}
	}
	return i;
}

/*
Check If N and Its Double Exist
	Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
	More formally check if there exists two indices i and j such that :
	i != j
	0 <= i, j < arr.length
	arr[i] == 2 * arr[j]
Example 1:
	Input: arr = [10,2,5,3]
	Output: true
	Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:
	Input: arr = [7,1,14,11]
	Output: true
	Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:
	Input: arr = [3,1,7,11]
	Output: false
	Explanation: In this case does not exist N and M, such that N = 2 * M.
*/

bool checkIfExist(vector<int>& arr) {
	int i, j;
	unordered_set<int> hs;
	for (int i : arr) {
		if (hs.find(i * 2) != hs.end()) {//找改元素的倍数元素
			return true;
		}
		if (i % 2 == 0 && hs.find(i / 2) != hs.end()) {//如果是偶数，找/2的元素
			return true;
		}
		hs.insert(i);//都没有插入哈希表
	}
	return false;
}

/*
Valid Mountain Array
	Given an array A of integers, return true if and only if it is a valid mountain array.
	Recall that A is a mountain array if and only if:
		A.length >= 3
		There exists some i with 0 < i < A.length - 1 such that:
		A[0] < A[1] < ... A[i-1] < A[i]
		A[i] > A[i+1] > ... > A[A.length - 1]
Example 1:
	Input: [2,1]
	Output: false
Example 2:
	Input: [3,5,5]
	Output: false
Example 3:
	Input: [0,3,2,1]
	Output: true
*/
bool validMountainArray(vector<int>& A) {
	//A.size()<3 false
	if (A.size() < 3) {
		return false;
	}
	int i = 1;
	while (i < A.size() && A[i] > A[i - 1]) {//先递增
		i++;
	}
	if (i == A.size() || i == 1) { //单调递增或单调递减——false
		return false;
	}
	while (i < A.size() && A[i] < A[i - 1]) {//后递减
		i++;
	}
	if (i == A.size()) {
		return true;
	}
	return false;
}

/*
 Replace Elements with Greatest Element on Right Side
	Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
	After doing so, return the array.
Example 1:
	Input: arr = [17,18,5,4,6,1]
	Output: [18,6,6,6,1,-1]
*/

vector<int> replaceElements(vector<int>& arr) {
	if (arr.size() == 0) {
		return arr;
	}
	//从后往前，更新最大值
	int max = arr[arr.size() - 1];
	arr[arr.size() - 1] = -1;
	for (int i = arr.size() - 2; i >= 0; i--) {
		int t = arr[i];
		arr[i] = max;
		max = std::max(max, t);
	}
	return arr;
}

/*
Move Zeroes
	Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Example:
	Input: [0,1,0,3,12]
	Output: [1,3,12,0,0]
*/

void moveZeroes(vector<int>& nums) {
	int i, j;
	for (i = 0, j = 0; j < nums.size(); j++) {//按顺序排列
		if (nums[j] != 0) {
			nums[i++] = nums[j];
		}
	}
	while (i < nums.size()) {//末尾加上0
		nums[i++] = 0;
	}
}

/*
Sort Array By Parity
	Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
	You may return any answer array that satisfies this condition.
Example 1:
	Input: [3,1,2,4]
	Output: [2,4,3,1]
	The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
*/

vector<int> sortArrayByParity(vector<int>& A) {
	int i = 0, j = A.size() - 1;
	while (i < j) {
		while (i < j && A[i] % 2 == 0) {//找到基数
			i++;
		}
		while (i < j && A[j] % 2 != 0) {//找到偶数
			j--;
		}
		swap(A[i++], A[j--]);//交换
	}
	return A;
}

/*
Height Checker
	Students are asked to stand in non-decreasing order of heights for an annual photo.
	Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.
	Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students remain on their seats.
Example 1:
	Input: heights = [1,1,4,2,1,3]
	Output: 3
	Explanation:
	Current array : [1,1,4,2,1,3]
	Target array  : [1,1,1,2,3,4]
Example 2:
	Input: heights = [5,1,2,3,4]
	Output: 5
Example 3:
	Input: heights = [1,2,3,4,5]
	Output: 0
*/

int heightChecker(vector<int>& heights) {
	vector<int> copy(heights);
	sort(copy.begin(), copy.end());//先排序后比较
	int count = 0;
	for (int i = 0; i < heights.size(); i++) {
		if (copy[i] != heights[i]) {
			count++;
		}
	}
	return count;
}

/*
Third Maximum Number
	Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
Example 1:
	Input: [3, 2, 1]
	Output: 1
Example 2:
	Input: [1, 2]
	Output: 2
Example 3:
	Input: [2, 2, 3, 1]
	Output: 1
*/

int thirdMax(vector<int>& nums) {
	int n = nums.size();
	if (n < 3) {
		return *max_element(nums.begin(), nums.end());//数组元素小于3
	}
	set<int> s;
	for (int x : nums) {
		s.insert(x);
	}
	set<int>::iterator it = s.end();
	if (s.size() < 3) {
		return *(--it);//存在重复元素，导致不存在第3大的数
	}
	it--;//指向第3大的数
	it--;
	it--;
	return *it;
}

/*
Find All Numbers Disappeared in an Array
	Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
	Find all the elements of [1, n] inclusive that do not appear in this array.
	Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
Example:
	Input:
	[4,3,2,7,8,2,3,1]
	Output:
	[5,6]
*/

vector<int> findDisappearedNumbers(vector<int>& nums) {
	int i, j, val;
	for (i = 0; i < nums.size(); i++) {
		val = abs(nums[i]) - 1; //根据当前值找到对应位置的元素，加绝对值去除标记值的影响
		if (nums[val] > 0) {
			nums[val] *= -1;	//标记存在该值
		}
	}
	for (i = 0, j = 0; i < nums.size(); i++) {
		if (nums[i] > 0) {		//找到未标记过的位置
			nums[j++] = i + 1;
		}
	}
	nums.erase(nums.begin() + j, nums.end());//去除多余元素
	return nums;
}
