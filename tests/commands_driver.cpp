#include <gtest/gtest.h>
#include <cstdio>
#include <fstream>
#include "../header/KeyValueStore.hpp"
#include "../header/Commands.hpp"

TEST(CommandsTest, SetCommandTest) {
    KeyValueStore store;
    std::ostringstream testOutput;
    SetCommand setCommand("name", "Alice");
    setCommand.Execute(store, testOutput);
    std::string result = testOutput.str();
    EXPECT_TRUE(store.GetData().contains("name"));
    EXPECT_EQ(store.Get("name"), "Alice");
    EXPECT_EQ(result, "OK\n");
}
TEST(CommandsTest, GetCommandTest) {
    KeyValueStore store;
    store.Set("name", "Alice");
    std::ostringstream testOutput;
    GetCommand getCommand("name");
    getCommand.Execute(store, testOutput);
    std::string result = testOutput.str();
    EXPECT_EQ(result, "Alice\n");
}
TEST(CommandsTest, ExistsCommandTrueTest) {
    KeyValueStore store;
    store.Set("name", "Alice");
    std::ostringstream testOutput;
    ExistsCommand existsCommand("name");
    existsCommand.Execute(store, testOutput);
    EXPECT_EQ(testOutput.str(), "true\n");
}
TEST(CommandsTest, ExistsCommandFalseTest) {
    KeyValueStore store;
    store.Set("name", "Alice");
    std::ostringstream testOutput;
    ExistsCommand existsCommand("age");
    existsCommand.Execute(store, testOutput);
    EXPECT_EQ(testOutput.str(), "false\n");
}
TEST(CommandsTest, RemoveExistCommandTest) {
    KeyValueStore store;
    store.Set("name", "Alice");
    store.Set("age", "19");
    store.Set("city", "Riverside");
    EXPECT_TRUE(store.Exists("age"));
    std::ostringstream testOutput;
    RemoveCommand removeCommand("age");
    removeCommand.Execute(store, testOutput);
    EXPECT_FALSE(store.Exists("age"));
    EXPECT_EQ(testOutput.str(), "Deleted\n");
}
TEST(CommandsTest, RemoveNotExistCommandTest) {
    KeyValueStore store;
    store.Set("name", "Alice");
    store.Set("age", "19");
    store.Set("city", "Riverside");
    EXPECT_FALSE(store.Exists("job"));
    std::ostringstream testOutput;
    RemoveCommand removeCommand("job");
    removeCommand.Execute(store, testOutput);
    EXPECT_FALSE(store.Exists("job"));
    EXPECT_EQ(testOutput.str(), "Key not found\n");
}
TEST(CommandsTest, ListCommandEmptyTest) {
    KeyValueStore store;
    std::ostringstream testOutput;
    ListCommand listCommand;
    listCommand.Execute(store, testOutput);
    EXPECT_EQ(testOutput.str(), "Empty\n");
}
TEST(CommandsTest, ListCommandTest) {
    KeyValueStore store;
    store.Set("name", "Alice");
    store.Set("age", "19");
    store.Set("city", "Riverside");
    std::ostringstream testOutput;
    ListCommand listCommand;
    listCommand.Execute(store, testOutput);
    EXPECT_EQ(testOutput.str(), "age = 19\ncity = Riverside\nname = Alice\n");
}
TEST(CommandsTest, SaveCommandTest) {
    KeyValueStore store;
    store.Set("name", "John");
    std::ostringstream testOutput;
    FileStorage storage("test.txt");
    SaveCommand saveCommand(storage);
    saveCommand.Execute(store, testOutput);
    EXPECT_EQ(testOutput.str(), "Saved successfully\n");
}
TEST(CommandsTest, LoadCommandTest) {
    const std::string filename = "commands_load_test.txt";

    {
        std::ofstream file(filename);
        ASSERT_TRUE(file.is_open());
        file << "name=Alice\n";
        file << "age=19\n";
        file << "city=Riverside\n";
    }

    KeyValueStore store;
    FileStorage storage(filename);
    std::ostringstream testOutput;
    LoadCommand loadCommand(storage);
    loadCommand.Execute(store, testOutput);

    EXPECT_EQ(testOutput.str(), "Loaded successfully\n");
    EXPECT_EQ(store.Get("name"), "Alice");
    EXPECT_EQ(store.Get("age"), "19");
    EXPECT_EQ(store.Get("city"), "Riverside");
    std::remove(filename.c_str());
}
