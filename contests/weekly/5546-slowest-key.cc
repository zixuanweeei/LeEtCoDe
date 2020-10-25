#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  char slowestKey(vector<int> &releaseTime, string keysPressed) {
    size_t max_duration = 0;
    char slowest_key = keysPressed[0];
    size_t last_release_time = releaseTime[0];
    unordered_map<char, size_t> key_dur_map;
    key_dur_map[slowest_key] = last_release_time;
    for (size_t i = 1; i < releaseTime.size(); ++i) {
      size_t current_dur = releaseTime[i] - last_release_time;
      char cur_key = keysPressed[i];
      if (key_dur_map.count(cur_key)) {
        key_dur_map[cur_key] = key_dur_map[cur_key] > current_dur
                                   ? key_dur_map[cur_key]
                                   : current_dur;
      } else
        key_dur_map[cur_key] = current_dur;
      last_release_time = releaseTime[i];
    }
    const string alpbet = "abcdefghijklmnopqrstuvwxyz";
    for (auto c : alpbet) {
      if (key_dur_map.count(c)) {
        if (key_dur_map[c] >= max_duration) {
          slowest_key = c;
          max_duration = key_dur_map[c];
        }
      }
    }
    return slowest_key;
  }
};
