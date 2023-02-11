> 除书籍作者给出的题解外，其余为个人所解，仅供参考

## 第6章 循环

### 练习题

1. `1 2 4 8 16 32 64 128 `
2. `9384 938 93 9 `
3. `5 4 3 2`
4. c
5. c
6. `for (int i = 1; i <= 128; i *= 2) printf("%d ", i);`
7. `for (int i = 9384; i > 0; i /= 10) printf("%d ", i);`
8. `10 5 3 2 1...` `// 不断输出1`
9. ```c
   i = 10;
   while (i >= 1) {
      printf("%d ", i++);
      i /= 2;
   }
   ```
10. ```c
    while (…) {
      …
      continue;
      …
    }

    while (…) {
      …
      goto loop_end;
      …
      loop_end: ;   /* null statement */
    }
    ```
11. 20
12. ```c
    for (d =2; d * d < n; d++) {
       if ( n % d == 0)
          break;
    }
    if (d * d <= n)
       printf("%d is divisible by %d\n", n, d);
    else
      printf("%d is prime\n", n);
    ```
13. `for (n = 0; m > 0; m /= 2, n++);`
14. 去掉if语句末尾的分号

### 编程题

1. ```c
   float n, max = 0;
   do {
      printf("Enter a number: ");
      scanf("%f", &n);
      max = n > max ? n : max;
   } while (n > 0);
   printf("\nThe largest number entered was %g\n", max);
   ```
2. ```c
   int m, n, remainder;

   printf("Enter two integers: ");
   scanf("%d%d", &m, &n);

   while (n != 0) {
      remainder = m % n;
      m = n;
      n = remainder;
   }

   printf("Greatest common divisor: %d\n", m);
   ```
3. ```c
   int a, b, m, n, remainder;
   printf("Enter a fraction: ");
   scanf("%d/%d", &a, &b);

   m = a;
   n = b;

   while (n != 0) {
      remainder = m % n;
      m = n;
      n = remainder;
   }

   printf("In lowest terms: %d/%d", a/m, b/m);
   ```
4. ```c
   float commission, value;

   printf("Enter value of trade: ");
   scanf("%f", &value);

   while (value != 0.0f) {
      if (value < 2500.00f)
         commission = 30.00f + .017f * value;
      else if (value < 6250.00f)
         commission = 56.00f + .0066f * value;
      else if (value < 20000.00f)
         commission = 76.00f + .0034f * value;
      else if (value < 50000.00f)
         commission = 100.00f + .0022f * value;
      else if (value < 500000.00f)
         commission = 155.00f + .0011f * value;
      else
         commission = 255.00f + .0009f * value;

      if (commission < 39.00f)
         commission = 39.00f;

      printf("Commission: $%.2f\n\n", commission);
      printf("Enter value of trade: ");
      scanf("%f", &value);
   }
   ```
5. ```c
   int n, remainder, reversal = 0;
   printf("Enter a number: ");
   scanf("%d", &n);

   do {
      remainder = n % 10;
      n /= 10;
      reversal = reversal * 10 + remainder;
   } while (n > 0);

   printf("The reversal is: %d\n", reversal);
   ```
6. ```c
   int n;

   printf("Enter limit on maximum square: ");
   scanf("%d", &n);

   for (int i = 2; i * i <= n; i += 2)
      printf("%d\n", i * i);
   ```
7. ```c
   int n, odd, square;

   printf("This program prints a table of squares.\n");
   printf("Enter number of entries in table: ");
   scanf("%d", &n);

   odd = 3;
   for (int i = 1, square = 1; i <= n; ++i, odd += 2) {
      printf("%10d%10d\n", i, square);
      square += odd;
   }
   ```
8. ```c
   int i, n, start_day;

   printf("Enter number of days in month: ");
   scanf("%d", &n);
   printf("Enter starting day of the week (1=Sun, 7=Sat): ");
   scanf("%d", &start_day);

   for (i = 1; i < start_day; i++)
      printf("   ");

   for (i = 1; i <= n; i++) {
      printf("%3d", i);
      if ((start_day + i - 1) % 7 == 0)
         printf("\n");
   }
   ```
9. ```c
   double loan, rate, payment;
   int count;

   printf("Enter amount of loan: ");
   scanf("%lf", &loan);
   printf("Enter interest rate: ");
   scanf("%lf", &rate);
   printf("Enter monthly payment: ");
   scanf("%lf", &payment);
   printf("Enter number of payments: ");
   scanf("%d", &count);

   double monthly_interest = rate / 100 / 12;

   for (int i = 1; i <= count; i++) {
      loan *= monthly_interest + 1;
      loan -= payment;
      printf("Balance remaining after %d month(s): $%.2f\n", i, loan);
   }
   ```
10. ```c
    int month, day, year, early_month = 0, early_day = 0, early_year = 0;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &early_month, &early_day, &early_year);

    for (;;) {
      printf("Enter a date (mm/dd/yy): ");
      scanf("%d/%d/%d", &month, &day, &year);

      if (month == 0 && day == 0 && year == 0)
        break;

      if (year < early_year) {
        early_month = month;
        early_day = day;
        early_year = year;
      } else if (year == early_year && month < early_month) {
        early_month = month;
        early_day = day;
        early_year = year;
      } else if (year == early_year && month == early_month && day < early_day) {
        early_month = month;
        early_day = day;
        early_year = year;
      }
    }

    printf("%d/%.2d/%.2d is the earliest date\n", early_month, early_day, early_year);
    ```
11. ```c
    double E = 1.0;
    int n, divisor = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
      divisor *= i;
      E += 1.0 / divisor;
    }
    ```
12. ```c
    double ranger, E = 1.0;
    int n, divisor = 1;

    printf("Enter a floating number: ");
    scanf("%lf", &ranger);

    for (int i = 1;; i++) {
      divisor *= i;
      if (1.0 / divisor < ranger)
        break;
      E += 1.0 / divisor;
    }
    ```
