#include "../base.hpp"

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

// 高速なハッシュテーブル
// see: https://atcoder.jp/contests/abc362/submissions/55563043
template<typename Key, typename Val>
using hash_table = gp_hash_table<Key, Val>;

// 宣言
// hash_table<ll, ll> ht;
// 存在チェック
// ht.find(val) != ht.end()
