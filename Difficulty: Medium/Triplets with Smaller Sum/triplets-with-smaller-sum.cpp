class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        int n = arr.size();
        int count=0;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;
            
            while(left < right){
                int result_sum = arr[i]+arr[left]+arr[right];
                if(result_sum < sum){
                   int possible_combinaton = right-left;
                   count+=possible_combinaton;
                    left++;
                }
                else if(result_sum > sum  || result_sum == sum){
                    right--;
                }

            }
            
        }
        return count;
    }
};