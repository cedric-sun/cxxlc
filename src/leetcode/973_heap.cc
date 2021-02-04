// cesun, 9/16/20 6:18 PM.

#include <vector>
#include <queue>

using std::vector;

static inline int square(int x) {
    return x * x;
}

class Solution {
public:
    using Point = vector<int>;

    vector<vector<int>> kClosest(vector<Point> &points, int K) {
        for (Point &p : points)
            p.push_back(square(p[0]) + square(p[1]));
        auto compFunc = [](const Point &a, const Point &b) { return a[2] > b[2]; };
        std::priority_queue<Point, vector<Point>, decltype(compFunc)> pq{
                std::make_move_iterator(points.begin()),
                std::make_move_iterator(points.end()),
                compFunc
        };
        vector<vector<int>> ans;
        for (int i = 0; i < K; ++i) {
            ans.push_back({pq.top()[0], pq.top()[1]});
            pq.pop();
        }
        return ans;
    }
};

#include <cstdio>

int main() {
    Solution x;
    vector<Solution::Point> data{{1,  3},
                                 {-2, 2}};
    for (const auto &vec : x.kClosest(data, 1)) {
        printf("%d %d\n", vec[0], vec[1]);
    }
}
