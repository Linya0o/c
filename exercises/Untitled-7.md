> 除书籍社区给出的题解外，其余为个人所解，仅供参考

## 第7章 基本类型

### 练习题

1. |a |b  |c   |
   |--|---|----|
   |63|119|2748|
2. (a) 010E2 合法，浮点数  
   (b) 32.1E+5 合法，浮点数  
   (c) 0790 非法  
   (d) 100_000 非法  
   (e) 3.978e-2 合法，浮点数
3. b
4. d
5. 
6. |a   |b    |c  |d   |
   |----|-----|---|----|
   |char|short|int|long|
7. |a  |b  |c  |d  |
   |---|---|---|---|
   |\10|\12|\15|\11|
8. |a   |b   |c   |d   |
   |----|----|----|----|
   |\x08|\x0a|\x0d|\x09|
9. `int`
10. `unsigned int`
11. `double`
12. 变量 i 转换成 float 和 f 相加, 然后结果被转换成 double 存储在 d 中。
13. |a    |b   |c    |d     |e     |f  |
    |-----|----|-----|------|------|---|
    |short|long|float|double|double|int|
14. 不是。如果 f 中存储的值超过 int 类型的最大值则转换失败。
15. ```c
    typedef char Int8;
    typedef short Int16;
    typedef int Int32;
    ```

## 编程题

1. ```c
   printf("Size of short: %zu bytes\n", sizeof(short));
   printf("Size of int: %zu bytes\n", sizeof(int));
   printf("Size of long: %zu bytes\n", sizeof(long));
   ```
1. ```c
   int i, n;
   char ch;

   printf("This program prints a table of squares.\n");
   printf("Enter number of entries in table: ");
   scanf("%d", &n);
   ch = getchar();
     /* dispose of new-line character following number of entries */
     /* could simply be getchar(); */

   for (i = 1; i <= n; i++) {
      printf("%10d%10d\n", i, i * i);
      if (i % 24 == 0) {
         printf("Press Enter to continue...");
         ch = getchar();   /* or simply getchar(); */
      }
   }
   ```
1. ```c
   double n, sum = 0;
   printf("This program sums a series of float number.\n");
   printf("Enter integers (0 to terminate): ");

   do {
       scanf("%lf", &n);
       sum += n;
   } while (n != 0);
   printf("The sum is: %f\n", sum);
   ```
1. ```c
   char ch;
   printf("Enter phone number: ");
   while ((ch = getchar()) != '\n') {
      if ('A' <= ch && ch <= 'Z')
         switch(ch) {
            case 'A': case 'B': case 'C':
               putchar('2');
               break;
            case 'D': case 'E': case 'F':
               putchar('3');
               break;
            case 'G': case 'H': case 'I':
               putchar('4');
               break;
            case 'J': case 'K': case 'L':
               putchar('5');
               break;
            case 'M': case 'N': case 'O':
               putchar('6');
               break;
            case 'P': case 'R': case 'S':
               putchar('7');
               break;
            case 'T': case 'U': case 'V':
               putchar('8');
               break;
            case 'W': case 'X': case 'Y':
               putchar('9');
               break;
            }
      else
         putchar(ch);
   }   
   ```
1. ```c
   #include <ctype.h>

   int sum = 0;
   char ch;

   printf("Enter a word: ");
   while ((ch = getchar()) != '\n')
      switch (toupper(ch)) {
         case 'D': case 'G':
            sum += 2; break;
         case 'B': case 'C': case 'M': case 'P':
            sum += 3; break;
         case 'F': case 'H': case 'V': case 'W': case 'Y':
            sum += 4; break;
         case 'K':
            sum += 5; break;
         case 'J': case 'X':
            sum += 8; break;
         case 'Q': case 'Z':
            sum += 10; break;
         default:
            sum++; break;
      }

   printf("Scrabble value: %d\n", sum);
   ```
1. ```c
   printf("Size of int: %zu\n", sizeof(int));
   printf("Size of short: %zu\n", sizeof(short));
   printf("Size of long: %zu\n", sizeof(long));
   printf("Size of float: %zu\n", sizeof(float));
   printf("Size of double: %zu\n", sizeof(double));
   printf("Size of long double: %zu\n", sizeof(long double));
   ```
1. ```c
   char op;
   int num1, denom1, num2, denom2, result_num, result_denom;

   printf("Enter two fractions separated  by operator: ");
   scanf("%d/%d", &num1, &denom1);
   op = getchar();
   scanf("%d/%d", &num2, &denom2);

   switch (op) {
      case '+':
         result_num = num1 * denom2 + num2 * denom1;
         result_denom = denom1 * denom2;
         break;
      case '-':
         result_num = num1 * denom2 - num2 * denom1;
         result_denom = denom1 * denom2;
         break;
      case '*':
         result_num = num1 * num2;
         result_denom = denom1 * denom2;
         break;
      case '/':
         result_num = num1 * denom2;
         result_denom = denom1 * num2;
         break;
      }
   printf("The result is: %d/%d\n", result_num, result_denom);
   ```
1. ```c
   #include <ctype.h>
   int hours, minutes;
   char time_suffix;
   printf("Enter a 12-hours time: ");
   scanf("%d:%d ", &hours, &minutes);
   time_suffix = getchar();

   int base = tolower(time_suffix) == 'a' ? 0 : 720;
   int time = base + hours * 60 + minutes;
   if (time < 480 || time >= 1140)
      printf("Cloest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
   else if (time < 583)
      printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
   else if (time < 679)
      printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
   else if (time < 767)
      printf("Closest departure time is 12:47 a.m., arriving at 3:00 p.m.\n");
   else if (time < 840)
      printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
   else if (time < 945)
      printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
   else if (time < 1140)
      printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
   else
      printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
   ```
1. ```c
   int hours, minutes;
   printf("Enter a 12-hour time: ");
   scanf("%d:%d ", &hours, &minutes);

   char time_suffix = getchar();
   int base = tolower(time_suffix) == 'a' ? 0 : 12;
   printf("Equivalent 24-hour time: %d:%d\n", hours + base, minutes);
   ```
2. ```c
   printf("Enter a sentence: ");
   char ch;
   int count = 0;
   while ((ch = getchar()) != '\n') {
      switch (tolower(ch)) {
         case 'a': case 'e': case 'i': case 'o': case 'u':
            count++;
            break;
         }
   }
   printf("You sentence contains %d vowels\n", count);
   ```
1. ```c
   printf("Enter a first and last name: ");
   char first_letter;
   scanf(" %c", &first_letter);
   while (getchar() != ' ')
      ;
   char ch;
   while ((ch = getchar()) != '\n')
      if (ch != ' ')
         putchar(ch);
   printf(", %c.\n", first_letter);
   ```
1. ```c
   double num, result;
   printf("Enter an expression: ");

   scanf("%lf", &result);
   char op = getchar();
   do {
      scanf("%lf", &num);
      switch (op) {
         case '+': result += num; break;
         case '-': result -= num; break;
         case '*': result *= num; break;
         case '/': result /= num; break;
      }
   } while ((op = getchar()) != '\n');
   printf("Value of expression: %.1f\n", result);
   ```
1. ```c
   printf("Enter a sentence: ");
   char ch;
   int char_count = 0, word_count = 0;
   while ((ch = getchar()) != '\n') {
      ch == ' ' ? word_count++ : char_count++;
   }
   float average = (float) char_count / ++word_count;
   printf("Average word leagth: %.1f\n", average);
   ```
1. ```c
   double x, y, mean = 1.0;
   printf("Enter a positive number: ");
   scanf("%lf", &x);

   do {
      y = mean;
      mean = (y + x / y) / 2;
   } while (fabs(y - mean) >= 0.00001 * y);

   printf("Square root: %.5f\n", mean);
   ```
1. ```c
   int n, fac = 1;
   printf("Enter a positive integer: ");
   scanf("%d", &n);

   for (int i = 1; i <= n; i++) {
      fac *= i;
   }

   printf("Factorial of %d: %d\n", fac);
   ```
