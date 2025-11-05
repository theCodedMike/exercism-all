#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {
    void Bankaccount::open() {
        check_open();
        _open = true;
    }

    void Bankaccount::close() {
        check_close();
        _open = false;
        _balance = 0;
    }

    int Bankaccount::balance() const {
        check_close();
        return _balance;
    }

    void Bankaccount::deposit(const int amount) {
        check_close();
        check_amount(amount);

        std::lock_guard lock(_mutex);
        _balance += amount;
    }

    void Bankaccount::withdraw(const int amount) {
        check_close();
        check_amount(amount);
        check_balance(amount);

        std::lock_guard lock(_mutex);
        _balance -= amount;
    }

    void Bankaccount::check_open() const {
        if (_open == true)
            throw std::runtime_error("");
    }

    void Bankaccount::check_close() const {
        if (_open == false)
            throw std::runtime_error("");
    }

    void Bankaccount::check_balance(const int amount) const {
        if (amount > _balance)
            throw std::runtime_error("");
    }

    void Bankaccount::check_amount(const int amount) {
        if (amount < 0)
            throw std::runtime_error("");
    }

}
