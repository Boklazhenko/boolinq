#include <list>
#include <vector>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "boolinq.h"

using namespace boolinq;

TEST(Avg, ThreeInts)
{
    std::vector<int> src;
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);

    auto rng = from(src);

    EXPECT_EQ(2, rng.avg<double>());
}

TEST(Avg, FiveInts)
{
    std::vector<int> src;
    src.push_back(1);
    src.push_back(2);
    src.push_back(3);
    src.push_back(4);
    src.push_back(5);

    auto rng = from(src);
    auto dst0 = rng.where([](int a){return a%2 == 0;});
    auto dst1 = rng.where([](int a){return a%2 == 1;});

    EXPECT_EQ(3, dst0.avg<double>());
    EXPECT_EQ(3, dst1.avg<double>());
}

TEST(Avg, FiveStringsLen)
{
    std::vector<std::string> src;
    src.push_back("hello");
    src.push_back("apple");
    src.push_back("nokia");
    src.push_back("oracle");
    src.push_back("ponny");

    auto rng = from(src);

    EXPECT_EQ(5, rng.avg<int>([](const std::string & str){return str.size();}));
}
