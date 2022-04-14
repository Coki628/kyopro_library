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
