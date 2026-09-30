#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int daysNeeded = 1;
            int currentWeight = 0;

            for (int i = 0; i < weights.size(); i++) {

                if (currentWeight + weights[i] <= mid) {
                    currentWeight += weights[i];
                }
                else {
                    daysNeeded++;
                    currentWeight = weights[i];
                }
            }

            if (daysNeeded <= days) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};