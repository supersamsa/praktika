#!/usr/bin/gnuplot

# Настройки терминала
set terminal png size 1000,700 enhanced font "Times New Roman, 14"
set output 'graph2.png'

# Стили линий
set style line 1 lc rgb "blue" lt 1 lw 4 pt 9 ps 2
set style line 2 lc rgb "green" lt 1 lw 4 pt 5 ps 2

# Сетка и границы
set grid
set border lw 2

# Подписи осей
set xlabel "Количество элементов в массиве" font "Times New Roman, 16"
set ylabel "Время выполнения, мкс" font "Times New Roman, 16" rotate by 90

# Линейная шкала (без логарифма)
unset logscale

# Формат чисел
set format x "%.0f"
set format y "%.3f"

# Настройки легенды
set key top left box lw 2

# Заголовок
set title "Сравнение бинарного и экспоненциального поиска" font "Times New Roman, 18"

# Построение графиков
plot 'data1.txt' using 1:3 title 'Бинарный поиск' with linespoints ls 1, \
     'data1.txt' using 1:4 title 'Экспоненциальный поиск' with linespoints ls 2