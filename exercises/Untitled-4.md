> 除书籍社区给出的题解外，其余为个人所解，仅供参考

## 第4章 表达式

### 练习题

1. |a  |b|c|d|
   |---|-|-|-|
   |1 2|0|1|0|

2. 自c99以后，一样

3. 空

4. |a|b |c |d|
   |-|--|--|-|
   |1|-1|-1|1|

5. 空

6. |a|b |c|d |
   |-|--|-|--|
   |3|-3|3|-3|

7. 不可行
8. 正确

9. |a   |b    |c      |d    |
   |----|-----|-------|-----|
   |63 8|3 2 1|2 -1 -3|0 0 0|

10. |a    |b  |c  |d  |
    |-----|---|---|---|
    |12 12|3 4|2 8|6 9|

11. |a  |b     |c    |d      |
    |---|------|-----|-------|
    |0 2|4 11 6|0 8 7|3 4 5 4|

12. |a   |b   |c   |d   |
    |----|----|----|----|
    |6 16|6 -7|6 23|6 15|

13. ++i
 
14. (a) `((a * b) - (c * d)) + e`  
    (b) `((a / b) % c) / d`  
    (c) `(((- a) - b) + c) - (+d)`  
    (d) `((a * (-b)) / c) - d`
 
15. (a) i=3, j=2  
    (b) i=0, j=2  
    (c) i=1, j=2  
    (d) i=1, j=3

### 编程题

1. ```c
   int n;
   printf("Enter a two-digit number: ");
   scanf("%d", &n);

   printf("The reversal is: %d%d\n", n % 10, n / 10);
   ```
2. ```c
   int n;
   printf("Enter a three-digit number: ");
   scanf("%d", &n);

   printf("The reversal is: %d%d%d\n", n % 10, (n / 10) % 10, n / 100);
   ```
3. ```c
   int i, j, k;
   printf("Enter a three-digit number: ");
   scanf("%d%d%d", &i, &j, &k);

   printf("The reversal is: %d%d%d\n", i, j, k);
   ```
4. ```c
   int n;
   printf("Enter a number between 0 and 32767: ");
   scanf("%d", &n);

   printf("The reversal is: %d%d%d%d%d\n", n/4096%8, n/512%8, n/64%8, n/8%8, n%8);
   ```
5. ```c
   unsigned long long upc;
   int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
       first_sum, second_sum, total;
   printf("Enter the first 11 digits of a UPC: ");
   scanf("%llu", &upc);

   d = upc / 10000000000;
   i1 = upc / 1000000000 % 10;
   i2 = upc / 100000000 % 10;
   i3 = upc / 10000000 % 10;
   i4 = upc / 1000000 % 10;
   i5 = upc / 100000 % 10;

   j1 = upc / 10000 % 10;
   j2 = upc / 1000 % 10;
   j3 = upc / 100 % 10;
   j4 = upc / 10 % 10;
   j5 = upc % 10;

   first_sum = d + i2 + i4 + j1 + j3 + j5;
   second_sum = i1 + i3 + i5 + j2 + j4;
   total = 3 * first_sum + second_sum;

   printf("Check digit: %d\n", 9 - ((total - 1) % 10));
   ```
6. ```c
   // 注意数据类型范围
   unsigned long long int ean;
   int c1, c2, c3, d, i1, i2, i3, j1, j2, j3, j4, j5,
        first_sum, second_sum, total;
   printf("Enter the first 12 digits of a EAN: ");
   scanf("%llu", &ean);

   c1 = ean / 100000000000;
   c2 = ean / 10000000000 % 10;
   c3 = ean / 1000000000 % 10;
   d  = ean / 100000000 % 10;
   i1 = ean / 10000000 % 10;
   i2 = ean / 1000000 % 10;
   i3 = ean / 100000 % 10;
   j1 = ean / 10000 % 10;
   j2 = ean / 1000 % 10;
   j3 = ean / 100 % 10;
   j4 = ean / 10 % 10;
   j5 = ean % 10;

   first_sum = c2 + d + i2 + j1 + j3 + j5;
   second_sum = c1 + c3 + i1 + i3 + j2 + j4;
   total = 3 * first_sum + second_sum;

   printf("Check digit: %d\n", 9 - ((total - 1) % 10));
   ```
