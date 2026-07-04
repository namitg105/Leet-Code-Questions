class Solution {
public:
int result=0;
    int minTimeToVisitAllPoints(vector<vector<int>>& points) { 
        for(int i=0;i<points.size();i++){
            // for(int j=0;j<points[i].size();j++){
            if(i!=points.size()-1){
                int dx=abs(points[i][0]-points[i+1][0]);
                int dy=abs(points[i][1]-points[i+1][1]);
                
                 result = result+ max(dx,dy);
            }
            // }
        }
return result;
    }

};