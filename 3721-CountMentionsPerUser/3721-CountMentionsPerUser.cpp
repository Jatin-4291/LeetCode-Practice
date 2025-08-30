// Last updated: 8/30/2025, 1:21:56 PM
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0); // To store the count of mentions for each user
        map<int, int> offlineUsers; // Map to track when users went offline

        // Sort events by timestamp. If timestamps are the same, process "OFFLINE" before "MESSAGE".
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA == timeB) {
                return a[0] == "OFFLINE"; // "OFFLINE" events come before "MESSAGE"
            }
            return timeA < timeB;
        });

        for (const auto& event : events) {
            string eventType = event[0];
            int timestamp = stoi(event[1]);

            if (eventType == "MESSAGE") {
                string mentionString = event[2];
                if (mentionString == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                       
                            mentions[i]++;
            
                    }
                } else if (mentionString == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineUsers.find(i) == offlineUsers.end() || offlineUsers[i] + 60 <= timestamp) {
                            mentions[i]++;
                        }
                    }
                } else {                    
                    stringstream ss(mentionString);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                                mentions[userId]++;
                        }
                    }
                }
            } else if (eventType == "OFFLINE") {
                int userId = stoi(event[2]);
                offlineUsers[userId] = timestamp;    
            }
        }

        return mentions;
    }
};
