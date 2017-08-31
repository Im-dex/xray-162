#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv) {
    //testing::GTEST_FLAG(catch_exceptions) = 0;
    //testing::GTEST_FLAG(filter) = "TestCase.Test";
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}