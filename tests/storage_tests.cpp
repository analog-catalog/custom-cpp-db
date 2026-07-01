#include <gtest/gtest.h>
#include <cstdio>
#include "../header/Storage.hpp"
#include "../header/KeyValueStore.hpp"

TEST(StorageTest, StorageSaveTest) {
    KeyValueStore store;
    store.Set("name", "John");
    store.Set("city", "Riverside");
    FileStorage storage("test.txt");
    bool savedData = storage.Save(store.GetData());
    std::ifstream file("test.txt");
    ASSERT_TRUE(file.is_open());
    std::ostringstream testOutput;
    testOutput << file.rdbuf();
    EXPECT_EQ(testOutput.str(),
                "city=Riverside\n"
                "name=John\n");
    EXPECT_TRUE(savedData);
    file.close();
    std::remove("test.txt");
}
TEST(StorageTest, StorageLoadTest) {
    KeyValueStore store;
    {
        std::ofstream file("test.txt");
        ASSERT_TRUE(file.is_open());
        file << "name=John\n" << "city=Riverside\n";
    }

    FileStorage storage("test.txt");
    bool loadData = storage.Load();
    EXPECT_TRUE(loadData);
    EXPECT_TRUE(storage.GetData().contains("name"));
    EXPECT_TRUE(storage.GetData().contains("city"));
    std::remove("test.txt");
}

