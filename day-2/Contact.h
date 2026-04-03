//
// Created by harel on 02/04/2026.
//

#pragma once
#include <string>
#include <utility>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;

    Contact(std::string name, std::string phone, std::string email) :
    name(std::move(name)), phone(std::move(phone)), email(std::move(email)) {}
};
