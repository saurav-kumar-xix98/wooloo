#include <util/Parser.hpp>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <datatype/ListNode.hpp>

std::vector<std::string> splitWords(const std::string_view &str, const std::string &delimiter) {
    std::vector<std::string> words;
    size_t start = 0;

    while (start < str.size()) {
        size_t end = str.find(delimiter, start);
        if (end == std::string_view::npos)
            end = str.size();

        words.emplace_back(str.substr(start, end - start));
        start = end + delimiter.size();
    }

    return words;
}

template<>
std::vector<std::string> Util::Parser::parse(const std::string &str) {
    if (str == "[]")
        return {};
    
    if (str.size() < 2)
        throw std::invalid_argument("Not enough bytes provided: " + str);

    if (str.front() != '[' || str.back() != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    return splitWords(std::string_view(str.data() + 1, str.size() - 2), ",");
}

template<>
std::vector<std::vector<std::string>> Util::Parser::parse(const std::string &str) {
    if (str == "[]")
        return {};
    
    const size_t size = str.size();

    if (size < 4 || str[0] != '[' || str[size - 1] != ']' || str[1] != '[' || str[size - 2] != ']')
        throw std::invalid_argument("Invalid Input: " + str);

    const auto lines = splitWords(std::string_view(str.data() + 2, size - 4), "],[");

    std::vector<std::vector<std::string>> stringMatrix(lines.size());
    for (size_t i = 0; i < lines.size(); ++i)
        stringMatrix[i] = splitWords(lines[i], ",");
    return stringMatrix;
}

template<>
std::vector<int> Util::Parser::parse(const std::string &str) {
    const auto words = parse<std::vector<std::string>>(str);

    std::vector<int> result(words.size());
    for (size_t i = 0; i < words.size(); ++i)
        result[i] = std::stoi(words[i]);
    return result;
}

template<>
std::vector<std::vector<int>> Util::Parser::parse(const std::string &str) {
    const auto stringMatrix = parse<std::vector<std::vector<std::string> > >(str);

    std::vector<std::vector<int>> intMatrix(stringMatrix.size());
    for (size_t r = 0; r < stringMatrix.size(); ++r) {
        intMatrix[r] = std::vector<int>(stringMatrix[r].size());
        for (size_t c = 0; c < stringMatrix[r].size(); ++c)
            intMatrix[r][c] = std::stoi(stringMatrix[r][c]);
    }

    return intMatrix;
}

template<>
std::vector<std::vector<char>> Util::Parser::parse(const std::string &str) {
    const auto stringMatrix = parse<std::vector<std::vector<std::string>>>(str);

    std::vector<std::vector<char>> charMatrix(stringMatrix.size());
    for (size_t r = 0; r < stringMatrix.size(); ++r) {
        charMatrix[r] = std::vector<char>(stringMatrix[r].size());
        for (size_t c = 0; c < stringMatrix[r].size(); ++c)
            charMatrix[r][c] = stringMatrix[r][c][0];
    }

    return charMatrix;
}

Datatype::ListNode* listNodeFromIntVector(const std::vector<int> &vec) {
    Datatype::ListNode dummyHead;
    Datatype::ListNode *tail = &dummyHead;
    for (auto x : vec) {
        tail->next = new Datatype::ListNode(x);
        tail = tail->next;
    }
    return dummyHead.next;
}

template<>
Datatype::ListNode* Util::Parser::parse(const std::string &str) {
    const auto intVector = parse<std::vector<int>>(str);
    return listNodeFromIntVector(intVector);
}

template<>
std::vector<Datatype::ListNode*> Util::Parser::parse(const std::string &str) {
    const auto intMatrix = parse<std::vector<std::vector<int>>>(str);

    std::vector<Datatype::ListNode*> result(intMatrix.size());
    std::ranges::transform(intMatrix, result.begin(), [](const auto &intVector) {
        return listNodeFromIntVector(intVector);
    });
    return result;
}
