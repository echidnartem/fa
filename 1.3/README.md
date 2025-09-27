## 💻 Задание
Через аргументы командной строки программе подается флаг, который определяет действие, и набор чисел. Флаг начинается с символа ‘-’ или ‘/’. Необходимо проверять соответствие количества параметров введённому флагу. Программа распознает следующие флаги: \
-q первый параметр (вещественное число) задаёт точность сравнения вещественных чисел (эпсилон), оставшиеся три (вещественные числа) являются коэффициентами квадратного уравнения; необходимо вывести в консоль решения этого уравнения при всевозможных уникальных перестановках значений коэффициентов при степенях переменной; \
-m необходимо задать два ненулевых целых числа, после чего определить, кратно ли первое число второму; \
-t первый параметр (вещественное число) задаёт точность сравнения вещественных чисел (эпсилон); необходимо проверить, могут ли оставшиеся три (вещественные числа) параметра являться длинами сторон прямоугольного треугольника

## 📙 Тесты
| Входные данные | Выходные данные |
| :---: | :---: |
| ```.\flags_program.exe -m 1``` | Error: Expected 3 or more arguments, got 2<br>Usage: \<flag> \<parameters> |
| ```.\flags_program.exe -q 0.0001 1.0 2.0``` | Error: Expected 4 parameters, got 3<br>Usage: \<flag> \<parameters><br>Example: -q 0.0001 2.5 -3.0 1.2 |
| ```.\flags_program.exe -m 10 20 30``` | Error: Expected 2 parameters, got 3<br>Usage: \<flag> \<parameters><br>Example: -m 20 10 |
| ```.\flags_program.exe -t 10 20 30``` | Error: Expected 4 parameters, got 3<br>Usage: \<flag> \<parameters><br>Example: -t 0.0001 2.5 3.0 1.2 |
| ```flags_program.exe -q epsilon a b c``` | Error: Failed to read 4 real numbers |
| ```flags_program.exe -q 0.0001 2.5 -3.0 1.2``` | Quadratic equation: 2.5000x^2 + -3.0000x + 1.2000<br>Result: No solutions<br><br>Quadratic equation: 2.5000x^2 + 1.2000x + -3.0000<br>Result: x1 = 0.8814, x2 = -1.3614<br><br>Quadratic equation: 1.2000x^2 + 2.5000x + -3.0000<br>Result: x1 = 0.8518, x2 = -2.9351<br><br>Quadratic equation: 1.2000x^2 + -3.0000x + 2.5000<br>Result: No solutions<br><br>Quadratic equation: -3.0000x^2 + 2.5000x + 1.2000<br>Result: x1 = -0.3407, x2 = 1.1740<br><br>Quadratic equation: -3.0000x^2 + 1.2000x + 2.5000<br>Result: x1 = -0.7345, x2 = 1.1345 |
| ```flags_program.exe -m 0 10``` | Error: Failed to read 2 non-zero integers |
| ```flags_program.exe -m 50 10``` | The first number is a multiple of the second |
| ```flags_program.exe -m 10 50``` | The first number is not a multiple of the second |
| ```flags_program.exe -t epsilon a b c``` | Error: Failed to read 4 real numbers |
| ```flags_program.exe -t 0.0001 3.0 4.0 5.0``` | These values can be the lengths of the sides of a right triangle |
| ```flags_program.exe -t 0.0001 3.0 4.0 5.5``` | These values can not be the lengths of the sides of a right triangle |
