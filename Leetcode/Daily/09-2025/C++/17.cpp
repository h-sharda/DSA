// Problem: 2353. Design a Food Rating System (Medium)
// Link: https://leetcode.com/problems/design-a-food-rating-system

class FoodRatings {
public:
    unordered_map<string, int> idxs;
    unordered_map<string, map<int, set<string>>> umap;

    vector<string> cuisines;
    vector<int> ratings;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        this->cuisines = cuisines;
        this->ratings = ratings;

        int n = foods.size();

        for (int i = 0; i < n; i++) {
            idxs[foods[i]] = i; // foods are distinct, so no overlap
            umap[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        int idx = idxs[food];
        
        string cuisine = cuisines[idx];
        
        int rating = ratings[idx];
        ratings[idx] = newRating;

        umap[cuisine][rating].erase(food);
        if (umap[cuisine][rating].empty()) umap[cuisine].erase(rating);
        
        umap[cuisine][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        return *umap[cuisine].rbegin()->second.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */