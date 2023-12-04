#pragma once
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

// 初期化
// tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> tr;

// k番目(0-indexed)の要素を取得
// ll val = *tr.find_by_order(k);

// それ意外はほぼsetと同じ感じで使える。
