//Name:Saksham
//RollNo:2010992072
//Set:-
//Q1

#include <bits/stdc++.h>
using namespace std;


//We are going to the length of longest subarray
// we need to find the givensubarray having sum k
int lenOfLongSubarr(int arr[],
                    int n,
                    int k)
{

    // unordered_map 'um' implemented
    // as hash table
    unordered_map<int, int> um;
    int sum = 0, maxLen = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {

        // accumulate sum
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == k)
            maxLen = i + 1;

        // make an entry for 'sum' if it is
        // not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;

        // check if 'sum-k' is present in 'um'
        // or not
        if (um.find(sum - k) != um.end())
        {

            // update maxLength
            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }

    // required maximum length
    return maxLen;
}

// Driver Code
int main()
{
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;
    int res;

    try
    {
        res = lenOfLongSubarr(arr, n, k);
        if (!res)
            throw("No subarray found");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "Length = " << res;
    return 0;
}

