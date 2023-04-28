#include <iostream>
#include <ctime>

char menu();

void show_balance(double user_money);

double make_deposit();

double withdraw(double user_money);

int main() {
    srand(time(0));
    double user_money = rand() % 1000 + 1;

    std::cout << "Welcome to your awesome bank, what can we do for you ?\n";

    bool exit = false;

    do {
        switch (menu()) {
            case '1':
                show_balance(user_money);
                break;
            case '2':
                user_money -= withdraw(user_money);
                show_balance(user_money);
                break;
            case '3':
                user_money += make_deposit();
                show_balance(user_money);
                break;
            case '4':
                exit = true;
                break;
        }
    } while (!exit);

    return 0;
}

char menu() {
    char choice = 'Z';
    bool correct_choice = false;
    do {
        std::cout << "Choose an action \n";
        std::cout << "1. Show balance \n2. Withdraw money \n3. Make a deposit \n4. Exit\n";
        std::cout << "> ";
        std::cin >> choice;
        correct_choice = choice == '1' || choice == '2' || choice == '3' || choice == '4';

        if (!correct_choice) {
            std::cout << "Please enter a correct option\n";
        }
    } while (!correct_choice);

    return choice;
}

double make_deposit() {
    double amount = 0;
    do {
        std::cout << "How much do you want to store ? \n";
        std::cout << "> ";
        std::cin >> amount;

        if (amount > 10000) {
            std::cout << "You can deposit a maximum of 10_000€ \n";
            std::cout << "Please enter a more reasonable amount\n";
        }

    } while (amount > 10000);

    return amount;
}

void show_balance(double user_money) {
    std::cout << "Your balance is: " << user_money << "€ \n";
}

double withdraw(double user_money) {
    show_balance(user_money);
    double amount = 0;

    do {
        std::cout << "How much money do you wish to withdraw ? \n";
        std::cout << "> ";
        std::cin >> amount;

        if (amount > user_money) {
            std::cout << "You don't have enough money, please enter correct amount\n";
        }
    } while (amount > user_money);

    return amount;
}