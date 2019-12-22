# Python 3 program to find Length of the 
# Longest AP (llap) in a given sorted set. 

# Returns length of the longest AP 
# subset in a given set 
def lenghtOfLongestAP(set, n): 

	if (n <= 2): 
		return n 

	# Create a table and initialize all 
	# values as 2. The value of L[i][j] 
	# stores LLAP with set[i] and set[j] 
	# as first two elements of AP. Only 
	# valid entries are the entries where j>i 
	L = [[0 for x in range(n)] 
			for y in range(n)] 
	llap = 2 # Initialize the result 

	# Fill entries in last column as 2. 
	# There will always be two elements 
	# in AP with last number of set as 
	# second element in AP 
	for i in range(n): 
		L[i][n - 1] = 2

	# Consider every element as second 
	# element of AP 
	for j in range(n - 2, 0, -1): 

		# Search for i and k for j 
		i = j - 1
		k = j + 1
		while(i >= 0 and k <= n - 1): 

			if (set[i] + set[k] < 2 * set[j]): 
				k += 1

			# Before changing i, set L[i][j] as 2 
			elif (set[i] + set[k] > 2 * set[j]): 
				L[i][j] = 2
				i -= 1

			else: 

				# Found i and k for j, LLAP with i and j 
				# as first two elements are equal to LLAP 
				# with j and k as first two elements plus 1. 
				# L[j][k] must have been filled before as 
				# we run the loop from right side 
				L[i][j] = L[j][k] + 1

				# Update overall LLAP, if needed 
				llap = max(llap, L[i][j]) 

				# Change i and k to fill more L[i][j] 
				# values for current j 
				i -= 1
				k += 1

				# If the loop was stopped due to k 
				# becoming more than n-1, set the 
				# remaining entties in column j as 2 
				while (i >= 0): 
					L[i][j] = 2
					i -= 1
	return llap 

# Driver Code 
if __name__ == "__main__": 
	
    print('Enter the array below - ')
    array = list(map(int, input().split()))
    length = len(array)
    print(lenghtOfLongestAP(array,length))

