#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
private:
    // encode (shop,movie) into a 64-bit key
    static inline long long key(int shop, int movie) {
        return ( (long long)shop << 32 ) | (long long)movie;
    }

    unordered_map<long long, int> priceMap;                 // key -> price
    unordered_map<int, set<pair<int,int>>> avail;           // movie -> set of (price, shop)
    set<tuple<int,int,int>> rented;                         // set of (price, shop, movie)

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // n not needed explicitly but kept for API compatibility
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            long long k = key(shop, movie);
            priceMap[k] = price;
            avail[movie].insert({price, shop});
        }
    }

    // Returns list of up to 5 shops (sorted by price, then shop) that have an unrented copy of movie.
    vector<int> search(int movie) {
        vector<int> res;
        auto it = avail.find(movie);
        if (it == avail.end()) return res;
        int cnt = 0;
        for (auto itr = it->second.begin(); itr != it->second.end() && cnt < 5; ++itr, ++cnt) {
            res.push_back(itr->second);
        }
        return res;
    }

    // Rent the given movie from the given shop (it's guaranteed unrented there).
    void rent(int shop, int movie) {
        long long k = key(shop, movie);
        int p = priceMap[k];
        auto it = avail.find(movie);
        if (it != avail.end()) {
            it->second.erase({p, shop});
            if (it->second.empty()) avail.erase(it);
        }
        rented.insert({p, shop, movie});
    }

    // Drop off a previously rented copy (guaranteed rented).
    void drop(int shop, int movie) {
        long long k = key(shop, movie);
        int p = priceMap[k];
        rented.erase({p, shop, movie});
        avail[movie].insert({p, shop});
    }

    // Return up to 5 cheapest rented movies as [shop, movie]
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            int p, shop, movie;
            tie(p, shop, movie) = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};
