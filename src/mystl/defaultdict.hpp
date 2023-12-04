#pragma once
#include "../base.hpp"
#include "../common/HashMap.hpp"

// HashMapを継承したdefaultdict
template<typename _Key, typename _Tp>
struct defaultdict : HashMap<_Key, _Tp> {
    const _Tp init;

    defaultdict() : init(_Tp()) {};

    defaultdict(_Tp init) : init(init) {}

    _Tp &operator[](const _Key &k) {
        if (this->count(k)) {
            return HashMap<_Key, _Tp>::operator[](k);
        } else {
            return HashMap<_Key, _Tp>::operator[](k) = init;
        }
    }

    _Tp &operator[](_Key &&k) {
        if (this->count(k)) {
            return HashMap<_Key, _Tp>::operator[](k);
        } else {
            return HashMap<_Key, _Tp>::operator[](k) = init;
        }
    }
};
