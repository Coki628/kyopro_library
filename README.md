# kyopro_library

[![Actions Status](https://github.com/Coki628/kyopro_library/workflows/verify/badge.svg)](https://github.com/Coki628/kyopro_library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://Coki628.github.io/kyopro_library/)

- 動作環境はC++17を想定。
- 基本的にローカルで使う時は別途用意した提出用リポジトリからoj-bundleやpythonやvscodeの機能等で呼び出すようにしてる。
- テストは気が向いたら少しずつ増やす予定。(あんまりやる気ない)
- 作り込んでない物も多いですが、不具合等見かけたらご一報いただけると嬉しいです。

## ローカルテスト実行方法

- oj-verifyが動くpython環境は別途作ってある前提。

```bash
# 全テスト実行
oj-verify run
# 個別実行
oj-verify run test/xxx/xxx.test.cpp
```

## 自分用メモ

- cloneしてくる時はsubmoduleにしているACLを含めたいので、  
`git clone --recursive https://github.com/Coki628/kyopro_library.git`  
のようにオプション付きでやる。

## プリコンパイル

ちょっと速くなってる、かもしれない。
```bash
cd src
sudo g++ template.hpp -std=c++17
```

## ACLの更新

```bash
git submodule update --remote
```

上記コマンドでACLは最新版に更新される。  
更新の記録が変更差分に表示されるので、それをaddしてcommitする。  
差分に「...-dirty」のように記載されている場合は、ACL内に更新が発生しているはずなので、状態を戻してからcommitする。
