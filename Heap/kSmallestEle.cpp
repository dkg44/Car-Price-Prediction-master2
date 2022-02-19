class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //co000de here
        // heap initialisation
        priority_queue<int> maxh;
        int size= r+1;
        
        for(int i=0; i<size; i++){
            maxh.push(arr[i]);
            
            if(maxh.size()>k){
                maxh.pop();
            }
            
        }
        return maxh.top();
    }
};
