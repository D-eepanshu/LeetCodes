class FoodRatings {
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first;  // higher rating first
            return a.second < b.second;                        // lexicographically smaller first
        }
    };

    unordered_map<string, string> foodToCuisine;   // food -> cuisine
    unordered_map<string, int> foodToRating;       // food -> rating
    unordered_map<string, set<pair<int,string>, cmp>> cuisineToFoods; // cuisine -> set of (rating, food)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        // remove old entry
        cuisineToFoods[cuisine].erase({oldRating, food});
        // update rating
        foodToRating[food] = newRating;
        // insert new entry
        cuisineToFoods[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
