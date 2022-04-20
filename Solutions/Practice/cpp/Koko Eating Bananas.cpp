class Solution {
public:
    // returns true if all bananas can be finished by eating at given speed
    bool canFinishBananas(vector<int> &piles, int h, int k) {
        int hours = 0;
        
        for (int &pile : piles) {
            // time taken to eat pile
            int time = (pile % k == 0) ? pile / k : pile / k + 1;
            
            hours += time;
            if (hours > h)
                return false;
        }
        
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        // impossible to eat all bananas
        if (h < piles.size())
            return -1;
        
        // lower and upper bound of eating speed
        int lb = 0, ub = 1e9;
        for (int &pile : piles) {
            ub = max(ub, pile);
            lb += pile / h;
        }
        lb = max(lb, 1);
        
        // binary search for required speed between lb and ub
        int k = -1;
        while (lb <= ub) {
            int mid = lb + (ub - lb) / 2;
            
            // if speed is possible, search for smaller speed
            if (canFinishBananas(piles, h, mid)) {
                k = mid;
                ub = mid - 1;
            }
            else
                lb = mid + 1;
        }
        
        // minimum eating speed
        return k;
    }
};

/*
we need to find the minimum eating speed to finish all bananas.

we can find bounds on the eating speed:
    - upper bound: maximum element in the array
    - lower bound: (sum of all bananas / hours)

a more loose bound on the eating speed would be:
    - upper bound = 1e9 (maximum allowed element)
    - lower bound = 1 (since speed > 0)

we binary search for the minimum speed between lb and ub.
    - for the current speed (mid), we check if all bananas can be eaten.
    - if so, we try searching for a smaller speed.
    - else, we need to increase the speed.

m = maximum element in the array
time complexity: O(mlogm)
space complexity: O(1)

https://leetcode.com/problems/koko-eating-bananas/
*/