#!/usr/bin/gnuplot

# Включаем отладочный вывод
print "Начало построения графика..."

# Проверка наличия файла
file_exists = system("if [ -f data1.txt ]; then echo 1; else echo 0; fi")
if (file_exists == 0) {
    print "ОШИБКА: Файл data1.txt не найден!"
    print "Создайте файл с данными в формате:"
    print "кол-во_элементов линейный бинарный экспоненциальный"
    exit
}

# Проверка содержимого файла
print "Содержимое data1.txt (первые 5 строк):"
system("head -5 data1.txt")

# Настройки терминала
set terminal png size 800,600 enhanced font "Times New Roman, 12"
set output 'graph4.png'

# Стили линий
set style line 1 lc rgb "red" lt 1 lw 2 pt 7 ps 1.5
set style line 2 lc rgb "blue" lt 1 lw 2 pt 9 ps 1.5
set style line 3 lc rgb "green" lt 1 lw 2 pt 5 ps 1.5

# Настройки осей
set xlabel "Количество элементов в массиве" font "Times New Roman, 14"
set ylabel "Время выполнения, мкс" font "Times New Roman, 14"

# Включаем сетку
set grid

# Автоматическое масштабирование
set autoscale

# Вывод статистики для проверки
stats 'data1.txt' using 1:2 name "Lin" nooutput
stats 'data1.txt' using 1:3 name "Bin" nooutput
stats 'data1.txt' using 1:4 name "Exp" nooutput

print sprintf("Линейный поиск: min=%f, max=%f", Lin_min_y, Lin_max_y)
print sprintf("Бинарный поиск: min=%f, max=%f", Bin_min_y, Bin_max_y)
print sprintf("Экспоненц. поиск: min=%f, max=%f", Exp_min_y, Exp_max_y)

# Устанавливаем диапазоны вручную, если нужно
# set xrange [0:*]
# set yrange [0:*]

# Заголовок
set title "Зависимость времени выполнения алгоритмов поиска" font "Times New Roman, 16"

# Легенда
set key top left

# Построение графика
print "Построение графика..."
plot 'data1.txt' using 1:2 title 'Линейный поиск' with linespoints ls 1, \
     'data1.txt' using 1:3 title 'Бинарный поиск' with linespoints ls 2, \
     'data1.txt' using 1:4 title 'Экспоненциальный поиск' with linespoints ls 3

print "График сохранен в graph4.png"

# Дополнительная проверка
if (exists("GPVAL_TERMINALS")) {
    print "Терминал: ", GPVAL_TERMINALS
}