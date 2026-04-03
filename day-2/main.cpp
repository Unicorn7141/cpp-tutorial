#include <algorithm>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <limits>

#include "Contact.h"

int main() {
    std::unordered_map<std::string, Contact> contacts;
    int action;
    std::string name, phone, email;

    while (true) {
        // TIP Select an option
        std::cout << "Choose an option: \n";
        std::cout << "\t 1. Add contact\n";
        std::cout << "\t 2. Remove contact\n";
        std::cout << "\t 3. View contacts\n";
        std::cout << "\t 4. Exit\n";
        std::cout << "\nAction [1~4]: ";
        std::cin >> action;

        if (action < 1 || action > 4) {
            std::cout << "\nInvalid action. Try again.\n";
            continue;
        }
        if (action == 4) {
            std::cout << "EXITING" << std::endl;
            break;
        }
        if (action == 1) {
            // TIP Ignore the <code>'\n'</code> from the action selection
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid Input. Try again.\n";
                continue;
            }

            // TIP Add a contact to the list
            std::cout << "\nAdd contact\n";
            std::cout << "Name: ";
            std::getline(std::cin, name);
            std::cout << "Phone: ";
            std::getline(std::cin, phone);
            std::cout << "Email: ";
            std::getline(std::cin, email);
            auto c = Contact(name, phone, email);
            contacts.emplace(name, c);
        } else if (action == 2) {
            std::cout << "\nRemove contact\n";
            std::cout << "Name: ";
            std::getline(std::cin, name);
            if (contacts.contains(name)) { contacts.erase(name); } else {
                std::cout << "No contact named " << name << " was found!\n" << std::endl;
            }
        } else {
            std::cout << "\n--- Phone Book ---\n";
            int emailSize = 1;
            int nameSize = 1;
            int phoneSize = 1;

            for (auto &contact: contacts) {
                if (contact.second.phone.length() > phoneSize)
                    phoneSize = static_cast<int>(contact.second.phone.length());
                if (contact.second.email.length() > emailSize)
                    emailSize = static_cast<int>(contact.second.email.length());
                if (contact.second.name.length() > nameSize)
                    nameSize = static_cast<int>(contact.second.name.length());
            }
            // TIP Header
            std::cout << std::left << std::setw(++nameSize) << "Name"
                    << std::setw(++phoneSize) << "Phone"
                    << "Email" << "\n";

            for (const auto &pair: contacts) {
                const Contact &c = pair.second;
                std::cout << std::left << std::setw(nameSize) << c.name
                        << std::setw(phoneSize) << c.phone
                        << c.email << "\n";
            }
        }
        return 0;
    }
}
