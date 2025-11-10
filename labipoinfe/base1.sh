#!/bin/sh


touch my_file             # создание файла
date > my_file            # запись даты и времени
pwd >> my_file            # запись текущего каталога в файл
who >> my_file            # запись имени в файл
uname -s -r >> my_file    # запись названия ОС в файл
