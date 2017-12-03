#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <imdexlib/option.hpp>

using namespace imdex;
using namespace testing;

struct test_exception : std::exception {
    test_exception() noexcept
        : exception("Test exception")
    {}
};

struct complex_constructible final {
    complex_constructible(const int a, const double b) noexcept
        : a(a),
          b(b)
    {}

    bool operator== (const complex_constructible& that) const noexcept {
        return (a == that.a) && (b == that.b);
    }

    int a;
    double b;
};

struct OptionTest : Test {
    int value = 1;
    int secondValue = 10;
};

struct OptionValueTest : OptionTest {};
struct OptionRefTest : OptionTest {};

using OptVal = option<int>;
using OptRef = option<int&>;

TEST_F(OptionValueTest, ConstructorTest) {
    EXPECT_THAT(OptVal(), IsEmpty());
    EXPECT_EQ(OptVal(), none());

    EXPECT_THAT(OptVal(value), Not(IsEmpty()));
    EXPECT_EQ(OptVal(value), value);
    EXPECT_EQ(some(value), value);

    EXPECT_EQ(option<complex_constructible>(in_place(), 0, .0), complex_constructible(0, .0));
    EXPECT_EQ(make_option<complex_constructible>(0, .0), complex_constructible(0, .0));
}

TEST_F(OptionRefTest, ConstructorTest) {
    EXPECT_THAT(OptRef(), IsEmpty());
    EXPECT_EQ(OptRef(), none());

    EXPECT_THAT(OptRef(std::ref(value)), Not(IsEmpty()));
    EXPECT_EQ(std::addressof(OptRef(std::ref(value)).get()), std::addressof(value));
    EXPECT_EQ(std::addressof(some(std::ref(value)).get()), std::addressof(value));
}

TEST_F(OptionValueTest, AssignmentTest) {
    OptVal opt;

    opt = some(value);
    EXPECT_EQ(opt, value);

    int number = 0;
    opt = number;
    EXPECT_EQ(opt, number);

    opt = none();
    EXPECT_THAT(opt, IsEmpty());
}

TEST_F(OptionRefTest, AssignmentTest) {
    OptRef opt;

    opt = std::ref(value);
    EXPECT_EQ(std::addressof(opt.get()), std::addressof(value));

    opt = some(std::ref(value));
    EXPECT_EQ(std::addressof(opt.get()), std::addressof(value));

    int number = 0;
    opt = std::ref(number);
    EXPECT_EQ(std::addressof(opt.get()), std::addressof(number));

    opt = none();
    EXPECT_THAT(opt, IsEmpty());
}

TEST_F(OptionValueTest, EmplaceTest) {
    OptVal opt;
    opt.emplace(value);
    EXPECT_EQ(opt, value);
}

TEST_F(OptionValueTest, SizeTest) {
    OptVal empty;
    OptVal nonEmpty(value);

    EXPECT_EQ(empty.size(), 0);
    EXPECT_THAT(empty, IsEmpty());
    EXPECT_FALSE(empty.non_empty());

    EXPECT_EQ(nonEmpty.size(), 1);
    EXPECT_THAT(nonEmpty, Not(IsEmpty()));
    EXPECT_TRUE(nonEmpty.non_empty());
}

TEST_F(OptionRefTest, SizeTest) {
    OptRef empty;
    OptRef nonEmpty(value);

    EXPECT_EQ(empty.size(), 0);
    EXPECT_THAT(empty, IsEmpty());
    EXPECT_FALSE(empty.non_empty());

    EXPECT_EQ(nonEmpty.size(), 1);
    EXPECT_THAT(nonEmpty, Not(IsEmpty()));
    EXPECT_TRUE(nonEmpty.non_empty());
}

TEST_F(OptionValueTest, GetTest) {
    OptVal empty;
    OptVal nonEmpty(value);

    EXPECT_EQ(nonEmpty.get(), value);
    EXPECT_EQ(nonEmpty.get_or_else(secondValue), value);
    EXPECT_EQ(empty.get_or_else(secondValue), secondValue);

    EXPECT_EQ(nonEmpty.get_or_throw<test_exception>(), value);
    EXPECT_EQ(nonEmpty.get_or_throw(test_exception()), value);

#ifdef DEBUG
    EXPECT_DEATH(empty.get(), ".*");
#endif
    EXPECT_THROW(empty.get_or_throw<test_exception>(), test_exception);
    EXPECT_THROW(empty.get_or_throw(test_exception()), test_exception);
}

TEST_F(OptionRefTest, GetTest) {
    OptRef empty;
    OptRef nonEmpty(std::ref(value));

    EXPECT_EQ(std::addressof(nonEmpty.get()), std::addressof(value));
    EXPECT_EQ(std::addressof(nonEmpty.get_or_else(std::ref(secondValue))), std::addressof(value));
    EXPECT_EQ(std::addressof(empty.get_or_else(std::ref(secondValue))), std::addressof(secondValue));

    EXPECT_EQ(std::addressof(nonEmpty.get_or_throw<test_exception>()), std::addressof(value));
    EXPECT_EQ(std::addressof(nonEmpty.get_or_throw(test_exception())), std::addressof(value));

#ifdef DEBUG
    EXPECT_DEATH(empty.get(), ".*");
#endif
    EXPECT_THROW(empty.get_or_throw<test_exception>(), test_exception);
    EXPECT_THROW(empty.get_or_throw(test_exception()), test_exception);
}

TEST_F(OptionValueTest, SwapTest) {
    using std::swap;

    OptVal first(value);
    OptVal second(secondValue);

    swap(first, second);
    EXPECT_EQ(first, secondValue);
    EXPECT_EQ(second, value);

    int someValue = 4;
    swap(first, someValue);
    EXPECT_EQ(first, 4);
    EXPECT_EQ(someValue, secondValue);
}

TEST_F(OptionRefTest, SwapTest) {
    using std::swap;

    OptRef first(std::ref(value));
    OptRef second(std::ref(secondValue));

    swap(first, second);
    EXPECT_EQ(std::addressof(first.get()), std::addressof(secondValue));
    EXPECT_EQ(std::addressof(second.get()), std::addressof(value));
}

TEST_F(OptionValueTest, HashTest) {
    std::hash<OptVal> hasher;
    OptVal empty;
    OptVal nonEmpty(value);

    EXPECT_EQ(hasher(empty), 0);

    std::hash<int> valueHasher;
    EXPECT_EQ(hasher(nonEmpty), valueHasher(value));
}

TEST_F(OptionRefTest, HashTest) {
    std::hash<OptRef> hasher;
    OptRef empty;
    OptRef nonEmpty(std::ref(value));

    EXPECT_EQ(hasher(empty), 0);

    std::hash<int*> valueHasher;
    EXPECT_EQ(hasher(nonEmpty), valueHasher(std::addressof(value)));
}
