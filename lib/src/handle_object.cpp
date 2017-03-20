
#include <handle_object.hpp>

CHandle::CHandle(Handle aHandle)
    :m_Handle(aHandle)
{}

CHandle::~CHandle()
{
    if (m_Handle != HANDLE_UNUSED)
        Handle_CloseHandle(m_Handle);
}

CHandle::CHandle(CHandle&& aCHandle)
{
    m_Handle = aCHandle.m_Handle;
    aCHandle.m_Handle = HANDLE_UNUSED;
}

CHandle& CHandle::operator =(CHandle && aCHandle)
{
    m_Handle = aCHandle.m_Handle;
    aCHandle.m_Handle = HANDLE_UNUSED;
    return *this;
}

Handle CHandle::GetHandle()
{
    return m_Handle;
}