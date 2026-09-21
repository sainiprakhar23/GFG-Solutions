class Solution {
  public:
  
    void swap(int &a , int &b){
        int temp=a;
        a=b;
        b=temp;
        
    }
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int left=0;
        int right = n-1;
        
        while(left < right){
            while(left<right && arr[left]==0){
                left++;
            }
            while(left<right && arr[right]==1){
                right--;
            }
            
            if(left < right  &&  arr[left]==1 && arr[right]==0){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
            
            // if(left<right){
            //     swap(arr[left],arr[right]);
            //     left++;
            //     right--;
            // }

        }
    }
};