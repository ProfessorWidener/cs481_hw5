// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "../file_system.hpp"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}

TEST(TLBTest, TestsIntests)
{
    write_to_journal(5, "txb43", 2, "IB", 2, "BB", 16, "checkpoint 1,2,3", 6, "TXE150");

    int fd = open("journal.txt", O_RDONLY);
    char* sol = "txb43IBBBcheckpoint 1,2,3TXE150";

    struct stat st;
    stat("journal.txt", &st);
    int size = st.st_size;
    char* file_bytes = (char*)malloc(size*sizeof(char));
    read(fd, file_bytes, size);

    ASSERT_STREQ(file_bytes, sol);
    
}
