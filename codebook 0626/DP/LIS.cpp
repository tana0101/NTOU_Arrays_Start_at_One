/*LIS 最長遞增子序列*/
int LIS(int n, int s[], int length[]) {
	for (int i = 0; i < n; i++) length[i] = 1;
	for (int j = 0; j < n; j++) 
		for (int i = j + 1; i < n; i++)
			if (s[j] < s[i]) length[i] = 
				max(length[i], length[j] + 1);
	return *max_element(length, length+n);
