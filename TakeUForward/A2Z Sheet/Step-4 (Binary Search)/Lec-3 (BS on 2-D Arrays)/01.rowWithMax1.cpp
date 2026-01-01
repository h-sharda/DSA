// GFG: Row with max 1s
// link: https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size(), m = arr[0].size();
        int ones = m-1, ans = -1;
        
        for (int i =0; i < n; i++) {
            if (arr[i][m-1] == 1) {
                ans = i;
                break;
            }
        }
        
        if (ans == -1 ) return 0;
        
        for (int i = ans; i < n; i++) {
            if (arr[i][ones] == 0) continue;
            else ans = i;
            
            while (ones >= 0) {
                if (arr[i][ones] == 1) ones--;
                else break;
            }
            
            if ( ones < 0) break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after the integer input
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        cout << obj.rowWithMax1s(mat);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends