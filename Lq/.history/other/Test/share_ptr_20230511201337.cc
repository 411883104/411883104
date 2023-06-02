#include <iostream>

template <class T>
class share_ptr
{
private:
    int ref_{0};
    T* ptr_;

public:
    share_ptr(T*);
};