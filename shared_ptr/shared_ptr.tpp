template <typename T>
int shared_ptr<T>::count = 0;

template <typename T>
shared_ptr<T>::shared_ptr()
{
    ++count;
    m_ptr = nullptr;
}

template <typename T>
shared_ptr<T>::shared_ptr(T* ptr)
{
    ++count;
    m_ptr = ptr;
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr& ob)
{
    ++count;
    m_ptr = ob.m_ptr;
}

template <typename T>
shared_ptr<T>::shared_ptr(shared_ptr&& ob)
{
    m_ptr = ob.m_ptr;
    ob.m_ptr = nullptr;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>:: operator =(const shared_ptr& ob)
{
    if(this == &ob) 
    {
        return *this;
    }
    ++count;
    m_ptr = ob.m_ptr;
    return *this;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator =(shared_ptr&& ob)
{
    if(this == &ob) 
    {
        return *this;
    }
    m_ptr = ob.m_ptr;
    ob.m_ptr = nullptr;
    return *this;
}

template <typename T>
shared_ptr<T>::~shared_ptr()
{
    --count;
    if(!count && !m_ptr)
        delete m_ptr;

}

template <typename T>
void shared_ptr<T>::reset(T* ptr)
{
    T *old_ptr = m_ptr;
    m_ptr = ptr;
    if(old_ptr)
    {
        delete old_ptr;
    }
}

template <typename T>
void shared_ptr<T>::swap(shared_ptr& ob)
{
    T* tmp = m_ptr;
    m_ptr = ob.m_ptr;
    ob.m_ptr = tmp;
    tmp = nullptr;
}

template <typename T>
T* shared_ptr<T>::get()
{
    return m_ptr; 
}

template <typename T>
int shared_ptr<T>::use_count()
{
    return count;
}

template <typename T>
bool shared_ptr<T>::unique()
{
    if(use_count() == 1)
        return true;
    return false;
}

template <typename T>
bool shared_ptr<T>::owner_before(const shared_ptr<T>& ob) const
{
    if(m_ptr == ob.m_ptr)
        return false;
    
    if(m_ptr && sizeof(ob) >= sizeof(*m_ptr))
        return true;
    return false;
}


template <typename T>
shared_ptr<T>::operator bool()
{
    if(get())
        return true;
    return false;
}

template <typename T>
T shared_ptr<T>::operator*()
{
    return *get();
}

template <typename T>
T* shared_ptr<T>::operator->()
{
    return get();
}

template <typename T>
T shared_ptr<T>::operator[](int index)
{
    return get()[index];
}

