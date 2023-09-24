//
// Created by bogda on 24.09.2023.
//
#include <iostream>
#include "ListNode.cpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("test list create, add, clear", "[list]"){
    List lst;
    INFO("checking list created empty");
    REQUIRE(lst.Empty() == true);
    lst.PushBack(1);
    lst.PushFront(2);
    lst.PushBack(3);
    CHECK(lst.Size() == 3);
    lst.Clear();
    CHECK(lst.Size() == 0);
    CHECK(lst.Empty() == true);
}

int main()
{
    return Catch::Session().run();
}