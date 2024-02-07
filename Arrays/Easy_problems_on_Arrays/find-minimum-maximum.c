// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

struct pair {
    long long int max;
    long long int min;
};

struct pair getMinMax(long long int arr[], long long int n) {
    struct pair ans;
    
    ans.max = arr[0];
    ans.min = arr[0];
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > ans.max) {
            ans.max = arr[i];
        }
        
        if (arr[i] < ans.min) {
            ans.min = arr[i];
        }
    }
    
    return ans;
}