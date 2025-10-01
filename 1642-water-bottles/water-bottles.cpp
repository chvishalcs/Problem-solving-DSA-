class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk = numBottles;
        while(numBottles >= numExchange){
            int newBottles = numBottles / numExchange;
            drunk += newBottles;
            numBottles = newBottles + (numBottles % numExchange);
        }
        return drunk;
    }
};