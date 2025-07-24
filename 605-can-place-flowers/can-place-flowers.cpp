class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int len = flowerbed.size();

        for(int i = 0; i < len; ++i){
            if(flowerbed[i] == 0){
                bool emptyLeft = (i == 0 || flowerbed[i - 1] == 0);
                bool emptyRight = (i == len - 1 || flowerbed[i + 1] == 0);

                if(emptyLeft && emptyRight){
                    flowerbed[i] = 1;
                    count++;
                    if(count >= n)
                    return true;
                }
            }
        }
        return count >= n;
    }
};