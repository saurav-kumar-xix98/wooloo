#include <library/LC3260_FindTheLargestPalindromeDivisibleByK.hpp>
#include <array>

namespace LC3260 {
    std::string largestPalindrome1(int n) {
        return std::string(n, '9');
    }

    std::string largestPalindrome2(int n) {
        std::string out = std::string(n, '9');
        out[0] = '8';
        out[n - 1] = '8';
        return out;
    }

    std::string largestPalindrome3(int n) {
        return std::string(n, '9');
    }

    std::string largestPalindrome4(int n) {
        std::string out = std::string(n, '9');
        out[0] = '8';
        out[n - 1] = '8';
        if (n > 1) {
            out[1] = '8';
            out[n - 2] = '8';
        }
        return out;
    }

    std::string largestPalindrome5(int n) {
        std::string out = std::string(n, '9');
        out[0] = '5';
        out[n - 1] = '5';
        return out;
    }

    std::string largestPalindrome6(int n) {
        if (n <= 2)
            return std::string(n, '6');

        std::string out = std::string(n, '9');
        out[0] = '8';
        out[n - 1] = '8';
        if (n % 2 == 0) {
            out[n / 2 - 1] = '7';
            out[n / 2] = '7';
        } else {
            out[n / 2] = '8';
        }
        return out;
    }

    std::string largestPalindrome7(int n) {
        if (n <= 2)
            return std::string(n, '7');

        const static std::array<int, 6> lookupArray = {{1, 3, 2, 6, 4, 5}};
        const static std::array<std::array<char, 6>, 7> lookupMatrix = {{
            {{'7', '7', '7', '7', '7', '7'}},
            {{'8', '4', '5', '9', '3', '6'}},
            {{'9', '8', '3', '4', '6', '5'}},
            {{'3', '5', '8', '6', '9', '4'}},
            {{'4', '9', '6', '8', '5', '3'}},
            {{'5', '6', '4', '3', '8', '9'}},
            {{'6', '3', '9', '5', '4', '8'}}
        }};



        std::string out = std::string(n, '9');

        int l = (n - 1) / 2;
        int mod999 = (lookupArray[l % 6] + 6) % 7;
        if (n % 2 == 1) {
            int mod101 = (lookupArray[(l + 1) % 6] + 1) % 7;
            int modReq = (7 - (mod999 * mod101) % 7) % 7;
            int coeffD = lookupArray[l % 6];
            out[n / 2] = lookupMatrix[modReq][coeffD - 1];
        } else {
            int mod101 = (lookupArray[(l + 2) % 6] + 1) % 7;
            int modReq = (7 - (mod999 * mod101) % 7) % 7;
            int coeffD = (lookupArray[l % 6] * 11) % 7;
            out[n / 2 - 1] = lookupMatrix[modReq][coeffD - 1];
            out[n / 2] = lookupMatrix[modReq][coeffD - 1];
        }

        return out;
    }

    std::string largestPalindrome8(int n) {
        std::string out = std::string(n, '9');
        out[0] = '8';
        out[n - 1] = '8';
        if (n > 1) {
            out[1] = '8';
            out[n - 2] = '8';
            if (n > 2) {
                out[2] = '8';
                out[n - 3] = '8';
            }
        }
        return out;
    }

    std::string largestPalindrome9(int n) {
        return std::string(n, '9');
    }
};

std::string LC3260::largestPalindrome(int n, int k) {
    if (n == 0)
        return "";

    switch (k) {
        case 1: return largestPalindrome1(n);
        case 2: return largestPalindrome2(n);
        case 3: return largestPalindrome3(n);
        case 4: return largestPalindrome4(n);
        case 5: return largestPalindrome5(n);
        case 6: return largestPalindrome6(n);
        case 7: return largestPalindrome7(n);
        case 8: return largestPalindrome8(n);
        case 9: return largestPalindrome9(n);
    }

    return "";
}
