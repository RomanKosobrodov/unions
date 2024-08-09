#include <catch2/catch_test_macros.hpp>
#include <variant.hpp>

TEST_CASE("visitor function can modify variant")
{
    v::shape x = v::circle{.radius = 1.0f};
    REQUIRE(std::get<v::circle>(x).radius == 1.0f);
    std::visit([](auto &arg)
               {  using T = std::decay_t<decltype(arg)>; 
                if constexpr(std::is_same_v<T, v::circle>)
                {
                    arg.radius *= 2;
                } },
               x);
    REQUIRE(std::get<v::circle>(x).radius == 1.0f * 2);
}