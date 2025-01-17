/*
    link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
*/



// ----------------------------------------------------------------------------------------------------------------------- //
bool subArrayExists(int arr[], int n)
{
    // if the element 0 itself is present.
    for (int i = 0;i < n;i++) {
        if (arr[i] == 0) return 1;
    }
    set<int> s;
    s.insert(arr[0]);
    for (int i = 1;i < n;i++) {
        arr[i] += arr[i - 1];

        //   
        if (s.find(arr[i]) != s.end() || arr[i] == 0) return 1;
        s.insert(arr[i]);
    }
    return 0;
}

// More easy - just explanation 

To see why this is true, consider the following: Suppose we have seen the prefix sum sum before at position j in the array, 
where j < i. This means that the sum of the elements from arr[0] to arr[j] is equal to sum. 
But since we have also calculated the prefix sum up to position i and found that it is equal to sum, 
this means that the sum of the elements from arr[j+1] to arr[i] is equal to 0. Therefore, there exists a subarray whose sum is 0.

// ----------------------------------------------------------------------------------------------------------------------- //
// alternate solution
bool subArrayExists(int arr[], int n)
{
    //using map to store the prefix sum which has appeared already.
    unordered_map<int, bool> sumMap;

    int sum = 0;
    //iterating over the array.
    for (int i = 0; i < n; i++)
    {
        //storing prefix sum.
        sum += arr[i];

        //if prefix sum is 0 or if it is already present in map then it is
        //repeated which means there is a subarray whose summation is 0,
        //so we return true.
        if (sum == 0 || sumMap[sum] == true)
            return true;

        //storing true in map for every prefix sum obtained.
        sumMap[sum] = true;
    }
    //returning false if we don't get any subarray with 0 sum.
    return false;
}
