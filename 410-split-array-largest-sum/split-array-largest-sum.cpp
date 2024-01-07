class Solution {
public:
int countStudents(vector<int> &A,int M)
    {
        int students = 1;
        long long pageStudent = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(pageStudent + A[i] <= M)
            {
                pageStudent += A[i];
            }
            else
            {
                students += 1;
                pageStudent = A[i];
            }
        }
        return students;
    }
    //Function to find minimum number of pages.
    int findPages(vector<int> A,int N, int M) 
    {
        //code here
        if(M > N)   return -1;
        int low = *max_element(A.begin(),A.end());
        int high = accumulate(A.begin(),A.end(),0);
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int students = countStudents(A,mid);
            if(students > M)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};