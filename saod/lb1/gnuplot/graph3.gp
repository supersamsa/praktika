#!/usr/bin/gnuplot

# Настройки терминала
set terminal png size 1200,800 enhanced font "Times New Roman, 14"
set output 'graph3.png'

# Мультиграфик - два графика в одном окне
set multiplot layout 2,2 title "Анализ производительности поиска (Таблица 2)"

# Стили линий
set style line 1 lc rgb "red" lt 1 lw 3 pt 7 ps 1.5
set style line 2 lc rgb "blue" lt 1 lw 3 pt 9 ps 1.5

# График 1: Линейный vs Бинарный для 1М элементов
set size 0.5,0.5
set origin 0,0.5

set title "Поиск в массиве 1М элементов"
set xlabel "Количество поисков"
set ylabel "Время, мкс"
set grid
set key top left

plot 'data2.txt' using 1:2 title 'Линейный (1М)' with linespoints ls 1, \
     'data2.txt' using 1:3 title 'Бинарный (1М)' with linespoints ls 2

# График 2: Линейный vs Бинарный для 5М элементов
set size 0.5,0.5
set origin 0.5,0.5

set title "Поиск в массиве 5М элементов"
set xlabel "Количество поисков"
set ylabel "Время, мкс"
set grid
set key top left

plot 'data2.txt' using 1:4 title 'Линейный (5М)' with linespoints ls 1, \
     'data2.txt' using 1:5 title 'Бинарный (5М)' with linespoints ls 2

# График 3: Сравнение бинарного поиска для разных размеров
set size 0.5,0.5
set origin 0,0

set title "Сравнение бинарного поиска"
set xlabel "Количество поисков"
set ylabel "Время, мкс"
set grid
set key top left

plot 'data2.txt' using 1:3 title 'Бинарный (1М)' with linespoints ls 2, \
     'data2.txt' using 1:5 title 'Бинарный (5М)' with linespoints ls 1

# График 4: Отношение времени линейного к бинарному
set size 0.5,0.5
set origin 0.5,0

set title "Отношение времени линейного к бинарному"
set xlabel "Количество поисков"
set ylabel "Линейный / Бинарный"
set grid
set key top left

# Вычисляем отношение в самом gnuplot
plot 'data2.txt' using 1:($2/$3) title 'Отношение (1М)' with linespoints ls 1, \
     'data2.txt' using 1:($4/$5) title 'Отношение (5М)' with linespoints ls 2

unset multiplot