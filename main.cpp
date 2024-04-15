/* Dependency */
#include <iostream>
#include <vector>
#include <string>
#define NEW_RECORD 1
#define FETCH_RECORD 2
#define EXIT 3





/* Class For Info */
class User {
public:
    std::string name;
    int age;
};

/* Vector of our User class */
std::vector<User> records;

void AddRecord(const std::string& name, int age) {
    User new_User;         //Create new object
    new_User.name = name;  //Store the name 
    new_User.age = age;    //Store the age
    records.push_back(new_User);  //Pushback the object to the vector
}

User FetchRecord(int userID) {
    /* check ID bouds */
    if (userID >= 0 && userID < records.size()) {
        /* If ID found return the object from the vector with index = id */
        return records[userID];
    } else {
        // Return an empty User if the userID is out of bounds
        User empty_User; //dummy object
        return empty_User;
    }
}

void print_start(void)
{
        std::cout << "Options:\n";
        std::cout << "1. Add Record\n";
        std::cout << "2. Fetch Record\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
}
void print_seperator(void)
{
    std::cout << "======================================\n";
}

int main() {
    int choice = 0;
    while (choice != 3) {
        print_start();
        std::cin >> choice;
        switch (choice) {
            case NEW_RECORD: {
                std::string name;
                int age;
                print_seperator();
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter age: ";
                std::cin >> age;
                AddRecord(name, age);
                std::cout << "Record added successfully!\n";
                print_seperator();
                break;
            }
            case FETCH_RECORD: {
                int userID;
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                User fetchedUser = FetchRecord(userID);
                if (!fetchedUser.name.empty()) {
                    print_seperator();
                    std::cout << "Name: " << fetchedUser.name << ", Age: " << fetchedUser.age << "\n";
                    print_seperator();
                } else {
                    print_seperator();
                    std::cout << "Record not found!\n";
                    print_seperator();
                }
                break;
            }
            case EXIT:
                print_seperator();
                std::cout << "Exiting...\n";
                print_seperator();
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }
    }

    return 0;
}