/**
 *
Convert a char to an integer. You can assume the char is in ASCII code (See Definition, so the value of the char should be in 0~255.

Example
Given a, return 97.

Given %, return 37.
 */


class Solution {
public:
    /**
     * @param character: a character
     * @return: An integer
     */
    int charToInteger(char character) {
        return character-'a'+97;// write your code here
    }
};