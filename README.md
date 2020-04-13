# 1CDepartmentEntryTask
[![Build Status](https://travis-ci.com/2ToThe10th/1CDepartmentEntryTask.svg?token=3S6xWbBvu4EyXfDwhGsF&branch=master)](https://travis-ci.com/2ToThe10th/1CDepartmentEntryTask)

Данная программа состоит из 2 частей - сервер и клиент.

#### Сервер:
Epoll принимающий соединения и обробатывающий их

Сборка:
  - mkdir cmake-build-client
  - cd cmake-build-client
  - cmake ../ -DSERVER=1
  - make
  
Запускается с одним аргументом - порт на котором работать
  
#### Клиент:
Один сокет, подключающийся к серверу и чтение символов из cin

Сборка:
  - mkdir cmake-build-client
  - cd cmake-build-client
  - cmake ../ -DCLIENT=1
  - make
  
Запускается с 2 аргументами - хост и порт сервера

TODO:
- 
- Добавить mutex в ClientSituation, чтобы появилась многопоточность (пока сервер может работать только в один поток)
- Добавить графический итерфейс в клиента
- Добавить функции выхода из игры
- Декомпозировать ServerMain::GameHandler, потому что слишком длинная
- Добавить русский язык
- Добавить нормальное завершение работы для сервера (послать всем клиентам что сервер прекращает работу и добавить в epoll timeout)
- Добавить на клиенте счетчик оставшихся попыток
- Нормальная обработка ошибок
- Добавить словарь с словами и выбирать из них рандомный
