// GFG: search query auto complete (Hard)
// link: https://www.geeksforgeeks.org/problems/search-query-auto-complete/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


class AutoCompleteSystem {
  public:

    string curr;
    unordered_map<string, int> history;
    
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        history.clear(); curr.clear();
        
        for (int i = 0; i < times.size(); i++) {
            history[sentences[i]] = times[i];
        }
    }

    vector<string> input(char c) {
        
        if ( c == '#') {
            history[curr]++;
            curr.clear();
            return {};
        }
        
        curr.push_back(c);
        int len = curr.size();
        
        vector<pair<string, int>> v;
        for (const auto &it: history) {
            if (it.first.substr(0, len) == curr) {
                v.push_back({it.first, it.second});
            }
        }
        sort (v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b){
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        
        vector<string> ans;
        for (int i = 0; i < v.size(); i++) {
            ans.push_back(v[i].first);
            if ( ans.size() == 3) break;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> sentences(n);
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {

            getline(cin, sentences[i]);
            cin >> times[i];
            cin.ignore();
        }
        AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
        int q;
        cin >> q;
        cin.ignore();

        for (int i = 0; i < q; ++i) {
            string query;
            getline(cin, query);
            string qq = "";
            for (auto &x : query) {
                qq += x;
                vector<string> suggestions = obj->input(x);
                if (x == '#')
                    continue;
                cout << "Typed : \"" << qq << "\" , Suggestions: \n";
                for (auto &y : suggestions) {
                    cout << y << "\n";
                }
            }
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends