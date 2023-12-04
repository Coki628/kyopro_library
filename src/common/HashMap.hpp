#pragma once
#include "../base.hpp"
#include "HashMapImpl.hpp"

// 参考：https://nyaannyaan.github.io/library/hashmap/hashmap.hpp
// ・めちゃ速い。
// 注意点
// ・eraseしてsize取るみたいな操作してたらなんかローカルは大丈夫だけど
// 　コードテストで挙動が一定でなくなったので、それやりたい時は別変数でsize管理した方がいいかも。
// ・色々試した感じ、そもそもeraseやることが非推奨と考えた方が良さそう。
// ・HashMap<int, mint>みたいので += やる時に、足される側の添字アクセスでextendが走ると、
// 　要素の位置が変わってしまうため、先に評価されて既に返している足す側の参照が壊れるっぽい。
// 　なんかintだと大丈夫っぽいので、mintみたいにオブジェクトだとダメなんかな多分。
// ・DPの2次元目に使ったら、メモリを食うと結構重くなるようだったので、
// 　配列節約テクは使った方が良さげ。
template<typename Key, typename Val>
struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {
    using base = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;
    using HashMapImpl::HashMapBase<Key, pair<Key, Val>>::HashMapBase;
    using Data = pair<Key, Val>;

    Val &operator[](const Key &k) {
        typename base::u32 h = base::inner_hash(k);
        while (true) {
            if (base::flag[h] == false) {
                if (base::extend_rate(base::s + 1)) {
                    base::extend();
                    h = base::hash(k);
                    continue;
                }
                base::data[h].first = k;
                base::data[h].second = Val();
                base::flag[h] = true;
                ++base::s;
                return base::data[h].second;
            }
            if (base::data[h].first == k) {
                if (base::dflag[h] == true) base::data[h].second = Val();
                return base::data[h].second;
            }
            h = (h + 1) & (base::cap - 1);
        }
    }

    typename base::itr emplace(const Key &key, const Val &val) {
        return base::insert(Data(key, val));
    }

    bool count(const Key &k) {
        return this->contain(k);
    }
};
