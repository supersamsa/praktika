#!/bin/bash

read -p "Введите сообщение коммита: " commit_message

if [ -z "$commit_message" ]; then
    echo "Ошибка: сообщение коммита не может быть пустым"
    exit 1
fi

git add . && git commit -m "$commit_message" && git push
