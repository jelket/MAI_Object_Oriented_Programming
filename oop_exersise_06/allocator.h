#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stack>

template<class T, size_t BLOCK_SIZE>
class allocator {
private:
    T* buffer;
    std::stack<T*> free_blocks;

public:

    // allocator traits
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = size_t;

    allocator() noexcept: buffer(nullptr){
        static_assert(BLOCK_SIZE>0);
    }

    ~allocator() {
        ::delete(buffer);
    }

    // allocator type conversion
    template<class U>
    struct rebind {
        using other = allocator<U, BLOCK_SIZE>;
    };

    pointer allocate() {
        // Сначала нужно выделить все блоки
        if (buffer == nullptr) {
            std::cout << "First allocating" << std::endl;
            buffer = (pointer)malloc( sizeof(T) * BLOCK_SIZE );
            for (int i = 0; i < BLOCK_SIZE; ++i) {
                free_blocks.push(buffer + i);
            }
        }
        // Есть ли свободные блоки в стеке?
        if (free_blocks.empty()) {
            throw std::bad_alloc();
        }

        pointer p = free_blocks.top();
        free_blocks.pop();
        std::cout << "Allocated " << p << std::endl;
        return p;

    }

    void deallocate(pointer p) {
        free_blocks.push(p);
    }

    template<typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }
};


#endif
