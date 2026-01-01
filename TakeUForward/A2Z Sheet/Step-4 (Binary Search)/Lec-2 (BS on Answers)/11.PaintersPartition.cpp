// Code360: Painter's Partition Problem
// link: https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid (vector<int> &books, int students, int maxPages){
    int n = books.size();
    int allocatedPages = 0;

    for ( int i = 0; i< n ; i++){
        if ( allocatedPages + books[i] > maxPages){
            students--;
            allocatedPages = books[i];
        } else allocatedPages += books[i];
        
        if ( students == 0 ) return false;
    }
    return true;
}

int findLargestMinDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    
    int low= 0, high= 0;
    for ( int &pages: arr){
        low = max(pages, low);
        high += pages;
    }

    int ans = -1;

    while ( low <= high) { 

        int mid = low + (high-low)/2;

        if ( isValid(arr, k, mid) ){
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    return ans;
}


int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector <int> v(n);
        for ( int i =0; i < n ; i++) {
            cin >> v[i];
        }

        cout << findLargestMinDistance(v, k) << endl;
    }
    return 0;
}