class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int max_sum=0;
        int sum=0;
        
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        
        max_sum = sum;
        
        for(int i=k;i<n;i++){  //or-->i<n
            sum+=arr[i];
            sum-=arr[i-k];
            max_sum = max(sum,max_sum);
        }
        return max_sum;
        
    }
};