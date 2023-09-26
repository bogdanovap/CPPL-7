//
// Created by bogda on 24.09.2023.
//
#include <iostream>
#include "ListNode.cpp"
#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"

TEST_CASE("test list", "[list]"){
    List lst;
    SECTION("simple test of add and pop functions"){
        REQUIRE(lst.Empty() == true);
        lst.PushBack(1);
        CHECK(lst[lst.Size()-1] == 1);
        lst.PushFront(2);
        lst.Clear();
        REQUIRE(lst.Empty() == true);
        std::string error_msg = "list is empty";
        CHECK_THROWS(lst.PopBack(), error_msg);
        CHECK_THROWS(lst.PopFront(), error_msg);
    };
    SECTION("multiple add and pop operations with empty list") {
        REQUIRE(lst.Empty() == true);
        lst.PushBack(1);
        lst.PushFront(2);
        INFO("PopBack returns value of last node");
        CHECK(lst.PopBack() == 1);
        INFO("first node is now - last (only node)");
        CHECK(lst.PopBack() == 2);
        lst.PushFront(3);
        INFO("PopFront returns value of first node");
        CHECK(lst.PopFront() == 3);
        INFO("list must be empty at this stage");
        CHECK(lst.Empty() == true);
        std::string error_msg = "list is empty";
        CHECK_THROWS(lst.PopBack(), error_msg);
        CHECK_THROWS(lst.PopFront(), error_msg);
    }
}

TEST_CASE("test list multiple actions", "[list]"){
    List lst;
}


int main()
{
    return Catch::Session().run();
}