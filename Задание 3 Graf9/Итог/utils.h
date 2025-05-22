/**
 * @file utils.h
 * @brief Вспомогательные функции для валидации входных данных
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <string>

 /**
  * @brief Проверяет корректность входных параметров задачи
  * @param cities Общее количество городов (должно быть 1-15)
  * @param start Начальный город маршрута (1-based индекс)
  * @param end Конечный город маршрута (1-based индекс)
  * @param transfers Допустимое количество пересадок (неотрицательное)
  * @throw std::invalid_argument При нарушении любого из условий валидации
  *
  * Функция выполняет следующие проверки:
  * - Количество городов в допустимом диапазоне
  * - Корректность номеров начального/конечного города
  * - Недопустимость отрицательного числа пересадок
  */
void ValidateInput(int cities, int start, int end, int transfers);

#endif // UTILS_H