#include <bits/stdc++.h>

using namespace std;

// Problem Link: https://leetcode.com/problems/wildcard-matching/
/* Problem Statement:
    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

    Constraints:
    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like ? or *.

    Sample Test Cases:
    Example 1:
    Input:
    s = "aa"
    p = "a"
    Output: false
    Explanation: "a" does not match the entire string "aa".

    Example 2:
    Input:
    s = "aa"
    p = ""
    Output: true
    Explanation: '' matches any sequence.
*/

bool isMatch(string str, string pattern)
{
	int n = str.size(), m = pattern.size();

	// 2D dp array where dp[i][j] represents that the str[0...i] is matched to pattern[0...j]
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true;


	for (int i = 1; i <= m; ++i)
	{
		// base case when string is empty so pattern needs to be in ***... form
		if (dp[0][i - 1] && pattern[i - 1] == '*')
			dp[0][i] = true;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			// If both characters are equal or the current is '?' then the current position is matched so we need to check previous position
			if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			// Else if current in pattern is '*', it  matches any sequence of characters so let's assume the current in the string is part of the sequence
			else if (pattern[j - 1] == '*')
				dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
		}
	}
	return dp[n][m];
}

int main()
{
	//input string & pattern to be matched
	string str, pattern;
	cin >> str >> pattern;

	if (isMatch(str, pattern))
		cout << "Pattern Matched!" << endl;
	else
		cout << "Pattern Not Matched!" << endl;
	return 0;
}