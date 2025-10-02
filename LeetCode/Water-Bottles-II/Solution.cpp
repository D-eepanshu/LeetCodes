class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrunk = 0;
        int emptyBottles = 0;

        while (numBottles > 0) {
            // Drink all full bottles
            totalDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            // Try to exchange
            if (emptyBottles >= numExchange) {
                // Do one exchange
                emptyBottles -= numExchange;
                numBottles += 1;  // You get one full bottle
                numExchange += 1; // Increase the exchange requirement
            } else {
                break; // Can't do any more exchanges
            }
        }

        return totalDrunk;
    }
};
