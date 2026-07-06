class Solution {
public:
   int  unsortedCounter=0;

    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights(heights.size());
        for(int i=0;i<heights.size();i++){
            sortedHeights[i]=heights[i];
        }
sort(sortedHeights.begin(), sortedHeights.end());  
        for(int i=0;i<heights.size();i++){
if(heights[i]!=sortedHeights[i]){
    unsortedCounter++;
}


        }

  return unsortedCounter;
  }

};