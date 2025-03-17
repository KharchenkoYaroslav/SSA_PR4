# SSA_PR4

# Звіт по завданням

## Завдання 4.1

### Скільки пам’яті може виділити malloc(3) за один виклик?

- Програма успішно визначає максимальний обсяг пам'яті, який може бути виділений за один виклик `malloc(3)`.
- Результати записані у файл `task1/output/result.txt`.

#### Результат для 64 бітної системи:

Size of size_t: 8 bytes (64 bits)
Trying to allocate 18446744073709551615 bytes...
Memory allocation failed.

#### Результат для 32 бітної системи:

Size of size_t: 4 bytes (32 bits)
Trying to allocate 4294967295 bytes...
Memory allocation failed.

#### Відповідь:

Тому що Архітектура x86_64 не використовує всі 64 біти для адресації. 

## Завдання 4.2

### Що станеться, якщо передати malloc(3) від’ємний аргумент?

- Програма успішно тестує виділення пам'яті з від'ємним аргументом та обчислює кількість виділених байтів за формулою `num = xa * xb`.
- Результати записані у файл `task2/output/result.txt`.

#### Результат для 64 бітної системи:

Trying to allocate 18446744073709551615 bytes...
Memory allocation failed.
num_signed = -727379968 (можливе переповнення)
Trying to allocate 18446744072982171648 bytes...
Memory allocation failed.

#### Результат для 32 бітної системи:

Trying to allocate 4294967295 bytes...
Memory allocation failed.
num_signed = -727379968 (можливе переповнення)
Trying to allocate 3567587328 bytes...
Memory allocation failed.

#### Відповідь:

В обох випадках змінна конвертується в максимальне значення size_t

## Завдання 4.3

### Що станеться, якщо використати malloc(0)?

- Програма успішно тестує виділення пам'яті з аргументом 0.
- Результати записані у файл `task3/output/result.txt`.

#### Результат:

Testing malloc(0)
malloc(0) returned non-NULL pointer, freeing it.

#### Результат ltrace:

fopen("output/result.txt", "w")                  = 0x5575f71db2a0
fwrite("Testing malloc(0)\n", 1, 18, 0x5575f71db2a0) = 18
malloc(0)                                        = 0x5575f71dc490
fwrite("malloc(0) returned non-NULL poin"..., 1, 49, 0x5575f71db2a0) = 49
free(0x5575f71dc490)                             = <void>
fclose(0x5575f71db2a0)                           = 0
+++ exited (status 0) +++

## Завдання 4.4

### Чи є помилки у такому коді?

- Програма успішно демонструє проблему та правильний варіант коду.
- Результати записані у файли `task4/output/result_1.txt` та `task4/output/result_2.txt`.

#### Результат для коректної програми:

Memory allocated at iteration 0
Using ptr at iteration 0
Memory allocated at iteration 1
Using ptr at iteration 1
Memory allocated at iteration 2
Using ptr at iteration 2
Memory allocated at iteration 3
Using ptr at iteration 3
Memory allocated at iteration 4
Using ptr at iteration 4

#### Результат ltrace:

fopen("output/result_1.txt", "w")                = 0x55698009f2a0
malloc(10)                                       = 0x55698009f480
fprintf(0x55698009f2a0, "Memory allocated at iteration %d"..., 0) = 32
fprintf(0x55698009f2a0, "Using ptr at iteration %d\n", 0) = 25
free(0x55698009f480)                             = <void>
fprintf(0x55698009f2a0, "Using ptr at iteration %d\n", 1) = 25
free(0x55698009f480free(): double free detected in tcache 2
 <no return ...>
--- SIGABRT (Aborted) ---
+++ killed by SIGABRT +++
fopen("output/result_2.txt", "w")                = 0x55ad5f3b62a0
malloc(10)                                       = 0x55ad5f3b6480
fprintf(0x55ad5f3b62a0, "Memory allocated at iteration %d"..., 0) = 32
fprintf(0x55ad5f3b62a0, "Using ptr at iteration %d\n", 0) = 25
free(0x55ad5f3b6480)                             = <void>
malloc(10)                                       = 0x55ad5f3b6480
fprintf(0x55ad5f3b62a0, "Memory allocated at iteration %d"..., 1) = 32
fprintf(0x55ad5f3b62a0, "Using ptr at iteration %d\n", 1) = 25
free(0x55ad5f3b6480)                             = <void>
malloc(10)                                       = 0x55ad5f3b6480
fprintf(0x55ad5f3b62a0, "Memory allocated at iteration %d"..., 2) = 32
fprintf(0x55ad5f3b62a0, "Using ptr at iteration %d\n", 2) = 25
free(0x55ad5f3b6480)                             = <void>
malloc(10)                                       = 0x55ad5f3b6480
fprintf(0x55ad5f3b62a0, "Memory allocated at iteration %d"..., 3) = 32
fprintf(0x55ad5f3b62a0, "Using ptr at iteration %d\n", 3) = 25
free(0x55ad5f3b6480)                             = <void>
malloc(10)                                       = 0x55ad5f3b6480
fprintf(0x55ad5f3b62a0, "Memory allocated at iteration %d"..., 4) = 32
fprintf(0x55ad5f3b62a0, "Using ptr at iteration %d\n", 4) = 25
free(0x55ad5f3b6480)                             = <void>
+++ exited (status 0) +++

## Завдання 4.5

### Що станеться, якщо realloc(3) не зможе виділити пам’ять?

- Програма успішно демонструє сценарій, коли `realloc(3)` не може виділити пам'ять.
- Результати записані у файл `task5/output/result.txt`.

#### Результат:

Memory allocated
Memory reallocation failed, but original pointer is lost!

## Завдання 4.6

### Якщо realloc(3) викликати з NULL або розміром 0, що станеться?

- Програма успішно тестує виклики `realloc(3)` з NULL або розміром 0.
- Результати записані у файл `task6/output/result.txt`.

#### Результат:

realloc(NULL, 16) успішний, отримано адресу: 0x56411fbbe480
realloc(ptr, 0) повернув NULL 

## Завдання 4.7

### Перепишіть наступний код, використовуючи reallocarray(3):

- Програма успішно переписує код з використанням `reallocarray(3)`
- Результати записані у файли `task7/output/result_1.txt` та `task7/output/result_2.txt`.

#### Результати з використанням `ltrace`:

fopen("output/result_1.txt", "w")                = 0x55ff551ac2a0
calloc(1000, 4)                                  = 0x55ff551ac480
realloc(0x55ff551ac480, 2000)                    = 0x55ff551ac480
fwrite("Memory successfully reallocated "..., 1, 47, 0x55ff551ac2a0) = 47
free(0x55ff551ac480)                             = <void>
+++ exited (status 0) +++
fopen("output/result_2.txt", "w")                = 0x55abba1d32a0
calloc(1000, 4)                                  = 0x55abba1d3480
reallocarray(0x55abba1d3480, 500, 4, 0)          = 0x55abba1d3480
fwrite("Memory successfully reallocated "..., 1, 52, 0x55abba1d32a0) = 52
free(0x55abba1d3480)                             = <void>
+++ exited (status 0) +++

## Завдання 8 (Варіант 22)

### Використайте системні виклики sbrk() та brk() для маніпуляції heap.

- Програма успішно використовує системні виклики `sbrk()` та `brk()` для маніпуляції heap.
- Результати записані у файл `task1/output/result.txt`.

#### Результат:

Початковий break: 0x55b3fd0fb000
Пам'ять виділена за адресою: 0x55b3fd0fb000
Новий break: 0x55b3fd0fb400
Heap повернуто у початковий стан.
