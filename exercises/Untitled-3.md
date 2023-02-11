> 除书籍作者给出的题解外，其余为个人所解，仅供参考
> 
> ***Tips:*** "•" 表示一个空格

## 第3章 格式化输入输出

### 练习题

1. |a          |b           |c      |d     |
   |-----------|------------|-------|------|
   |••••86,1040|3.02530e+001|83.1620|1e-006|

2. (a) `printf("%-8.1e", x);`  
   (b) `printf("%10.6e", x);`  
   (c) `printf("%-8.3f", x);`  
   (d) `printf("%6.0f", x);`

3. (a) 等价  
   (b) 不等价，后者可在输入每个整数后匹配任意空白字符  
   (c) 不等价，后者可在输入每个浮点数后匹配任意空白字符  
   (d) 等价

4. i=10，x=0.3，j=5

5. x=12.3，i=45，y=0.6

6. `scanf("%d / %d", &num, &denom);`

### 编程题

1. ```c
   int month, day, year;
   printf("Enter a date (mm/dd/yyyy): ");
   scanf("%d/%d/%d", &month, &day, &year);
   printf("You entered the date %.4d%.2d%.2d\n", year, month, day);
   ```

2. ```c
   int mount, day, month, year;
   float price;

   printf("Enter item number: ");
   scanf("%d", &mount);
   printf("Enter unit price: ");
   scanf("%f", &price);
   printf("Enter purchase date (mm/dd/yyyy): ");
   scanf("%d/%d/%d", &month, &day, &year);

   printf("Item\tUnit\tPurchase\n\tPrice\tDate\n");
   printf("%d\t$ %.2f\t%.2d/%.2d/%.4d\n", mount, price, month, day, year);
   ```

3. ```c
   int prefix, identifier, code, number, digit;

   printf("Enter ISBN: ");
   scanf("%3d-%1d-%3d-%5d-%1d", &prefix, &identifier, &code, &number, &digit);

   printf("GS1 prefix: %d\n", prefix);
   printf("Grounp identifier: %d\n", identifier);
   printf("Publisher code: %d\n", code);
   printf("Item number: %d\n", number);
   printf("Check digit: %d\n", digit);
   ```
4. ```c
   int area, first, second;

   printf("Enter phone number [(xxx) xxx-xxxx]: ");
   scanf("(%3d) %3d-%4d", &area, &first, &second);

   printf("Your entered: %.3d.%.3d.%.4d\n", area, first, second);
   ```

5. ```c
   int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
   printf("Enter the numbers from 1 to 16 in any order:\n");
   scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
     &a, &b, &c, &d, &e, &f, &g, &h,
     &i, &j, &k, &l, &m, &n, &o, &p);

   printf("%2d  %2d  %2d  %2d\n%2d  %2d  %2d  %2d\n%2d  %2d  %2d  %2d\n%2d  %2d  %2d  %2d\n\n",
            a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p);

   printf("Row sums: %d  %d  %d  %d\nColumn sums: %d  %d  %d  %d\nDiagonal sums: %d  %d\n",
     a + b + c + d, e + f + g + h,
     i + j + k + l, m + n + o + p,
     a + e + i + m, b + f + j + n,
     c + g + k + o, d + h + l + p,
     a + f + k + p, d + g + j + m);
   ```

6. ```c
   int num1, denom1, num2, denom2, result_num, result_denom;

   printf("Enter two fractions separated by a plus sign: ");
   scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

   result_num = num1 * denom2 + num2 * denom1;
   result_denom = denom1 * denom2;
   printf("The sum is: %d/%d\n", result_num, result_denom);
   ```
