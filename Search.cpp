#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <chrono>

int count_srav;

// Заполение массива случайными числами
std::vector<int> createMassiv(int count) {
    int start = -100;
    int end = 100;

    std::vector<int> mas;

    for (int i = 0; i < count; i++) {
        int el = rand() % (end - start + 1);
        mas.push_back(el);
    }

    return mas;
}

// Вывод массива
void printMas(const std::vector<int> mas) {
    std::cout << std::endl;
    for (int element : mas) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int linearSearch(const std::vector<int>& vec, int key) {
    count_srav = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
        count_srav++;
        if (vec[i] == key) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

std::string spacesIndentation(int val, int length) {
    std::string str = std::to_string(val);
    int size = length - str.size();
    for (int i = 0; i < size; i++) {
        str += " ";
    }
    return str;
}

std::string spacesIndentationFloat(float val, int length) {
    std::string str = std::to_string(val);
    int size = length - str.size();
    for (int i = 0; i < size; i++) {
        str += " ";
    }
    return str;
}

void printTable()
{
    std::vector<int> count_el = { 20,500,1000,3000,5000,10000 };

    std::cout << "\n+ ---------------+--------+-----------------+--------------+-----------+" << std::endl;
    std::cout << "| Метод поиска   | Размер | Искомый элемент | Сравнения    | Время (мс)|" << std::endl;
    std::cout << "+ ---------------+--------+-----------------+--------------+-----------+" << std::endl;
    for (int count : count_el)
    {
        std::vector<int> mas = createMassiv(count);
        int search_el = mas[rand() % (count - 0 + 1)];

        // Линейный поиск
        auto start = std::chrono::high_resolution_clock::now();
        linearSearch(mas, search_el);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        float time_linear = duration.count() * 1000;

        std::cout << "| Линейный поиск |" << spacesIndentation(mas.size(), 8) << "|"<< spacesIndentation(search_el, 17) << "|"<< spacesIndentation(count_srav, 14) << "|"<< spacesIndentationFloat(time_linear, 11) << "|" << std::endl;

        std::cout << "+ ---------------+--------+-----------------+--------------+-----------+" << std::endl;
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RU");
    printTable();
}