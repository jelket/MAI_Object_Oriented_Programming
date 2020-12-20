#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <memory>
#include <algorithm>
#include <exception>


template<typename T, class ALLOCATOR>
class Queue {
private:
    class Node {
    private:
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        T value;
    public:
        using allocator_type = typename ALLOCATOR::template rebind<Node>::other;
        Node(T val): next{nullptr}, prev{next}, value{val} {};
        // singleton allocator
        static allocator_type& get_allocator() {
            static allocator_type allocator;
            return allocator;
        }
        void* operator new(size_t size) {
            return get_allocator().allocate();
        }
        void operator delete(void* p) {
            get_allocator().destroy((Node*)p);
            get_allocator().deallocate((Node*)p);
        }
        friend class Queue;
    };
public:
    class Iterator {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;
        friend class Queue;

        Iterator(std::shared_ptr<Node> it = nullptr): ptr{it} {};
        Iterator(const Iterator &other): ptr{other.ptr} {};

        T& operator*() {
            return this->ptr.lock()->value;
        }

        Iterator operator++() {
            if (this->ptr.lock() == nullptr) {
                return *this;
            }
            this->ptr = ptr.lock()->next;
            return *this;
        }

        Iterator operator++(int s) {
            if (ptr.lock() == nullptr) {
                return *this;
            }
            Iterator old{this->ptr.lock()};
            ++(*this);
            return old;
        }

        const T& operator*() const {
            return this->ptr.lock()->value;
        }

        std::shared_ptr<Node> operator->() {
            return this->ptr.lock();
        }

        std::shared_ptr<const Node> operator->() const {
            return this->ptr.lock();
        }

        bool operator==(const Iterator &rhs) const {
            return this->ptr.lock() == rhs.ptr.lock();
        }

        bool operator!=(const Iterator &rhs) const {
            return this->ptr.lock() != rhs.ptr.lock();
        }

        Iterator Next() const {
            if (this->ptr.lock() == nullptr)
                return Iterator{};
            return this->ptr.lock()->next;
        }

    private:
        std::weak_ptr<Node> ptr;
    };

public:
    T Top(){
        if (head) {
            return head->value;
        }
        throw std::runtime_error("Stack is empty");
    }
    void Push(const T& val) {
        if (!head) {
            head = std::make_shared<Node>(val);
            tail = head;
        } else {
            std::shared_ptr<Node> newElem = std::make_shared<Node>(val);
            newElem->prev = tail;
            tail.lock()->next = newElem;
            tail = newElem;
        }
        size++;
    }

    void Pop() {
        if (this->head) {
            head = head->next;
            size--;
        }
    }

    Iterator Insert(const Iterator it, const T& val) {
        if (it == Iterator{}) {
            if (tail.lock() == nullptr) {
                Push(val);
                return Begin();
            }
            std::shared_ptr<Node> newElem = std::make_shared<Node>(val);
            newElem->prev = tail;
            tail.lock()->next = newElem;
            tail = newElem;
            size++;
            return newElem;
        }
        if (it == Begin()) {
            std::shared_ptr<Node> newElem = std::make_shared<Node>(val);
            newElem->next = it.ptr.lock();
            it->prev.lock() = newElem;
            head = newElem;
            size++;
            return newElem;
        }
        std::shared_ptr<Node> newElem = std::make_shared<Node>(val);
        newElem->next = it.ptr.lock();
        it->prev.lock()->next = newElem;
        newElem->prev = it->prev;
        it->prev.lock() = newElem;
        size++;
        return newElem;
    }


    Iterator Erase(const Iterator it) {
        if (it == Iterator{}) {
            return End();
        }
        if (it->prev.lock() == nullptr && head == tail.lock()) {
            head = nullptr;
            tail = head;
            size = 0;
            return End();
        }
        if (it->prev.lock() == nullptr) {
            it->next->prev.lock() = nullptr;
            head = it->next;
            size--;
            return head;
        }
        Iterator res = it.Next();
        if (res == Iterator{}) {
            it->prev.lock()->next = nullptr;
            size--;
            return End();
        }
        it->next->prev = it->prev;
        it->prev.lock()->next = it->next;
        size--;
        return res;
    }


    Iterator Begin() {
        return head;
    }

    Iterator End() {
        return Iterator{};
    }

    size_t Size() const {
        return size;
    }

    void Print() {
        Iterator it = Begin();
        std::for_each(Begin(), End(), [it, this](auto e)mutable{
            std::cout << e.c.first * e.c.second;
            if (it.Next() != this->End()) {
                std::cout << "\n";
            }
            it++;
        });
        std::cout << "\n";
    }

private:
    std::shared_ptr<Node> head;
    std::weak_ptr<Node> tail;
    size_t size;
};
#endif
