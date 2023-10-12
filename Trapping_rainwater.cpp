class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;

    int *leftmax = new int[n]; 
    
    leftmax[0] = height[0];

    for(int i=1;i<n;i++){
        leftmax[i] = max(height[i],leftmax[i-1]);    
    }
    int *rightmax = new int[n];
    rightmax[n-1] = height[n-1];
    for(int i=n-2;i>=0;i--){
      rightmax[i] = max(height[i],rightmax[i+1]);
    }

    int *waterlevel = new int[n];
    for(int i=0;i<n;i++){
      waterlevel[i]  = min(leftmax[i],rightmax[i]);
    }

    int *trappedwater = new int[n];
    int sum = 0 ;
    for(int i=0;i<n;i++){
      trappedwater[i] = waterlevel[i] - height[i];
       sum = sum + trappedwater[i];
    }
    return sum;
  


        
    }
};
