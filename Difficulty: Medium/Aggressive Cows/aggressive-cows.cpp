class Solution {
  public:
  
    bool isPossible(int mid, vector<int>& arr, int k){
        int cows = 1;
        int prev = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[prev] >=mid){
                cows++;
                prev=i;
            }
        }
        return cows >= k;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int low=1;
        int high = arr[arr.size()-1]-arr[0];
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            //ot int mid = low + (high- low)/2 for intergerr overflow
            // function to check
            if(isPossible(mid,arr,k)==true){
                ans= mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};
