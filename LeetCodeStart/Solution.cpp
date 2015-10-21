#include "Solution.h"
#include <iostream>
#include<map>
#include<algorithm>

using namespace std;
Solution::Solution()
{
}
Solution::~Solution()
{
}

void Solution::rotate(vector<int>& nums, int k)
{
	
}

int Solution::removeElement(int A[], int n, int elem)
{
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		if (elem != A[i])
			A[start++] = A[i];
	}
	return start;
}

int Solution::removeDuplicates(int A[], int n)
{
	if (!n)
		return 0;
	int start = 0;
	bool isRep = 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] == A[start] && !isRep)
		{
			A[++start] = A[i];
			isRep = 1;
		}
		else if (A[i] != A[start])
		{
			A[++start] = A[i];
			isRep = 0;
		}
	}
	cout << start + 1;
	return start + 1;
}

vector<int> Solution::plusOne(vector<int> &digits)
{
	vector<int> answer;
	int len = digits.size();
	int isFull = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		answer.insert(answer.begin(), (digits[i] + isFull) % 10);
		if (digits[i] == 9 && isFull == 1)
			continue;
		else
			isFull = 0;		
	}
	if (isFull)
		answer.insert(answer.begin(), 1);
	return answer;
}

vector<vector<int>>Solution::generate(int numRows)
{
	vector<vector<int>> result;
	if (numRows < 3)
	{
		switch (numRows)
		{
		case 1:
			result = { { 1 } };
			break;
		case 2:
			result = { { 1 }, { 1, 1 } };
			break;
		}
		//return result;
	}
	else
	{
		int row = 3;
		result = { { 1 }, { 1, 1 } };
		vector<int> last = { 1, 1 };
		while (row <= numRows)
		{
			vector<int> now;
			for (int i = 0; i < row; i++)
			{
				if (i == 0 || i == row - 1)
					now.push_back(1);
				else
					now.push_back(last[i - 1] + last[i]);
			}
			last = now;
			row++;
			result.push_back(now);
		}
	}
	return result;
}

vector<int> Solution::getRow(int rowIndex)
{
	/*
	1 [1,1]     2 [1,2,1]     3 [1,3,3,1]     4[1,4,6,4,1]
	*/
	vector<int> result;
	if (rowIndex == 0)
		result = { 1 };
	else if (rowIndex == 1)
		result = { 1, 1 };
	else
	{
		vector<int> last = { 1, 1 };
		for (int i = 1; i < rowIndex; i++)
		{
			result = {};
			for (int j = 0; j < i + 2; j++)
			{
				if (j == 0 || j == i + 1)
					result.push_back(1);
				else
					result.push_back(last[j - 1] + last[j]);
			}
			last = result;
		}
	}
	return result;
}

vector<int> Solution::twoSum(vector<int> &numbers, int target)   //用到哈希表map
{
	vector<int> result;
	map<int, int> numsMap;
	for (int i = 0; i < numbers.size(); i++)
	{
		numsMap.insert(pair<int, int>(numbers[i], i));
	}
	map<int, int>::iterator it;
	for (int j = 0; j < numbers.size(); j++)
	{
		it = numsMap.find(target - numbers[j]);
		if (it != numsMap.end() && it->second != j)
		{
			int index1 = j < it->second ? j + 1 : it->second + 1;
			int index2 = j < it->second ? it->second + 1 : j + 1;
			result.push_back(index1);
			result.push_back(index2);
			break;
		}
	}

	return result;
}

bool Solution::isValidSudoku(vector<vector<char>>&board)
{
	vector<vector<bool>> row(9, (vector<bool>(9, false)));
	vector<vector<bool>> line(9, (vector<bool>(9, false)));
	vector<vector<bool>> block(9, (vector<bool>(9, false)));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == '.')
				continue;
			int num = board[i][j] - '1';
			if (row[i][num] || line[j][num] || block[i - i%3 +j/3][num])
				return false;
			row[i][num] = line[j][num] = block[i - i % 3 + j / 3][num] = true;
		}
	}
	return true;
}

int Solution::singleNumber(int A[], int n)
{
	/*map<int, int> ary;
	for (int i = 0; i < n; i++)
	{
		if (ary.find(A[i]) == ary.end())
			ary.insert(pair<int, int>(A[i], i));
		else
			ary.erase(A[i]);
	}
	map<int, int>::iterator it = ary.begin();
	cout << it->first<<" " <<it->second;
	return it->first;*/
	int result = A[0];
	if (n != 1)
	{
		for (int i = 1; i < n; i++)
		{
			result = result ^ A[i];
		}
	}
	return result;
}

bool isInRange(char a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
		return true;
	return false;
}

bool Solution::isPalindrome(string s)
{
	int first = 0;
	int last = s.size() - 1;
	while (last > first)
	{
		if (!isInRange(s[first]))
		{
			first++;
			continue;
		}
		if (!isInRange(s[last]))
		{
			last--;
			continue;
		}
		if (s[first] != s[last] && abs(s[first] - s[last]) != abs('A' - 'a') )
			return false;
		else
		{
			first++;
			last--;
		}
	}
	return true;
}


string Solution::convert(string s, int n)
{
	if (s.size() <= n)
		return s;
	for (int i = 0; i < n; i++)
	{
		if (0 == i % (n * 2 - 2))
			s[i / (n * 2 - 2)] = s[i];
	}
}

int Solution::search(int A[], int n, int target)
{
	if (n == 0)
		return -1;
	if (target < A[0])       //从后往前找
	{
		int i = n;
		while (--i)
			if (A[i] == target)
				break;
		if (i != 0)
			return i;
	}
	else if (target > A[0])
	{
		int i = 0;
		while (++i < n)
			if (A[i] == target)
				break;
		if (i != n)
			return i;
	}
	else if (target == A[0])
		return 0;
	return -1;

}

bool Solution::search(vector<int>& nums, int target)
{
	

}

int Solution::majorityElement(vector<int>& nums)
{
	for (int i = 0; i = nums.size() - 1; i++)
	{

	}
}