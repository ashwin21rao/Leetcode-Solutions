class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {        
        int len = flowerbed.size();
        
        // check first position
        if (flowerbed[0] == 0 && (len == 1 || flowerbed[1] == 0)) {
            flowerbed[0] = 1;
            n--;
        }
        
        if (n <= 0)
            return true;
        
        // check intermediate positions
        for (int i=1; i<len-1; i++) {
            if (flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
                
                // if we found enough positions, break
                if (n == 0)
                    return true;
            }
        }
        
        // check last position
        if (flowerbed[len-1] == 0 && flowerbed[len-2] == 0) {
            flowerbed[len-1] = 0;
            n--;
        }
        
        return n == 0;
    }
};

/*
- we iterate over the flowerbed and greedily add flowers in any 
  empty position which does not have adjacent flowers.
- as soon as we are able to plant enough flowers, we return true.

time complexity: O(n)
space complexity: O(1)

https://leetcode.com/problems/can-place-flowers/
*/