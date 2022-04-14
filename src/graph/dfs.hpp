#include "../macros.hpp"

// 木DP用定型部分
auto dfs = [&](auto&& f, ll u, ll prv) -> void {
    for (auto v : nodes[u]) {
        if (v == prv) continue;
        f(f, v, u);
    }
};
