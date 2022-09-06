#ifndef _SHARED_H
#define _SHARED_H

#include <utility>

template <typename T>
class shared_ptr
{
public:
    shared_ptr();
    shared_ptr(T* ptr);
    shared_ptr(const shared_ptr& ob);
    shared_ptr(shared_ptr&& ob);
    shared_ptr& operator=(const shared_ptr& ob);
    shared_ptr& operator=(shared_ptr&& ob);
    ~shared_ptr();

    void reset(T* ptr);
    void swap(shared_ptr& ob);
    T* get();
    int use_count();
    bool unique();
    bool owner_before(const shared_ptr<T>& ob) const;
    operator bool();
    T operator*();
    T* operator->();
    T operator[](int index);

private:
    T* m_ptr;
    static int count;
};

#include "shared_ptr.tpp"

#endif // _SHARED_H
