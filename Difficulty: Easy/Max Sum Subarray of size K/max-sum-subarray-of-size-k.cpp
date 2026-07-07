class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // Brutforce
        // int maxSum=0;
        // for(int i=0;i<=arr.size()-k;i++){
        //     int sum=0;
        //     for(int j=i;j<i+k;j++){
        //         sum+=arr[j];
        //     }
        //     maxSum=max(maxSum,sum);
        // }
        // return maxSum;
        
        
        // 2 pointer
        int maxSum=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        maxSum=sum;
        
        for(int j=k;j<arr.size();j++){
            sum= sum - arr[j-k];
            sum= sum + arr[j];
            maxSum=max(sum,maxSum);
        }
        return maxSum;
        
    }
};