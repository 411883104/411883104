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
share_ptr<T>::share_ptr(Args... args) : ptr_(new T(args...)), ref_(new int(0))
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
        delete ref_;
        ref_ = nullptr;
        ptr_ = nullptr;
    }
}

class A
{
public:
    int a, b;
    A(int a, int b) : a(a), b(b) {}
};

template <typename T>
void test(share_ptr<T> ptr)
{
    auto p = ptr;
}

int main()
{
    auto ptr = share_ptr<A>(100, 20);
    auto p = ptr;
    std::cout << (*p).a << std::endl;
}