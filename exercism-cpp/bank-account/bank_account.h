#pragma once
#include <mutex>

namespace Bankaccount {
    class Bankaccount {
    public:
        Bankaccount() = default;

        void open();
        void close();
        [[nodiscard]]
        int balance() const;
        void deposit(int);
        void withdraw(int);


    private:
        std::mutex _mutex;
        int _balance = 0;
        bool _open = false;

        void check_open() const;
        void check_close() const;
        void check_balance(int) const;
        static void check_amount(int);
    };
}
