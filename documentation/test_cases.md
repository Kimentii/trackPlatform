# Проверка тестовых сценариев

## Представление результатов

Предоставление результатов требуется описать в следующем виде:

1. Идентификатор
2. Назначение / название
3. Сценарий
4. Ожидаемый результат
5. Фактический результат (заполняется на этапе тестирования)
6. Оценка (заполняется на этапе тестирования)

## Тестовые сценарии:

#### Возможность подключения к платформе

1. 1
2. Возможность подключения к платформе
3. Произведите следующие шаги:

   1. Включите платформу

   2. Дождитесь загрузки платформы

   3. Запустите приложение
4. В приложении появится надпись "Connected"
5. В приложении появилась надпись "Connected"
6. Выполнен

#### Возможность принудительного отключения от платформы

1. 2
2. Возможность принудительного отключения от платформы по завершению работы с ней
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Нажать кнопку Exit в главном меню приложения
   3. Попробуйте заново подключиться к платформе
4. В приложении, появится надпись "Connected"
5. В приложении появилась надпись "Connected"
6. Выполнен

#### Движение вперед

1. 3
2. Проверка движения платформы вперед
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Перейти из главного меню в меню "Motion"
   3. Выберите в приложении "forward"
4. Платформа должна поехать вперед
5. Платформа поехала вперед
6. Выполнен

#### Движение назад

1. 4
2. Проверка движения платформы назад
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Перейти из главного меню в меню "Motion"
   3. Выберите в приложении "back"
4. Платформа должна поехать назад
5. Платформа поехала назад
6. Выполнен

#### Разворот по направлению движения часовой стрелки

1. 5
2. Проверка возможности поворота платформы по часовой стрелке
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Перейти из главного меню в меню "Motion"
   3. Выберите в приложении "right"
4. Платформа должна начать поворачиваться по часовой стрелке
5. Платформа начала поворачиваться по часовой стрелке
6. Выполнен

#### Разворот против направления движения часовой стрелки

1. 6
2. Проверка возможности поворота платформы против часовой стрелки
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Перейти из главного меню в меню "Motion"
   3. Выберите в приложении "left"
4. Платформа должна начать поворачиваться против часовой стрелки
5. Платформа начала поворачиваться против часовой стрелки
6. Выполнен

#### Поворот сервоприводов в плоскости xy

1. 7
2. Проверка возможности поворота сервоприводов в плоскости xy
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Перейти из главного меню в меню "Servo"
   3. Нажмите на кнопку right
4. Платформа должна изменить угол отклонения сервопривода
5. Сервопривод на платформе повернулся вправо
6. Выполнен

#### Поворот сервоприводов в плоскости xz

1. 8
2. Проверка возможности поворота сервоприводов в плоскости xz
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Перейти из главного меню в меню "Servo"
   3. Нажмите на кнопку "up"
4. Платформа должна поднять сервопривод вверх
5. Сервопривод на платформе повернулся вверх
6. Выполнен

#### Получение информации с датчиков линии. Белый лист

1. 9
2. Получение информации с датчиков линии. Проверка корректного определения белого цвета
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Положите под платформу лист белой бумаги
   3. Нажмите на кнопку "Sensors"
4. В приложении напротив нумерации датчиков линии должно появиться значение 0
5. Были значения как 0, так и 1
6. Не выполнен

#### Получение информации с датчиков линии. Черный лист

1. 10
2. Получение информации с датчиков линии. Проверка корректного определения черного цвета
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Положите под платформу лист черной бумаги
   3. Нажмите на кнопку "Sensors"
4. В приложении напротив нумерации датчиков линии должно появиться значение 1
5. Были значения как 0, так и 1
6. Не выполнен

#### Получение информации с датчиков расстояния

1. 11
2. Получение информации с датчиков расстояния
3. Произведите следующие шаги:
   1. Подключитесь к платформе
   2. Подставьте перед центральным датчиком расстояния какой-нибудь непрозрачный предмет, например книгу, на расстоянии приблизительно 15 сантиметров
   3. Нажмите на кнопку "Sensors"
4. В приложении должно появится значение от 10 до 19
5. В приложении появилось значение 21 напротив значения центрального датчика
6. Не выполнен