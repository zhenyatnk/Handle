#include <gtest/gtest.h>
#include "object_global_storage.hpp"
#include "base_object.hpp"

//--------------------------------------------------------------------------------------------------------------------------------------
class TestClass;

template <>
int GetEnumObject<TestClass>()
{
    return 2;
}

class TestClass
    :public BaseObject
{
public:
    TestClass(int aValue)
        :BaseObject(this), m_Value(aValue)
    {}

public:
    int GetValue()
    {
        return m_Value;
    }
private:
    int m_Value;
};

class ogs_test
    :public ::testing::Test
{
public:
    void SetUp()
    {
    }

};

//--------------------------------------------------------------------------------------------------------------------------------------
TEST_F(ogs_test, first_sample)
{
    Handle lC = ObjectsGlobalStorage::getInstance().CreateHandle(new TestClass(15));
    ASSERT_EQ(ObjectsGlobalStorage::getInstance().GetObject<TestClass>(lC)->GetValue(), 15);
}