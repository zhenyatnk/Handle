#pragma once

#include <handle.hpp>
#include <base_object.hpp>
#include <map>

class ObjectsGlobalStorage
{
public:
    ~ObjectsGlobalStorage()
    {
        for (auto lObject : m_Storage)
            delete lObject.second;
    }

    static ObjectsGlobalStorage& getInstance()
    {
        static ObjectsGlobalStorage lObject;
        return lObject;
    }

    Handle CreateHandle(BaseObject* aObj)
    {
        ++m_LastCreatedHandle;
        m_Storage[m_LastCreatedHandle] = aObj;
        return m_LastCreatedHandle;
    }
    
    BaseObject* GetObject(Handle aHandle)
    {
        if (!!m_Storage.count(aHandle))
            return m_Storage[aHandle];
        return nullptr;
    }

    template<class Type>
    Type* GetObject(Handle aHandle)
    {
        BaseObject* lObj = GetObject(aHandle);
        if (!!lObj)
            return lObj->safe_cast<Type>();
        return nullptr;
    }

    void CloseHandle(Handle aHandle)
    {
        BaseObject* lObject = GetObject(aHandle);
        if (!!lObject)
        {
            m_Storage.erase(aHandle);
            delete lObject;
        }
    }

private:
    ObjectsGlobalStorage()
        :m_LastCreatedHandle(0)
    {}
    ObjectsGlobalStorage(const ObjectsGlobalStorage&) = delete;
    ObjectsGlobalStorage& operator = (const ObjectsGlobalStorage&) = delete;

private:
    Handle m_LastCreatedHandle;
    std::map<Handle, BaseObject*> m_Storage;
};
