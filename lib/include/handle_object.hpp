#pragma once

#include <handle.hpp>

class CHandle
{
public:
    explicit CHandle(Handle aHandle);
    virtual ~CHandle();

    CHandle(CHandle&& aCHandle);
    CHandle& operator =(CHandle && aCHandle);

    CHandle(const CHandle&) = delete;
    CHandle& operator =(const CHandle&) = delete;

    Handle GetHandle();
private:
    Handle m_Handle;

};
