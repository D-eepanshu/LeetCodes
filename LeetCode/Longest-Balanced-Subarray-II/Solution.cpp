1class Solution {
2public:
3
4    vector<int> segMin, segMax, lazy;
5    int n;
6
7    void propagate(int i, int l, int r) {
8        if (lazy[i] != 0) {
9            segMin[i] += lazy[i];
10            segMax[i] += lazy[i];
11
12            if (l != r) {
13                lazy[2*i+1] += lazy[i];
14                lazy[2*i+2] += lazy[i];
15            }
16            lazy[i] = 0;
17        }
18    }
19
20    // Range add val to [start, end]
21    void updateRange(int start, int end, int i, int l, int r, int val) {
22        propagate(i, l, r); //make sure to propagate before hand
23
24        if (l > end || r < start) return;
25
26        //[start...end[ is fully inside range of current node [l..r]
27        if (l >= start && r <= end) {
28            lazy[i] += val;
29            propagate(i, l, r);
30            return;
31        }
32
33        int mid = (l + r) / 2;
34        updateRange(start, end, 2*i+1, l, mid, val);
35        updateRange(start, end, 2*i+2, mid+1, r, val);
36
37        segMin[i] = min(segMin[2*i+1], segMin[2*i+2]);
38        segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
39    }
40
41    int findLeftMostZero(int i, int l, int r) {
42        propagate(i, l, r);
43
44        if(segMin[i] > 0 || segMax[i] < 0) {
45            return -1;
46        }
47
48        if(l == r) {
49            return l;
50        }
51
52        int mid = l + (r-l)/2;
53        int leftResult = findLeftMostZero(2*i+1, l, mid);
54        if(leftResult != -1)
55            return leftResult;
56        
57        return findLeftMostZero(2*i+2, mid+1, r);
58    }
59
60    int longestBalanced(vector<int>& nums) {
61        n = nums.size();
62        segMin.assign(4*n, 0);
63        segMax.assign(4*n, 0);
64        lazy.assign(4*n, 0);
65
66        //treating even = +1 and odd = -1
67        vector<int> cumSum(n, 0);
68
69        int maxL = 0;
70
71        unordered_map<int, int> mp;
72
73        for(int r = 0; r < n; r++) {
74            int val = (nums[r] % 2 == 0) ? 1 : -1;
75
76            int prev = -1;
77            if(mp.count(nums[r])) {
78                prev = mp[nums[r]];
79            }
80
81            if(prev != -1) { //we have seen this element in past
82                //[0..prev] we are adding (-val) in the range
83                updateRange(0, prev, 0, 0, n-1, -val);
84            }
85
86            //[0...r] we are adding val in the range
87            updateRange(0, r, 0, 0, n-1, val);
88
89            //We are finding left most 0 in the range [0...r]
90            int l = findLeftMostZero(0, 0, n-1);
91            if(l != -1)
92                maxL = max(maxL, r-l+1);
93
94            mp[nums[r]] = r;
95        }
96
97        return maxL;
98    }
99};