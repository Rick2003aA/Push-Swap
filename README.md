# ***This project has been created as part of the 42 curriculum by <rtsubuku>.***

## **Description（説明）**

このプロジェクト **push_swap** は、与えられた整数列を、限られたスタック操作のみを用いて並び替えるプログラムを作成することを目的としています。

スタック A と B を操作しながら、最小限の手数で昇順ソートを達成するアルゴリズムを実装します。

---

## **Instructions**

### **コンパイル**

```
make
```

### **実行**

```
./push_swap <numbers>
```

例：

```
./push_swap "3 2 1"
./push_swap 4 67 3 87 23
```

### **エラー出力**

次のような場合、標準エラーに **Error** と改行を出力して終了します：

- 整数でない入力
- int の範囲外の数値
- 重複値の存在
- 無効な split 結果（空文字列など）

---

## **Resources（リソース）**

### **参考資料**

- C言語標準ライブラリ（malloc, free, atoi など）
- スタックとリンクリストに関する基本資料
- ソートアルゴリズム（特に Radix Sort）に関する技術ドキュメント

### **AI の使用について**

AI（ChatGPT）は以下の用途で使用しました：

- エラー処理や split の境界条件の確認
- アルゴリズム理解のヒント（radix sort）
- README の構成案作成
- テストケース生成と不正入力の検証
