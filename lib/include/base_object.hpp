#pragma once

#include <export.hpp>

template<class Type>
class VisualTypeOnCompile;

template <class Type>
int GetEnumObject()
{
    VisualTypeOnCompile<Type> lVar;
    static_assert(sizeof(int) == 0, "Need specailization function GetEnumObject");
}

class BaseObject
{
public:
    template<class T>
    BaseObject(T* aObj)
        :m_Type(GetEnumObject<T>())
    {}

    virtual ~BaseObject()
    {}

    template<class T>
    T* safe_cast()
    {
        if (GetEnumObject<T>() == m_Type)
            return dynamic_cast<T*>(this);
        return nullptr;
    }

private:
    int m_Type;
};