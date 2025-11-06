#pragma once
#include <memory>
#include <stdexcept>

namespace linked_list {

    template <typename T>
    class List {
        struct Node {
            static std::shared_ptr<Node> make_node(T elem) {
                return std::make_shared<Node>(Node{elem});
            }

            T data;
            std::shared_ptr<Node> prev = nullptr;
            std::shared_ptr<Node> next = nullptr;
        };

    public:
        void push(T elem) {
            auto new_node = Node::make_node(elem);
            new_node->next = head;
            if (head)
                head->prev = new_node;
            else
                tail = new_node;
            head = new_node;

            ++size;
        }

        T pop() {
            check_empty();

            auto data = head->data;
            auto next = head->next;
            head->next = nullptr;
            if (next)
                next->prev = nullptr;
            else
                tail = nullptr;
            head = next;

            --size;
            return data;
        }

        void unshift(T elem) {
            auto new_node = Node::make_node(elem);
            new_node->prev = tail;
            if (tail)
                tail->next = new_node;
            else
                head = new_node;
            tail = new_node;

            ++size;
        }

        T shift() {
            check_empty();

            auto data = tail->data;
            auto prev = tail->prev;
            tail->prev = nullptr;
            if (prev)
                prev->next = nullptr;
            else
                head = nullptr;
            tail = prev;

            --size;
            return data;
        }

        void erase(T elem) {
            if (count() == 0)
                return;

            auto curr = head;
            while (curr != nullptr) {
                if (curr->data == elem)
                    break;
                curr = curr->next;
            }

            if (curr != nullptr) {
                auto prev = curr->prev;
                auto next = curr->next;
                if (prev)
                    prev->next = next;
                else
                    head = next;
                if (next)
                    next->prev = prev;
                else
                    tail = prev;
                --size;
            }
        }

        [[nodiscard]]
        size_t count() const {
            return size;
        }

    private:
        std::shared_ptr<Node> head =  nullptr;
        std::shared_ptr<Node> tail = nullptr;
        size_t size = 0;

        void check_empty() const {
            if (size == 0)
                throw std::runtime_error("List is empty");
        }
    };
}  // namespace linked_list
