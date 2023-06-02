#include <iostream>

template <class T>
class share_ptr
{
private:
    int* ref_;
    T* ptr_;

public:
    share_ptr(T*);
    template <typename... Args>
    share_ptr(Args... args);
    share_ptr(share_ptr& _ptr);
    share_ptr(share_ptr&& _ptr);

    T& operator*();

    ~share_ptr();
};
template <class T>
T& share_ptr<T>::operator*()
{
    return *ptr_;
}
template <class T>
template <typename... Args>
share_ptr<T>::share_ptr(Args... args) : ptr_(new T(args...))
{
}

template <class T>
share_ptr<T>::share_ptr(T* ptr) : ptr_(ptr), ref_(new int(0))
{
}
template <class T>
share_ptr<T>::share_ptr(share_ptr<T>& _ptr)
{
    ref_ = _ptr.ref_;
    ptr_ = _ptr.ptr_;
    ++(*ref_);
}
template <class T>
share_ptr<T>::share_ptr(share_ptr&& _ptr)
{
    ref_ = std::move(_ptr.ref_);
    ptr_ = std::move(_ptr.ptr_);
}

template <class T>
share_ptr<T>::~share_ptr()
{
    if (--(*ref_) == 0)
    {
        delete ptr_;
        ptr_ = nullptr;
    }
}

int main()
{
    auto ptr = share_ptr<int>(1);
    *ptr = 9;
    auto p = ptr;
    *p = 12;
    std::cout << *ptr << std::endl;
}