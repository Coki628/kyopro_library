#include "../macros.hpp"
#include "../common/chmin.hpp"

// XOR基底(array版：こっちのが速い。メモリは食う。)
template<typename T, size_t W>
struct XorBasis {
    array<T, W> basis = {};
    vector<T> saved; // 線形独立な値を保持(zone2021_f参照)
    int rank = 0;

    XorBasis() {}

    XorBasis(const array<T, W>& A) : basis(A) {}

    // 基底にaを追加、基底が更新されたらtrueを返す：O(W)
    bool add(T a) {
        if (a == 0) return false;
        T tmp = a;
        rep(i, rank) {
            chmin(a, a^basis[i]);
        }
        if (a > 0) {
            basis[rank] = a;
            saved.eb(tmp);
            rank++;
            return true;
        } else {
            return false;
        }
    }

    // 現在の基底でaが作れるか：O(W)
    bool exists(T a) {
        rep(i, rank) {
            chmin(a, a^basis[i]);
        }
        return !(a > 0);
    }

    // 2つの基底をマージ：O(W^2)
    XorBasis<T, W> merge(const XorBasis<T, W>& a) {
        if (rank == W or a.rank == 0) {
            return *this;
        }
        if (a.rank == W or rank == 0) {
            return a;
        }
        rep(i, a.rank) {
            add(a.basis[i]);
        }
        return *this;
    }

    void clear() {
        basis = {};
        rank = 0;
    }
};

// XOR基底(vector版)
// template<typename T>
// struct XorBasis {
//     vector<T> basis;

//     XorBasis() {}

//     XorBasis(const vector<T>& A) : basis(A) {}

//     // 基底にaを追加、基底が更新されたらtrueを返す
//     bool add(T a) {
//         if (a == 0) return false;
//         for (auto b : basis) {
//             chmin(a, a^b);
//         }
//         if (a > 0) {
//             basis.eb(a);
//             return true;
//         } else {
//             return false;
//         }
//     }

//     // 現在の基底でaが作れるか
//     bool exists(T a) {
//         for (auto b : basis) {
//             chmin(a, a^b);
//         }
//         return !(a > 0);
//     }

//     int rank() {
//         return basis.size();
//     }
// };
