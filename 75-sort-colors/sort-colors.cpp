class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount=0,oneCount=0,twoCount=0;
for(int i=0;i<nums.size();i++){
if(nums[i]==0){
    zeroCount++;
}
else if(nums[i]==1){
    oneCount++;
}
else if(nums[i]==2){
    twoCount++;
}
}   

int i=0;
cout<<zeroCount;
cout<<oneCount;
cout<<twoCount;


for( i=0;i<zeroCount;i++){
nums[i]=0;
}

for( i=zeroCount;i<oneCount+zeroCount;i++){
nums[i]=1;
}
for( i=oneCount+zeroCount;i<twoCount+oneCount+zeroCount;i++){
nums[i]=2;
}


 }
};