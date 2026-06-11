#include <iostream>



int doubleInteger() {

    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";

    int y{};
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y << '\n';
    std::cout << x << " - " << y << " is " << x - y << '\n';

    return 0;
}

int doubleNumber(int num) {

    return num + num;
}

#include <string>
using namespace std;
class Book {

    string title, author {};
    int pages;

public:
    Book(string t, string a, int p) : title(t), author(a), pages(p){}

    string get_title() {
        return title;
    }

    bool is_long() {
        if (pages > 300) {
            return true;
        }
        return false;
    }

    void print() {
        cout << title << " by " << author << " (" << pages << " pages)" << endl;
    }


};

class BankAccount {

private:
    string owner;
    double balance;
public:
    BankAccount(string o, double b) : owner(o), balance(b){}

    void deposit(double amount) {
        balance+= amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
    }

    double get_balance() const {
        return balance;
    }

    bool is_overdrawn()  const{
        if (balance < 0) {
            return true;
        }else {
            return false;
        }
    }

    void print() const{
        cout << owner << ": " << balance << endl;
    }
};

int main() {

    Book book1("The Hobbit", "J.R.R. Tolkien", 310);
    Book book2("Animal Farm", "George Orwell", 112);

    book1.print();
    book2.print();

    if (book1.is_long()) {
        cout << "Long Book" << endl;
    }else {
        cout << "Short Book" << endl;
    }
}