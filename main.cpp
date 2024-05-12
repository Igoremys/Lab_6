#include <iostream>
#include "Apartment.h"
#include "ExchangeRequest.h"
#include "ExchangeManager.h"

int main() {
    ExchangeManager manager;

    int choice;
    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить заявку на обмен\n";
        std::cout << "2. Найти совпадения\n";
        std::cout << "3. Вывести все заявки\n";
        std::cout << "4. Выйти\n";
        std::cout << "Введите ваш выбор: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << "\nВведите данные для требуемой квартиры:\n";
                Apartment wanted;
                std::cout << "Количество комнат: ";
                std::cin >> wanted.numRooms;
                std::cout << "Площадь (кв. м): ";
                std::cin >> wanted.area;
                std::cout << "Этаж: ";
                std::cin >> wanted.floor;
                std::cout << "Район: ";
                std::cin >> wanted.district;

                std::cout << "\nВведите данные для доступной квартиры:\n";
                Apartment available;
                std::cout << "Количество комнат: ";
                std::cin >> available.numRooms;
                std::cout << "Площадь (кв. м): ";
                std::cin >> available.area;
                std::cout << "Этаж: ";
                std::cin >> available.floor;
                std::cout << "Район: ";
                std::cin >> available.district;

                ExchangeRequest request(wanted, available);
                manager.addRequest(request);
                break;
            }
            case 2:
                std::cout << "\nСовпадения:\n";
                manager.findMatches();
                break;
            case 3:
                std::cout << "\nВсе заявки на обмен:\n";
                manager.printAllRequests();
                break;
            case 4:
                std::cout << "\nВыход...\n";
                break;
            default:
                std::cout << "\nНеверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 4);

    return 0;
}
