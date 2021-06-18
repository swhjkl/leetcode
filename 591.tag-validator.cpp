/*
 * @lc app=leetcode id=591 lang=cpp
 *
 * [591] Tag Validator
 */

 #include <iostream>
 #include <vector>
 #include <stack>
 #include <string>

 using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string code) {
        stack<pair<int, int>> tags;
        int begin = 0;
        enum {
            NORMAL,
            PASSED_LEFT_ANGLE,
            IN_START_TAG,
            IN_END_TAG,
            STARTING_CDDATA,
            STOPPING_CDDATA,
            IN_CDDATA_CONTENT
        } status = NORMAL;
        string cddata_start = "<![CDATA[";
        string cddata_end = "]]>";
        bool begin_with_tag = false;
        for (int i = 0; i < code.size(); i++) {
            char &c = code[i];
            switch (status) {
            case NORMAL:
                if (c == '<') {
                    status = PASSED_LEFT_ANGLE;
                    begin = i;
                }
                break;
            case PASSED_LEFT_ANGLE:
                if (c >= 'A' && c <= 'Z') {
                    status = IN_START_TAG;
                    begin = i;
                } else if (c == '/') {
                    status = IN_END_TAG;
                    begin = i + 1;
                } else if (c == '!') {
                    status = STARTING_CDDATA;
                } else {
                    return false;
                }
                break;
            case IN_START_TAG:
                if (c == '>') {
                    if (i - begin > 9) {
                        return false;
                    }
                    tags.push({begin, i - 1});
                    if (begin == 1) {
                        begin_with_tag = true;
                    }
                    status = NORMAL;
                } else if (c < 'A' || c > 'Z') {
                    return false;
                }
                break;
            case IN_END_TAG:
                if (c == '>') {
                    if (tags.empty()) {
                        return false;
                    }
                    int start_tag_len = tags.top().second - tags.top().first + 1;
                    int end_tag_len = i - begin;
                    if (start_tag_len != end_tag_len) {
                        return false;
                    }
                    for (int j = 0; j < start_tag_len; j++) {
                        if (code[tags.top().first + j] != code[begin + j]) {
                            return false;
                        }
                    }
                    tags.pop();
                    if (tags.empty()) {
                        if (i != code.size() - 1) {
                            return false;
                        } 
                    }
                    status = NORMAL;
                } else if (c < 'A' || c > 'Z') {
                    return false;
                }
                break;
            case STARTING_CDDATA:
                if (c != cddata_start[i - begin]) {
                    return false;
                }
                if (i - begin + 1 == cddata_start.size()) {
                    status = IN_CDDATA_CONTENT;
                }
                break;
            case IN_CDDATA_CONTENT:
                if (c == ']') {
                    status = STOPPING_CDDATA;
                    begin = i;
                }
                break;
            case STOPPING_CDDATA:
                if (c != cddata_end[i - begin]) {
                    status = IN_CDDATA_CONTENT;
                } else if (i - begin + 1 == cddata_end.size()) {
                    status = NORMAL;
                }
                break;
            }
        }
        return tags.empty() && begin_with_tag;
    }
};
// @lc code=end