#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
 
        long long a[n], mx = 0;
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
 
        long long low = 1, high = mx + x;
 
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            long long water = 0;
 
            for (int i = 0; i < n; i++)
                if (a[i] < mid)
                    water += mid - a[i];
 
            if (water <= x)
                low = mid;
            else
                high = mid - 1;
        }
 
        cout << low << '\n';
    }
}