class Solution {
  public:
  
    void segregate0and1(vector<int> &arr) {
        // code here
        int i=0;
        int j=arr.size()-1;
        
        while(i < j){
            if(arr[i]==1 && arr[j]==0){
                // swap
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
            }
            if(arr[i]==0){
                i++;
            }
            if(arr[j]==1){
                j--;
            }

        }
    }
};