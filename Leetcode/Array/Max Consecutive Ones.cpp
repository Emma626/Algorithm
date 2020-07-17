int findMaxConsecutiveOnes(vector<int>& nums) {
	int ans = 0,curMax = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 1) {
			curMax++;
		}
		else {
			ans = max(ans, curMax);
			curMax = 0;
		}
	}
	ans = max(ans, curMax);
	return ans;
}
