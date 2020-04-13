# 1CDepartmentEntryTask
[![Build Status](https://travis-ci.com/2ToThe10th/1CDepartmentEntryTask.svg?token=3S6xWbBvu4EyXfDwhGsF&branch=master)](https://travis-ci.com/2ToThe10th/1CDepartmentEntryTask)


Данная программа состоит из 2 частей - сервер(-DSERVER) и клиент(-DCLIENT).

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
  
Запускается с 2 аргументами - хост и порт

TODO:
- Добавить mutex в ClientSituation, чтобы появилась многопоточность (пока сервер может работать только в один поток)
- Добавить графический итерфейс в клиента
- Декомпозировать ServerMain::GameHandler, потому что слишком длинная и есть одинаковые фрагменты
- Добавить русский язык
- Добавить нормальное завершение работы для сервера (послать всем клиентам что сервер прекращает работу и добавить в epoll timeout)
- Добавить на клиенте счетчик оставшихся попыток