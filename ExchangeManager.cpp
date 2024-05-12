#include "ExchangeManager.h"
#include <iostream>
#include <algorithm>

void ExchangeManager::addRequest(const ExchangeRequest& request) {
    requests.push_back(request);
}

void ExchangeManager::findMatches() {
    auto it = std::remove_if(requests.begin(), requests.end(), [](const ExchangeRequest& request) {
        if (request.matchApartments()) {
            request.print();
            return true;
        }
        return false;
    });

    requests.erase(it, requests.end());
}

void ExchangeManager::printAllRequests() const {
    for (const auto& request : requests) {
        request.print();
        std::cout << "-----------------------\n";
    }
}
