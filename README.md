# push_swap
Because Swap_push isn't as natural

<a href="https://github.com/go0h/push_swap/blob/master/push_swap.en.pdf">SUBJECT<a>

Суть проекта состоит в том, чтобы отсортировать массив, с помошью двух стектов используя лишь 11 операций:
1. SA - поменять местами первые два элемента в Стеке А.
2. SB - поменять местами первые два элемента в Стеке В.
3. SS - сделать действие 1 и 2 одновременно.
4. PA - переложить из Стека B в Стек A.
5. PB - переложить из Стека A в Стек B.
6. RA - сдвинуть все элементы Стека А, так чтобы первый элемент стека стал последним.
7. RВ - сдвинуть все элементы Стека В, так чтобы первый элемент стека стал последним.
8. RR - сделать действие 6 и 7 одновременно.
9. RRA - сдвинуть все элементы Стека А, так чтобы последний элемент стека стал первым.
10. RRВ - сдвинуть все элементы Стека В, так чтобы последний элемент стека стал первым.
11. RRR - сделать действие 9 и 10 одновременно.

На вход программе ```push_swap```, в качестве аргумента, подается неотсортированный массив чисел.
Результатом работы пограммы является последовательность команд, приведенных выше, для сортировки массива.

Для проверки правильности команд используется программа ```checker```, которая получает на вход,
точно такой же неотсортированный массив чисел, и читает из стандартного ввода команды.
Если после чтения всех команд Стек А оказался отсортированным, ```checker``` выведет ```ОК```, иначе ```KO```.

По заданию оптимизированным считается алгоритм, если для ```100``` чисел число команд не превышает ```700```, а для ```500``` не превышает ```5000```.

```
Usage:
./push_swap [digit_1 ... digit_n]

./checker [-v [-c]]  [digit_1 ... digit_n]
    -v - to visualize sorting
    -c - for color visualization of sorting
```
