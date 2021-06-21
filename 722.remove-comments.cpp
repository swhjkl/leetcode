/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

// @lc code=start
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        enum {
            NORMAL,
            PREV_SLASH,
            IN_SLASH_ASTERISK,
            PREV_ASTERISK
        } status = NORMAL;

        int begin_line;
        int begin_pos;
        int line_count = source.size();
        for (int i = 0; i < line_count; i++) {
            if (status != IN_SLASH_ASTERISK) {
                status = NORMAL;
            }
            int line_size = source[i].size();
            for (int j = 0; j < line_size; j++) {
                char &c = source[i][j];
                switch (status) {
                case NORMAL:
                    if (c == '/') {
                        status = PREV_SLASH;
                        begin_line = i;
                        begin_pos = j;
                    } 
                    break;
                case PREV_SLASH:
                    if (c == '/') {
                        if (begin_pos == 0) {
                            source.erase(source.begin() + i);
                            i--;
                            line_count--;
                            line_size = j = 0;
                        } else {
                            source[i].erase(begin_pos, source[i].size() - begin_pos);
                            line_size = j = begin_pos;
                            j--;
                        }
                        status = NORMAL;
                    } else if (c == '*') {
                        status = IN_SLASH_ASTERISK;
                    } else {
                        status = NORMAL;
                    }
                    break;
                case IN_SLASH_ASTERISK:
                    if (c == '*') {
                        status = PREV_ASTERISK;
                    }
                    break;
                case PREV_ASTERISK:
                    if (c == '/') {
                        if (begin_line == i) {
                            source[i].erase(begin_pos, j - begin_pos + 1);
                            line_size -= (j - begin_pos + 1);
                            if (line_size == 0) {
                                source.erase(source.begin() + begin_line);
                                line_count--;
                                i--;
                                j = 0;
                            } else {
                                j = begin_pos - 1;
                            }
                        } else {
                            int k = begin_line + 1;
                            while (k < i) {
                                source.erase(source.begin() + k);
                                i--;
                                line_count--;
                            }
                            source[begin_line].erase(begin_pos, source[begin_line].size() - begin_pos);
                            source[i].erase(0, j + 1);
                            j = source[begin_line].size();
                            if (j > 0) {
                                j--;
                            }
                            source[begin_line].append(source[i]);
                            line_size = source[begin_line].size();
                            source.erase(source.begin() + i);
                            i--;
                            line_count--;
                            if (line_size == 0) {
                                source.erase(source.begin() + begin_line);
                                i--;
                                line_count--;
                            }
                        }
                        status = NORMAL;
                    } else if (c == '*') {
                        status = PREV_ASTERISK;
                    } else {
                        status = IN_SLASH_ASTERISK;
                    }
                    break;
                }
            }
        }
        return source;
    }
};
// @lc code=end