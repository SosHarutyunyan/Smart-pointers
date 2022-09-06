#ifndef UNIQUE
#define UNIQUE

template <typename T>
class unique_ptr
{
    public:
        unique_ptr(T* ob);
        unique_ptr(unique_ptr<T>&& ob);
        ~unique_ptr();
        unique_ptr<T>& operator=(unique_ptr<T>&& ob);
        unique_ptr(const unique_ptr<T>& ob) = delete;
        unique_ptr<T>& operator=(const unique_ptr<T>& ob) = delete;

        T* get_deleter () noexcept;
        T* release ();
        void reset (T* ptr);
        void swap(T& ob);
        T* get();
        operator bool();
        T operator*();
        T* operator->();
        T operator[](int index);

    private:
        T* m_ptr = nullptr;
};
#include "unique_ptr.tpp"
#endif // UNIQUE


