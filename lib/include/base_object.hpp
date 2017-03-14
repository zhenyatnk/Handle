#pragma once

class Object1;

enum class ETypeObject
{
    eObject1 = 1
};

template <class Type>
int GetEnumObject()
{
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