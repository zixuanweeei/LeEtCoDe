#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int ret = 0;
    unordered_map<string, int> roman_int;
    roman_int["M"] = 1000;
    roman_int["CM"] = 900;
    roman_int["D"] = 500;
    roman_int["CD"] = 400;
    roman_int["C"] = 100;
    roman_int["XC"] = 90;
    roman_int["L"] = 50;
    roman_int["XL"] = 40;
    roman_int["X"] = 10;
    roman_int["IX"] = 9;
    roman_int["V"] = 5;
    roman_int["IV"] = 4;
    roman_int["I"] = 1;

    size_t len = s.size();
    for (size_t i = 0; i < len;) {
      if (i + 1 < len && roman_int.count(s.substr(i, 2))) {
        ret += roman_int[s.substr(i, 2)];
        i += 2;
      } else {
        ret += roman_int[s.substr(i, 1)];
        i += 1;
      }
    }
    return ret;
  }
};
