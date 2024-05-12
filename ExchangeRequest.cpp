#include "ExchangeRequest.h"
#include <iostream>

ExchangeRequest::ExchangeRequest(const Apartment& wanted, const Apartment& available)
    : wantedApartment(wanted), availableApartment(available) {}

bool ExchangeRequest::matchApartments() const {
    // Проверяем совпадение количества комнат, этажа и района
    return (wantedApartment.numRooms == availableApartment.numRooms &&
            wantedApartment.floor == availableApartment.floor &&
            wantedApartment.district == availableApartment.district &&
            // Разница в площади не превышает 10%
            std::abs(wantedApartment.area - availableApartment.area) / wantedApartment.area <= 0.1);
}

void ExchangeRequest::print() const {
    std::cout << "Требуемая квартира:\n";
    std::cout << "Количество комнат: " << wantedApartment.numRooms << std::endl;
    std::cout << "Площадь: " << wantedApartment.area << " кв. м" << std::endl;
    std::cout << "Этаж: " << wantedApartment.floor << std::endl;
    std::cout << "Район: " << wantedApartment.district << std::endl;

    std::cout << "\nДоступная квартира:\n";
    std::cout << "Количество комнат: " << availableApartment.numRooms << std::endl;
    std::cout << "Площадь: " << availableApartment.area << " кв. м" << std::endl;
    std::cout << "Этаж: " << availableApartment.floor << std::endl;
    std::cout << "Район: " << availableApartment.district << std::endl;
}
