/* 1 */
// #include <stdio.h>
// int sum(int);
// int main() {
//     int n;
//     scanf("%d", &n);
//     printf("%d", sum(n));
//     return 0;
// }
// int sum(int n) {
//     if (n == 1) {
//         return n;
//     }
//     else {
//         return n + sum(n - 1);
//     }
// }


/* 2 */
// #include <stdio.h>
// void printNum(int);
// int main() {
//     int n;
//     scanf("%d", &n);
//     printNum(n);
//     return 0;
// }
// void printNum(int n) {
//     if (n < 10) {
//         printf("%d\n", n);
//     }
//     else {
//         printNum(n / 10);
//         printf("%d\n", n % 10);
//     }
// }


/* 3 */
// #include <stdio.h>
// void printNum(int);
// int main() {
//     int n;
//     scanf("%d", &n);
//     printNum(n);
//     return 0;
// }
// void printNum(int n) {
//     if (n < 10) {
//         printf("%d\n", n);
//     }
//     else {
//         printf("%d\n", n % 10);
//         printNum(n / 10);
//     }
// }


/* 4 */
// #include <stdio.h>
// int max(int *, int);
// int main() {
//     int n, a[20];
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//     }
//     printf("%d", max(a, n));
//     return 0;
// }
// int max(int *a, int n) {
//     if (n == 0) return a[0];
//     else {
//         return a[n - 1] > max(a, n - 1) ? a[n - 1] : max(a, n - 1);
//     }
// }


/* 5 */
// #include <stdio.h>
// void hanoi(int, char, char, char);
// int main() {
//     int n;
//     scanf("%d", &n);
//     hanoi(n, 'A', 'B', 'C');
//     return 0;
// }
// void hanoi(int n, char from, char aux, char to) {
//     if (n == 1) {
//         printf("%c %c\n", from, to);
//     }
//     else {
//         hanoi(n - 1, from, to, aux);
//         printf("%c %c\n", from, to);
//         hanoi(n - 1, aux, from, to);
//     }
// }


/* 6 */
// #include <stdio.h>
// int gcd(int, int);
// int main() {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     printf("%d", gcd(a, b));
//     return 0;
// }
// int gcd(int a, int b) {
//     int max = a >= b ? a : b;
//     int min = a < b ? a : b;
//     while (min > 0) {
//         int tmp = max % min;
//         max = min;
//         min = tmp;
//     }
//     return max;
// }


/* 7 */
// #include <stdio.h>
// #include <string.h>
// void findChar(char *, char, int, int *);
// int main() {
//     char str[101], ch;
//     scanf("%s %c", str, &ch);
//     int len = strlen(str), count = 0;
//     findChar(str, ch, len, &count);
//     printf("%d", count);
//     return 0;
// }
// void findChar(char *str, char ch, int len, int *pcount) {
//     if (len == 1) {
//         if (str[0] == ch) (*pcount)++;
//     }
//     else {
//         findChar(str, ch, len - 1, pcount);
//         if (str[len - 1] == ch) (*pcount)++;
//     }
// }


/* 7 다른 풀이 */
// #include <stdio.h>
// int findChar(char *, char);
// int main() {
//     char str[101], ch;
//     scanf("%s %c", str, &ch);
//     printf("%d", findChar(str, ch));
//     return 0;
// }
// int findChar(char *str, char ch) {
//     if (*str == '\0') {
//         return 0;
//     }
//     if (*str == ch) {
//         return 1 + findChar(str + 1, ch);
//     }
//     return findChar(str + 1, ch);
// }