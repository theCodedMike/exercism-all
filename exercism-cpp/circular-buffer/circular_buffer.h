#pragma once
#include <vector>
#include <stdexcept>

namespace circular_buffer {
    template <typename T>
    class circular_buffer {
    public:
        explicit circular_buffer(size_t size);

        T read();
        void write(T elem);
        void overwrite(T elem);
        void clear();

    private:
        std::vector<T> buffer;
        int new_pos = 0; // write
        int old_pos = 0; // read
        std::size_t count = 0;   // elem count
    };

    template<typename T>
    circular_buffer<T>::circular_buffer(const size_t size) {
        buffer = std::vector<T>(size, T{});
    }

    template<typename T>
    T circular_buffer<T>::read() {
        if (count == 0)
            throw std::domain_error("");

        auto tmp = buffer[old_pos];
        old_pos = (old_pos + 1) % buffer.size();
        count--;
        return tmp;
    }

    template<typename T>
    void circular_buffer<T>::write(T elem) {
        if (count == buffer.size())
            throw std::domain_error("");

        buffer[new_pos] = elem;
        new_pos = (new_pos + 1) % buffer.size();
        count++;
    }

    template<typename T>
    void circular_buffer<T>::overwrite(T elem) {
        if (count == buffer.size()) {
            buffer[old_pos] = elem;
            old_pos = (old_pos + 1) % buffer.size();
        } else {
            write(elem);
        }
    }

    template<typename T>
    void circular_buffer<T>::clear() {
        new_pos = old_pos = 0;
        count = 0;
    }
}  // namespace circular_buffer
