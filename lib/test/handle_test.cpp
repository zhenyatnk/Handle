#include <gtest/gtest.h>
#include "handle_object.hpp"


class handle_test
    :public ::testing::Test
{
public:
    void SetUp()
    {
    }

};
//--------------------------------------------------------------------------------------------------------------------------------------
CHandle CreateHandle1(int aVal)
{
    return CHandle(aVal);
}
CHandle CreateHandle2(int aVal)
{
    CHandle lHandle(aVal);
    return lHandle;
}
//--------------------------------------------------------------------------------------------------------------------------------------
TEST_F(handle_test, GetHandle)
{
    CHandle lHandle(10);
    ASSERT_EQ(10, lHandle.GetHandle());
}

TEST_F(handle_test, MoveCtor1)
{
    CHandle lHandle(10);
    CHandle lHandle1(std::move(lHandle));
    ASSERT_EQ(0, lHandle.GetHandle());
    ASSERT_EQ(10, lHandle1.GetHandle());
}

TEST_F(handle_test, MoveCtor2)
{
    CHandle lHandle(CreateHandle1(10));
    ASSERT_EQ(10, lHandle.GetHandle());
}

TEST_F(handle_test, MoveCtor2_2)
{
    CHandle lHandle(std::move(CreateHandle1(10)));
    ASSERT_EQ(10, lHandle.GetHandle());
}

TEST_F(handle_test, MoveCtor3)
{
    CHandle lHandle(CreateHandle2(10));
    ASSERT_EQ(10, lHandle.GetHandle());
}

TEST_F(handle_test, MoveOperator)
{
    CHandle lHandle(10);
    CHandle lHandle1(15);

    lHandle1 = std::move(lHandle);
    ASSERT_EQ(0, lHandle.GetHandle());
    ASSERT_EQ(10, lHandle1.GetHandle());
}
