
template <typename T>
unique_ptr<T>::unique_ptr(T *ptr)
{
    m_ptr = ptr;
}

template <typename T>
unique_ptr<T>:: unique_ptr(unique_ptr<T>&& ob)
{
    m_ptr = ob.m_ptr;
    ob.m_ptr = nullptr;
}

template <typename T>
unique_ptr<T>::~unique_ptr()
{
    delete get_deleter();
}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& ob) 
{
    if (this == &ob) 
    {
        return *this;
    }
    m_ptr = ob.m_ptr;
    ob.m_ptr = nullptr;
    return *this;
}

template <typename T>
T* unique_ptr<T>::get_deleter() noexcept
{
    return m_ptr;
}

template <typename T>
T* unique_ptr<T>::release ()
{
    T* new_ptr  = m_ptr;
    m_ptr = nullptr;
    return new_ptr;
}

template <typename T>
void unique_ptr<T>::reset (T* ptr)
{
    T *old_ptr = m_ptr;
    m_ptr = ptr;
    if(old_ptr)
    {
        delete old_ptr;
    }
}

template <typename T>
void unique_ptr<T>::swap(T& ob)
{
    T* tmp = m_ptr;
    m_ptr = &ob;
    ob.ptr = tmp;
    tmp = nullptr;
}

template <typename T>
T* unique_ptr<T>::get()
{
    return m_ptr; 
}

template <typename T>
unique_ptr<T>::operator bool()
{
    if (get())
        return true;
    return false;
}

template <typename T>
T unique_ptr<T>::operator*()
{
    return *get();
}

template <typename T>
T* unique_ptr<T>::operator->()
{
    return get();
}

template <typename T>
T unique_ptr<T>::operator[](int index)
{
    return get()[index];
}