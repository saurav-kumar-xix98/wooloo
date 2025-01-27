#include <util/Parser.hpp>
#include <vector>
#include <algorithm>
#include <stdexcept>

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
