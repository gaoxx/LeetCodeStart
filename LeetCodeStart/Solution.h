#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
public:
	//array
	void rotate(vector<int>& nums, int k);
	int removeElement(int A[], int n, int elem);
	int removeDuplicates(int A[], int n);
	vector<int> plusOne(vector<int> & digits);
	vector<vector<int> > generate(int numRows);
	vector<int> getRow(int rowIndex);
	//hash table
	vector<int> twoSum(vector<int> &numbers, int target);
	bool isValidSudoku(vector<vector <char>>&board);
	int singleNumber(int A[], int n);
	string convert(string s, int nRows);
	bool isPalindrome(string s);
	int search(int A[], int n, int target);
	bool search(vector<int>& nums, int target);
	int majorityElement(vector<int>& nums);
};

