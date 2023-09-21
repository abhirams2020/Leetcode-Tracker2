//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;

    void merge(long long arr[], int l, int mid, int r) {
        long long n1 = mid-l+1; // size of parition 1
        long long n2 = r - (mid+1) + 1; // size of parition 2
        vector<long long> left(n1);
        vector<long long> right(n2);
        for(long long i=l,k=0;i<=mid;i++,k++){
            left[k] = arr[i];
        }
        for(long long i=mid+1,k=0;i<=r;i++,k++){
            right[k] = arr[i];
        }
        long long p1 = 0, p2 = 0, p = l;
        while(p1<n1 && p2<n2){
            if(left[p1]<=right[p2]){
                arr[p] = left[p1];
                p1++;
            }
            // If left ptr element > right ptr element it means there is inversion
            // Since left and right are sorted, left ptr to end of left, there is inversion.
            // so add no of elements to right of left ptr including it for each inversion
            else {
                arr[p] = right[p2];
                p2++;
                count = count + (n1-p1);
            }
            p++;
        }
        while(p1<n1){
            arr[p] = left[p1];
            p1++;
            p++;
        }
        while(p2<n2){
            arr[p] = right[p2];
            p2++;
            p++;
        }
    }
    
    void mergesort(long long arr[], long long  l, long long  r){
        if(l>=r){
            return;
        }
        long long mid = l + (r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergesort(arr,0,N-1);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends