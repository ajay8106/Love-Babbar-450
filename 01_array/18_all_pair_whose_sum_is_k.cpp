/*
    link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

    https://www.geeksforgeeks.org/count-pairs-with-given-sum/
*/


// ----------------------------------------------------------------------------------------------------------------------- //
// using hashing (aka unordered_map)
int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;

    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int twice_count = 0;

    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++) {
        twice_count += m[sum - arr[i]];

        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (sum - arr[i] == arr[i])
            twice_count--;
    }

    // return the half of twice_count
    return twice_count / 2;
}



// ----------------------------------------------------------------------------------------------------------------------- //
// naive solution (TLE)
// TC: O(n^2)
int getPairsCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize result

    // Consider all possible pairs and check their sums
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;

    return count;
}

// More easy

int getPairsCount(int arr[], int n, int k) {
        sort(arr,arr+n);
        int i=0;
        int j=n-1;
        int c=0;
        while(i<j){
            if(arr[i]+arr[j]==k){
                c++;
                int m=i+1;
                while(m<j && (arr[m]+arr[j]) == k){
                    c++;
                    m++;
                }
                j--;
            }
            else if(arr[i]+arr[j] < k){
                i++;
            }
            else if(arr[i]+arr[j] > k){
                j--;
            }
        }
        return c;
    }






