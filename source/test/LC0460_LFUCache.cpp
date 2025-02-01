#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0460_LFUCache.hpp>

void testLC0460(const std::string &input1, const std::string& input2, const std::string output) {
    const auto commands = Util::Parser::parse<std::vector<std::string>>(input1);
    const auto arguments = Util::Parser::parse<std::vector<std::vector<int>>>(input2);
    const auto expectedResults = Util::Parser::parse<std::vector<std::string>>(output);

    ASSERT_TRUE(commands.size() > 0);
    ASSERT_EQ(commands.size(), arguments.size());
    ASSERT_EQ(commands.size(), expectedResults.size());
    ASSERT_EQ(commands[0], "LFUCache");
    ASSERT_EQ(arguments[0].size(), 1);

    const auto capacity = arguments[0][0];
    LC0460::LFUCache cache(capacity);

    for (int i = 1; i < commands.size(); i++) {
        const auto &command = commands[i];
        const auto &argument = arguments[i];
        const auto &expectedResult = expectedResults[i];
        if (command == "put") {
            ASSERT_EQ(argument.size(), 2);
            const auto key = argument[0];
            const auto value = argument[1];
            cache.put(key, value);
        } else if (command == "get") {
            ASSERT_EQ(argument.size(), 1);
            const auto key = argument[0];
            const auto result = cache.get(key);
            ASSERT_EQ(std::stoi(expectedResult), result);
        } else {
            throw std::runtime_error("Expected command to be to 'get' or 'put'");
        }
    }
}

TEST(LC0460_LFUCache, TEST_1) {
    const std::string input1 = "[LFUCache,put,put,get,put,get,get,put,get,get,get]";
    const std::string input2 = "[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]";
    const std::string output = "[null,null,null,1,null,-1,3,null,-1,3,4]";

    testLC0460(input1, input2, output);
}
