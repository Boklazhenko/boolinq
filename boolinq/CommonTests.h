#pragma once

#include <set>

//////////////////////////////////////////////////////////////////////////
// Compare Range with array
//////////////////////////////////////////////////////////////////////////

template<typename R, typename T, int N, typename F>
void CheckRangeEqArray(R dst, T (&ans)[N], F f)
{
    for (int i = 0; i < N; i++)
        EXPECT_EQ(f(ans[i]), f(dst.nextObject()));

    EXPECT_THROW(dst.nextObject(), EnumeratorEndException);
}

template<typename R, typename T, int N>
void CheckRangeEqArray(R dst, T (&ans)[N])
{
    for (int i = 0; i < N; i++)
        EXPECT_EQ(ans[i], dst.nextObject());

    EXPECT_THROW(dst.nextObject(), EnumeratorEndException);
}

template<typename T, int N>
std::set<T> ArrayToSet(T (&ans)[N])
{
    std::set<T> res;
    for(int i = 0; i < N; i++)
        res.insert(ans[i]);

    EXPECT_EQ(N, res.size());

    return res;
}

template<typename R, typename T, int N>
void CheckRangeEqSet(R dst, T (&ans)[N])
{
    std::set<T> expected = ArrayToSet(ans);
    std::set<typename R::value_type> actual = dst.toSet();

    EXPECT_EQ(expected.size(), actual.size());

    std::set<T>::iterator it1 = expected.begin();
    std::set<typename R::value_type>::iterator it2 = actual.begin();
    for(; it1 != expected.end() && it2 != actual.end(); it1++, it2++)
    {
        EXPECT_EQ(*it2, *it1);
    }
}
