#pragma once
#include "HashMapImpl.hpp"

// 参考：https://nyaannyaan.github.io/library/hashmap/hashset.hpp
template <typename Key>
struct HashSet : HashMapImpl::HashMapBase<Key, Key> {
    using HashMapImpl::HashMapBase<Key, Key>::HashMapBase;
};
