#pragma once
#include "../base.hpp"
#include "common/HashMap.hpp"

// 疎な2次元BIT
template<typename T>
class SparseBIT2D {
    int H;
    int W;
    HashMap<int, HashMap<int, T>> data2d;

public:
    SparseBIT2D(int H, int W) : H(H), W(W) {
    }

    // [0,h],[0,w]
    T sum(int h, int w) {
        T res = 0;
        h++, w++;
        for (int i = h; i > 0; i -= i & -i) {
            if (not data2d.count(i - 1)) continue;
            for (int j = w; j > 0; j -= j & -j) {
                if (not data2d[i - 1].count(j - 1)) continue;
                res += data2d[i - 1][j - 1];
            }
        }
        return res;
    }

    // [h1,h2),[w1,w2)の区間和
    T query(int h1, int w1, int h2, int w2) {
        return sum(h2 - 1, w2 - 1) - sum(h1 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) +
               sum(h1 - 1, w1 - 1);
    }

    T get(int h, int w) {
        return query(h, w, h + 1, w + 1);
    }

    void add(int h, int w, T x) {
        h++, w++;
        for (int i = h; i <= H; i += i & -i) {
            for (int j = w; j <= W; j += j & -j) {
                data2d[i - 1][j - 1] += x;
            }
        }
    }
};
