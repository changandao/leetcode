# Notes
# LEETCODES TAGS
## array
#### 832	Flipping an Image  
#### 905	Sort Array By Parity  
#### 561	Array Partition I  
#### 896	Monotonic Array  
### Matrix problems
#### 867	Transpose Matrix   
***push_back is faster than = in vector!***  
#### 566	Reshape the Matrix  
#### 766 Toeplitz Matrix  
#### 283	Move Zeroes 
### Interview problem
#### 238 Product of Array Except Self  
***设置头尾两个指针***  
#### 169 Majority Element  
```c++
int majorityElement(vector<int>& nums) {
    int c=1;
    int n=nums[0];
    int i;
    for(i=1;i<nums.size();i++)
    {
        if(nums[i]==n)
            c++;
        else
            c--;
        if(c==0)
        {
            c=1;
            n=nums[i];
        }
    }
    return n;
}
```
***Majority Voting Algorithm***
[Moore voting](https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html)
## linkedlist
## tree
## string
## math


# Fast ai
#### Make functions if you use something often. Jeremy made function called stats(x) which returned the mean and the standard deviation of the input.
### ***Talking and reading is cheap, show me the code.***
#### One thing I noticed right away was that Jeremy didn’t just read things from somewhere but he tested those by himself.
