> 除书籍作者给出的题解外，其余为个人所解，仅供参考

## 第5章 选择语句

### 练习题

1. |a|b|c|d|
   |-|-|-|-|
   |1|1|1|0|

2. |a|b|c|d|
   |-|-|-|-|
   |1|1|1|1|

3. (a) 1; 3 4 5  
   (b) 0; 7 8 9  
   (c) 1; 8 8 9  
   (d) 1; 2 1 1

4. `(i > j) - (i < j)`

5. 合法，条件恒成立打印输出

6. 合法，条件不成立什么也不做

7. 结果相同皆为17

8. ```c
   if (age >= 13 && age <= 19)
       teenager = true;
   else
       teenager = false;
   ```
9. 等价

10. onetwo

11. ```c
    switch (area_code) {
        case 229: printf("Albany"); break;
        case 404: case 470: case 678: case 770:
            printf("Atlanta"); break;
        case 478: printf("Macon"); break;
        case 706: case 762:
            printf("Columbus"); break;
        case 912: printf("Savannah"); break;
        default: printf("Area code not recognized"); break;
    }
    ```

### 编程题

1. ```c
   int num;
   
   printf("Enter a number: ");
   scanf("%d", &num);
   
   if (num >= 0 && num <= 9)
      printf("The number %d has 1 digits\n", num);
   else if (num >= 10 && num <= 99)
      printf("The number %d has 2 digits\n", num);
   else if (num >= 100 && num <= 999)
      printf("The number %d has 3 digits\n", num);
   else
      printf("The number %d has 4 digits\n", num);
   ```
2. ```c
   int hours, minutes;

   printf("Enter a 24-hour time: ");
   scanf("%d:%d", &hours, &minutes);

   printf("Equivalent 12-hour time: ");
   if (hours == 0)
      printf("12:%.2d AM\n", minutes);
   else if (hours < 12)
      printf("%d:%.2d AM\n", hours, minutes);
   else if (hours == 12)
      printf("%d:%.2d PM\n", hours, minutes);
   else
      printf("%d:%.2d PM\n", hours - 12, minutes);
   ```
3. ```c
   int mount, commission, competitor_commission;
   float price, value;
   
   printf("Enter price and mount: ");
   scanf("%d%d", &price, &mount);

   if (mount < 2000)
      competitor_commission = 33.3f * mount;
   else
      competitor_commission = 33.2f * mount;

   value = price * mount;
   if (value < 2500.f)
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

   if (commission < 39)
      commission = 39.00f;

   printf("Commission: $%.2f\n", commission);
   printf("Commission of competitor: $%.2f\n", competitor_commission);
   ```
4. ```c
   int speed;
   
   printf("Enter wind speed: ");
   scanf("%f", &speed);

   if (speed < 1)
      printf("Calm");
   else if (speed >= 1 && speed <= 3)
      printf("Light air\n");
   else if (speed >= 4 && speed <= 27)
      printf("Breeze\n");
   else if (speed >= 28 && speed <= 47)
      printf("Gale\n");
   else if (speed >= 48 && speed <= 63)
      printf("Storm\n");
   else
      printf("Hurricane\n");
   ```
5. ```c
   float value, taxi;
   printf("Enter your value of income: ");
   scanf("%d", &value);

   if (value <= 750)
      taxi = value * 0.01f;
   else if (value <= 2250)
      taxi = (value - 750) * 0.02f + 7.5f;
   else if (value <= 3750)
      taxi = (value - 2250) * 0.03f + 37.5f;
   else if (value <= 5250)
      taxi = (value - 3750) * 0.04f + 82.5f;
   else if (value <= 7000)
      taxi = (value - 5250) * 0.05f + 142.5f;
   else
      taxi = (value - 7000) * 0.06f + 230.0f;

   printf("Your taxi: %d\n", taxi);
   ```
6. ```c
   int check_digit, d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5,
   first_sum, second_sum, total;

   printf("Enter the first (single) digit: ");
   scanf("%1d", &d);
   printf("Enter first group of five digits: ");
   scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
   printf("Enter second group of five digits: ");
   scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
   printf("Enter the last (single) digit: ");
   scanf("%1d", &check_digit);

   first_sum = d + i2 + i4 + j1 + j3 + j5;
   second_sum = i1 + i3 + i5 + j2 + j4;
   total = 3 * first_sum + second_sum;

   if (check_digit == 9 - ((total - 1) % 10))
      printf("VALID\n");
   else
      printf("NOT VALID\n");
   ```
7. ```c
   int a, b, c, d;
   int min1, min2, max1, max2;

   printf("Enter four integers: ");
   scanf("%d%d%d%d", &a, &b, &c, &d);

   if (a < b) min1 = a, max1 = b;
   else min1 = b, max1 = a;

   if (c < d) min2 = c, max2 = d;
   else min2 = d, max2 = c;

   if (min1 > min2) min1 = min2;
   if (max1 < max2) max1 = max2;

   printf("Largest: %d\n", max1);
   printf("Smallest: %d", min1);
   ```
8. ```c
   int hours, minutes;
   printf("Enter a 24-hours time: ");
   scanf("%d:%d", &hours, &minutes);

   int time = hours * 60 + minutes;
   if (time < 480 || time >= 1140)
      printf("Cloest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
   else if (time < 583)
      printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.");
   else if (time < 679)
      printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m");
   else if (time < 767)
      printf("Closest departure time is 12:47 a.m., arriving at 3:00 p.m");
   else if (time < 840)
      printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.");
   else if (time < 945)
      printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.");
   else if (time < 1140)
      printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.");
   else
      printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.");
   ```
9. ```c
   int month, day, year, early_month = 0, early_day = 0, early_year = 0;
    
   printf("Enter a date (mm/dd/yy): ");
   scanf("%d/%d/%d", &early_month, &early_day, &early_year);
   printf("Enter a date (mm/dd/yy): ");
   scanf("%d/%d/%d", &month, &day, &year);
    
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
   
   printf("%d/%.2d/%.2d is the earliest date\n", early_month, early_day, early_year);
   ```
9. ```c
   int grade;
    
   printf("Enter numerical grade: ");
   scanf("%d", &grade);
    
   if (grade < 0 || grade > 100) {
      printf("Illegal grade\n");
      return 0;
   }

   switch (grade/10) {
      case 10: case 9: printf("A\n"); break;
      case 8: printf("B\n"); break;
      case 7: printf("C\n"); break;
      case 6: printf("D\n"); break;
      case 5: case 4: case 3: case 2: case 1: case 0:
         printf("F\n"); break;
   }
    ```
9. ```c
   int m, n;
    
   printf("Enter a two-digit number: ");
   scanf("%1d%1d", &m, &n);
   printf("Your entered the number ");
   switch (m) {
      case 1:
         switch (n) {
            case 0: printf("ten\n"); break;
            case 1: printf("eleven\n"); break;
            case 2: printf("twelve\n"); break;
            case 3: printf("thirteen\n"); break;
            case 4: printf("fourteen\n"); break;
            case 5: printf("fifteen\n"); break;
            case 6: printf("sixteen\n"); break;
            case 7: printf("seventeen\n"); break;
            case 8: printf("eighteen\n"); break;
            case 9: printf("nineteen\n"); break;
         }
         return 0;
      case 2: printf("twenty"); break;
      case 3: printf("thirty"); break;
      case 4: printf("forty"); break;
      case 5: printf("fifty"); break;
      case 6: printf("sixty"); break;
      case 7: printf("seventy"); break;
      case 8: printf("eighty"); break;
      case 9: printf("ninety"); break;
   }
   switch (n) {
      case 0: break;
      case 1: printf("-one\n"); break;
      case 2: printf("-two\n"); break;
      case 3: printf("-three\n"); break;
      case 4: printf("-four\n"); break;
      case 5: printf("-five\n"); break;
      case 6: printf("-six\n"); break;
      case 7: printf("-seven\n"); break;
      case 8: printf("-eight\n"); break;
      case 9: printf("-nine\n"); break;
   }
   ```
