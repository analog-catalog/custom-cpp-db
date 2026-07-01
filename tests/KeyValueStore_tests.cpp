#include <gtest/gtest.h>
#include "../header/KeyValueStore.hpp"

TEST(KeyValueStoreTest, StoreTest) {
    KeyValueStore store;
    store.Set("name", "Hugh");
    EXPECT_EQ(store.Get("name"), "Hugh");
}
TEST(KeyValueStoreTest, DeleteTest) {
    KeyValueStore store;
    store.Set("name", "John");
    store.Set("theme", "dark");
    store.Set("language", "cpp");
    store.Set("level", "beginner");
    store.Remove("level");
}
TEST(KeyValueStoreTest, ExistsTest) {
    KeyValueStore store;
    store.Set("name", "John");
    store.Set("city", "Riverside");
    store.Set("university", "UCR");
    EXPECT_TRUE(store.Exists("city"));
    EXPECT_FALSE(store.Exists("major"));
}
