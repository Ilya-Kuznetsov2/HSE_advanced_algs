# Advanced algorithms HSE course.

# Problem_1. Доска с монетами.
Вам дали размеченную доску, содержащую N × M клеток — N по строкам и M по столбцам. На каждой клетке этой доски либо орлом, либо решкой вверх лежит монета. За одно действие можно взять две любые соседние по горизонтали или вертикали монеты и перевернуть их. В задаче требуется определить, за какое минимальное число действий можно так перевернуть монеты, что в результате орлы и решки будут лежать в шахматном порядке (т.е. чередоваться — таких порядков ровно 2), либо же сообщить, что это невозможно.
## Формат ввода.
В первой строке записаны 2 целых числа через пробел — N и M (1 ≤ N ⋅ M ≤ 20) — размеры доски. Далее следуют N строк, каждая из которых содержит по M символов — описание доски. Если очередной символ равен '0', то на этой клетке монета лежит вверх орлом, а если '1' — то решкой.
## Формат вывода.
Выведите ответ на задачу, либо же число -1, если решения нет.

#
#
# Problem_2. Максимальный размер компании.
Вам нужно создать компанию. Имеется всего n кандидатов в сотрудники в вашей компании, и вы должны выбрать как можно большее количество сотрудников. Однако есть несколько ограничений. Во-первых, структура компании должна быть строго иерархическая: у компании должен быть единственный директор, у него есть несколько (возможно 0) непосредственных подчиненных, у каждого из них есть несколько (возможно 0) своих непосредственных подчиненных и т.д.
Сотрудник A называется начальником сотрудника B, если B является непосредственным подчиненным A или непосредственным подчиненным непосредственного подчиненного A и т.д. Иными словами, если B — непосредственный подчиненный A, то A является начальником B, а также начальником любого сотрудника C, начальником которого является B. Не каждая пара (A, B), где A — начальник B, может мирно сосуществовать в компании. Если 
B считает A умственно отсталым, и при этом A — начальник B, то это создает некоторую напряженность отношений в компании, которой вы хотели бы избежать. 
Некоторые из n данных людей знакомы друг с другом, периодически встречаются и играют друг с другом в дурака. Если A хотя бы раз выигрывал у B в дурака, то A считает B умственно отсталым, а также A считает умственно отсталым любого человека C, которого таковым считает B. Т.е. если, например, A выигрывал у B, B — у C, C — у D, D — у E, то A считает умственно отсталыми B , C , D, E ; B — C, D, E ; C — D, E ; D — E.
Вам необходимо выяснить, какое наибольшее число сотрудников можно набрать в компанию.
## Формат ввода.
В первой строке входа заданы два целых числа n и m — количество людей и количество сыгранных партий в дурака. В каждой из следующих m строк — три целых числа, первое из которых — номер первого из людей, участвовавших в партии (от 1 до n), второе — номер второго из людей (от 1 до n), третье — результат партии (1 — первый выиграл, 2 — второй выиграл, 3 — ничья). 1 ≤ n, m ≤ 50000.
## Формат вывода.
Выведите максимальное количество сотрудников, которых можно нанять на работу в компанию.
#
#
# Problem_3. 
## Формат ввода.
## Формат вывода.
#
# Problem_4. 
## Формат ввода.
## Формат вывода.
#
# Problem_5. 
## Формат ввода.
## Формат вывода.
#
# Problem_6. 
## Формат ввода.
## Формат вывода.
#
# Problem_7. 
## Формат ввода.
## Формат вывода.

