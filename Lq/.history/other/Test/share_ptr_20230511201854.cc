#include <iostream>

template <class T>
class share_ptr
{
private:
    int* ref_;
    T* ptr_;

public:
    share_ptr(T*);
    share_ptr(share_ptr& _ptr);
    share_ptr(share_ptr&& _ptr);
};

template <class T>
share_ptr<T>::share_ptr(T* ptr) : ptr_(ptr)
{
}
template <class T>
share_ptr<T>::share_ptr(share_ptr<T>& _ptr)
{
    ref_ = ++_ptr.ref_;
    ptr_ = _ptr.ptr_;
}
template <class T>
share_ptr<T>::share_ptr(share_ptr&& _ptr)
{
    ref_ = std::move(ptr_)
}
