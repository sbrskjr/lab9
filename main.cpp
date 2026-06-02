#include "tasks.h"

int main() {
    int choice;
    do {
        std::cout << "\n--- МЕНЮ ---\n";
        std::cout << "1. Завдання 1 (Вставка рядка)\n";
        std::cout << "2. Завдання 2 (Заміна підрядків у файлі)\n";
        std::cout << "0. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            task1();
        } else if (choice == 2) {
            task2();
        }
    } while (choice != 0);
    return 0;
}
