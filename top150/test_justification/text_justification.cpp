#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        for (int i=0; i< words.size();)
        {
            string line = ""; // the upcoming line to be constructed
            
            int j=i; // use the remaining words
            int linesize = -1; // first word needs no leading space
            for (; j< words.size() && linesize+1+words[j].size() <= maxWidth; ++j)
                linesize += words[j].size()+1; // while the next word can be added
            
            int totExtraSpace = 0;
            for (int k=i; k<words.size() && k<j; ++k)
            {
                line += words[k];
                if (k != j-1)
                {
                    int spaceLength = 1;
                    if (j!=words.size()) // not the last line
                    {
                        int spaceToDistribute = maxWidth-linesize-totExtraSpace;
                        int remainingParts = j-k-1;
                        int eSpaceLength = spaceToDistribute/remainingParts + (spaceToDistribute % remainingParts != 0);
                        totExtraSpace += eSpaceLength;
                        spaceLength += eSpaceLength;
                    }                    
                    line += string(spaceLength, ' ');
                }
                else
                {
                    line += string(maxWidth - line.size(),' ');
                }
            }
            ret.push_back(line);
            i=j;
        }
        return ret;
    }
};

int main()
{
    vector<string> text({"What","must","be","acknowledgment","shall","be"});
    Solution sol;
    for (auto line:sol.fullJustify(text,16))
        cout << line << "|" << endl;
    
    return 0;
}

    