#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int> &nums, int sum, int n, vector<vector<int>> &dp) {
  if (n == 0) {
    if (sum == 0) return true;
    else return false;
  }
  if (dp[n][sum] != -1) return dp[n][sum];
  if (nums[n - 1] <= sum) {
    int op1 = subsetSum(nums, sum - nums[n - 1], n - 1, dp);
    int op2 = subsetSum(nums, sum, n - 1, dp);
    return dp[n][sum] = op1 || op2;
  } else return dp[n][sum] = subsetSum(nums, sum, n - 1, dp);
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  int sum;
  cin >> sum;
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  if (subsetSum(nums, sum, n, dp)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
