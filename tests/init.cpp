#include <catch.hpp>
#include <test.hpp>

SCENARIO("array init") 
{
	array<int, 13> v1;
	REQUIRE(v1.size() == 13);
	REQUIRE(v1.empty() == false);
	REQUIRE(v1[0]==0);
	array<int, 0> v2;
	REQUIRE(v1.size() == 0);
	REQUIRE(v1.empty() == true);
	array<int, 5> v3{1,5,7,23};
	array<int, 5> v4(v3);
	REQUIRE(v3[0]==v4[0]==1);
	REQUIRE(v3[1]==v4[1]==5);
	REQUIRE(v3[2]==v4[2]==7);
	REQUIRE(v3[3]==v4[3]==23);
}

SCENARIO("array at, back, front, data, operator[]")
{
	array<int, 2> v1{9,12};
	int tmp = v1.at(0);
	REQUIRE(tmp == 9);
	REQUIRE(tmp == v1.front());
	REQUIRE(tmp == *v1.data());
	REQUIRE(tmp == *v1.begin());
	tmp = v1.at(1);
	REQUIRE(tmp == 12);
	REQUIRE(tmp == v1.back());
	REQUIRE(tmp == *(v1.data() + 1));
	REQUIRE(tmp == *v1.end());
	REQUIRE(v1[0] == 9);
	REQUIRE(v1[1] == 12);
}
