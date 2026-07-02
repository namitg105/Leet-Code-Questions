class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int result=0;
       for(int i=0;i<nums.size();i=i+2){
                   result=min(nums[i],nums[i+1])+result;
       }
     
return result;
    }
};
// MY EXPLANATION TO MYSELF

// we sort the array because we need the sum to be maximized and by sorting we can ensure that the larger elements can be paired with each other and thus when we choose the min(secondLargeElement,largeElement) , it contributes maximum to the final answer
//------------------------------------------------------------------------------------------------------------------------------


/*

DISCUSSION 

We choose two numbers to make a pair.
Then we take min(a,b) = val
This sum of val's has to be maximum.
So, in all the pairs we make , if we take a bigger number and a very small number and take min of these two numbers then we are just wasting away the bigger number as it could be used with some other number for pairing so that it will contribute to the final sum.

So, when we do sorting , we make the adjacent numbers numerically close to each others. So, we can take pairwise elements like 1st and 2nd elements, 3rd and 4th element.. etc so reduce the difference between two numbers in each pair.

example:

input = [1, 1000, 3, 999]

Then if we take (1,1000) and (3,999) as pairs :

min1 = min(1,1000) = 1;
min2 = min(3,999) = 3;

Final sum = min1 + min2 = 4;

But if we sorted the array, we can choose adjacent numbers in the array as the pairs.

then: input = [1,3,999,1000]
min1 = min(1,3)
min2 = min(999,1000)

final sum = min1 + min2 = 1 + 999 = 1000;

We can clearly observe how we get the difference and I hope you understood why sorting of array is needed here.*/