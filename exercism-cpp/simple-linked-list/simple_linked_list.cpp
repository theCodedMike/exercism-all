#include "simple_linked_list.h"

#include <functional>
#include <stdexcept>

namespace simple_linked_list {
    std::size_t List::size() const {
        return current_size;
    }

    void List::push(int entry) {
        auto *new_node = new Element(entry);
        new_node->next = head;
        head = new_node;

        ++current_size;
    }

    int List::pop() {
        if (size() == 0)
            throw std::runtime_error("List is empty");

        const int data = head->data;
        head = head->next;
        --current_size;

        return data;
    }

    // 循环版本
    /*
    void List::reverse() {
        if (size() == 0)
            return;

        Element *tmp = nullptr;
        while (head) {
            const auto next = head->next;
            if (tmp) {
                head->next = tmp;
                tmp = head;
            } else {
                tmp = head;
                tmp->next = nullptr;
            }
            head = next;
        }

        head = tmp;
    }
    */

    // 递归版本1
    /*
    void List::reverse() {
        if (size() == 0)
            return;

        std::function<Element *(Element *, Element *)> do_reverse = [&do_reverse](Element* prev, Element* curr) {
            if (curr == nullptr)
                return prev;
            const auto next = curr->next;
            curr->next = prev;
            return do_reverse(curr, next);
        };

        head = do_reverse(nullptr, head);
    }
    */

    // 递归版本2
    void List::reverse() {
        if (size() == 0)
            return;

        struct Helper {
            static Element * do_reverse(Element * prev, Element * curr) {
                if (curr == nullptr)
                    return prev;
                const auto next = curr->next;
                curr->next = prev;
                return do_reverse(curr, next);
            }
        };

        head = Helper::do_reverse(nullptr, head);
    }

    List::~List() {
        while (head) {
            const auto next = head->next;
            delete head;
            head = next;
        }
    }
} // namespace simple_linked_list
