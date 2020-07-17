int findNumbers(vector<int>& nums) {
	int d, count = 0;
	for (int a : nums) {
		d = 0;
		while (a > 0) {
			a /= 10;
			d++;
		}
		if (d % 2 == 0) {
			count++;
		}
	}
	return count;
}
