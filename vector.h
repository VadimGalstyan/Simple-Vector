#ifndef __VECTOR__
#define __VECTOR__

#include <iostream>

template <typename T>
class Vector
{
    
public:
    Vector();
    Vector(const int& size);
    Vector(const Vector<T>& obj);
    ~Vector();
    Vector<T>& operator=(const Vector<T>& obj);
    Vector(Vector<T>&& obj) noexcept;
    Vector<T>& operator=(Vector<T>&& obj) noexcept;
    T& operator [](const int& index);

    void push_back(const T& value);
    void pop_back();
    void swap(Vector<T>& obj);
    void clear();
    void print() const;

    int size() const;
    int capacity() const;

    bool empty() const;

private:
    int m_size = 0;
    int m_capacity = 0;
    T* ptr = nullptr;

};

#endif //__VECTOR__

template <typename T> Vector<T>::Vector() : m_size(0),m_capacity(1),ptr(new T[m_capacity])
{
}

template <typename T> Vector<T>::Vector(const int& size) :  m_size(size),m_capacity(2 * size + 1),ptr(new T[m_capacity])
{
}

template <typename T> Vector<T>::Vector(const Vector<T>& obj) : m_size(obj.m_size),m_capacity(obj.m_capacity),ptr(new T[m_capacity])
{
    for (size_t i = 0; i < m_size; ++i)
    {
        ptr[i] = obj.ptr[i];
    }
    
}

template <typename T> Vector<T>& Vector<T>::operator=(const Vector<T>& obj)
{
    if (this != &obj)
    {
        delete[] ptr;

        m_size = obj.m_size;
        m_capacity = obj.m_capacity;

        ptr = new T[m_capacity];

        for (size_t i = 0; i < m_size; ++i)
        {
            ptr[i] = obj.ptr[i];
        }
        
    }

    return *this;
    
}

template <typename T> Vector<T>::~Vector()
{
    delete[] ptr;
    ptr = nullptr;
}

template <typename T> Vector<T>::Vector(Vector<T>&& obj) noexcept : m_size(obj.m_size),m_capacity(obj.m_capacity),ptr(obj.ptr)
{
    obj.m_size = 0;
    obj.m_capacity = 0;
    obj.ptr = nullptr;
}

template <typename T> Vector<T>& Vector<T>::operator=(Vector<T>&& obj) noexcept
{
    if (this != *obj)
    {
        delete[] ptr;

        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        ptr = obj.ptr;

        obj.m_size = 0;
        obj.m_capacity = 0;
        obj.ptr = nullptr;
    }
    
    return *this;
}

template <typename T> T& Vector<T>::operator [](const int& index)
{
    if (index >= 0 && index < m_size)
    {
        return ptr[index];
    }
    
}

template <typename T> void Vector<T>::push_back(const T& value)
{
    if (m_size == m_capacity)
    {
        m_capacity = m_size * 2 + 1;
        T* temp = new T[m_capacity];

        for (size_t i = 0; i < m_size; ++i)
        {
            temp[i] = ptr[i];
        }

        temp[m_size] = value;
        ++m_size;

        delete[] ptr;

        ptr = temp;
        temp = nullptr;
    }
    else
    {
        ptr[m_size] = value;
        ++m_size;
    }
    
}

template <typename T> void Vector<T>::pop_back()
{
    if(m_size > 0)
    {
        --m_size;
    }
}

template <typename T> void Vector<T>::swap(Vector<T>& obj)
{
    T* tmp = ptr;
    int size = m_size;
    int cap = m_capacity;

    ptr = obj.ptr;
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;

    obj.ptr = tmp;
    obj.m_size = size;
    obj.m_capacity = cap;

    tmp = nullptr;
}



template <typename T> void Vector<T>::print() const
{
    for (size_t i = 0; i < m_size; ++i)
    {
        std::cout<<ptr[i]<<" ";
    }
    
}


template <typename T> void Vector<T>::clear()
{
    if (m_capacity > 1)
    {
        delete[] ptr;
        m_size = 0;
        m_capacity = 1;

        ptr = new T[m_capacity];
    }
    
    m_size = 0;
}

template <typename T> int Vector<T>::size() const
{
    return m_size;
}

template <typename T> int Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T> bool Vector<T>::empty() const
{
    return m_size == 0;
}