#include <gtest/gtest.h>
#include "../header/Parser.hpp"

TEST(ParserTest, ParsesSetCommand) {
    Parser parser;
    auto command = parser.parse("SET name Alice");
    ASSERT_NE(command, nullptr);
    auto* setCommand = dynamic_cast<SetCommand*>(command.get());
    EXPECT_NE(setCommand, nullptr);
}

TEST(ParserTest, ParsesGetCommand) {
    Parser parser;
    auto command = parser.parse("GET name");
    ASSERT_NE(command, nullptr);
    auto* getCommand = dynamic_cast<GetCommand*>(command.get());
    EXPECT_NE(getCommand, nullptr);
}

TEST(ParserTest, ThrowsForUnknownCommand) {
    Parser parser;
    EXPECT_THROW(parser.parse("BOOP name Alice"), std::runtime_error);
}