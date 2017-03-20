
#include "object_global_storage.hpp"
#include "base_object.hpp"
#include "handle.hpp"

void Handle_CloseHandle(Handle aHandle)
{
    ObjectsGlobalStorage::getInstance().CloseHandle(aHandle);
}