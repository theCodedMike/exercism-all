#pragma once
#include <memory>
#include <stack>

namespace binary_search_tree {
    template <typename T>
    class binary_tree {
        class iterator {
        public:
            //using iterator_category = std::forward_iterator_tag;
            //using value_type = T;
            //using difference_type = std::ptrdiff_t;
            using pointer = const T *;
            using reference = const T &;

            iterator() : curr(nullptr){}
            explicit iterator(const binary_tree * root) {
                push_to_leftmost(root);
            }
            reference operator*() const {
                return curr->_data;
            }
            pointer operator->() const {
                return &(curr->_data);
            }
            iterator & operator++() {
                if (curr) {
                    if (curr->_right)
                        push_to_leftmost(curr->_right.get());
                    else {
                        if (ancestors.empty())
                            curr = nullptr;
                        else {
                            curr = ancestors.top();
                            ancestors.pop();
                        }
                    }
                }

                return *this;
            }
            iterator operator++(int) {
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bool operator==(const iterator & rhs) const {
                return curr == rhs.curr;
            }
            bool operator!=(const iterator & rhs) const {
                return !(*this == rhs);
            }
        private:
            const binary_tree<T>* curr;
            std::stack<const binary_tree<T>*> ancestors;

            void push_to_leftmost(const binary_tree<T>* node) {
                while (node) {
                    ancestors.push(node);
                    node = node->_left.get();
                }
                if (ancestors.empty())
                    curr = nullptr;
                else {
                    curr = ancestors.top();
                    ancestors.pop();
                }
            }
        };

    public:
        explicit binary_tree(T);

        const T & data() const;

        const std::unique_ptr<binary_tree<T>> & left() const;

        const std::unique_ptr<binary_tree<T>> & right() const;

        void insert(T);

        [[nodiscard]]
        iterator begin() const;

        [[nodiscard]]
        iterator end() const;
    private:
        T _data;
        std::unique_ptr<binary_tree<T>> _left = nullptr;
        std::unique_ptr<binary_tree<T>> _right = nullptr;
    };


    template<typename T>
    binary_tree<T>::binary_tree(T elem)
        : _data(elem){
    }

    template<typename T>
    const T &binary_tree<T>::data() const {
        return _data;
    }

    template<typename T>
    const std::unique_ptr<binary_tree<T> > &binary_tree<T>::left() const {
        return _left;
    }

    template<typename T>
    const std::unique_ptr<binary_tree<T> > &binary_tree<T>::right() const {
        return _right;
    }

    template<typename T>
    void binary_tree<T>::insert(T elem) {
        if (elem <= _data) {
            if (_left == nullptr)
                _left = std::make_unique<binary_tree>(elem);
            else
                _left->insert(elem);
        } else {
            if (_right == nullptr)
                _right = std::make_unique<binary_tree>(elem);
            else
                _right->insert(elem);
        }
    }

    template<typename T>
    typename binary_tree<T>::iterator binary_tree<T>::begin() const {
        return iterator(this);
    }

    template<typename T>
    typename binary_tree<T>::iterator binary_tree<T>::end() const {
        return iterator();
    }
}  // namespace binary_search_tree
