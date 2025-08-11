class Solution {
public:
  bool static comparator(pair<int, int> a, pair<int, int> b) {
    int diffA = a.second - a.first;
    int diffB = b.second - b.first;

    return diffA > diffB ? false : true;
  }

  int maxMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int, int>> sortedMeetings;
    for (int i = 0; i < start.size(); i++) {
      sortedMeetings.push_back({start[i], end[i]});
    }

    sort(sortedMeetings.begin(), sortedMeetings.end(), comparator);
  }
};
