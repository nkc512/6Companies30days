class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int> vec;
        int count=0;
        char ch=colors[0];
        for(int i=0;i<colors.length();i++)
        {
            if(colors[i]==ch)
                count++;
            else
            {
                vec.push_back(max(count-2,0));
                count=1;
                ch=colors[i];
            }
        }
        vec.push_back(max(count-2,0));
        int sum=0;
        for(int i:vec)
            sum+=i;
        int sumFirst=0;
        for(int i=0;i<vec.size();i+=2)
        {
            sumFirst+=vec[i];
        }
        bool temp=(sumFirst*2)>sum;
        
        if(colors[0]=='A')
        {
            return temp;
        }
        // in case of B, even equal count is bad for A
        temp=(sumFirst*2)<sum;
        return temp;
    }
};
/*
"A"
"AA"
"AAA"
"AAAAABBBB"
"AAAAABBBBB"
"AAAABBB"
"AAAB"
"AAABABB"
"AAABBB"
"AAABBBAA"
"AAABBBAAA"
"AAABBBB"
"AAABBBBAAAB"
"AAB"
"AABA"
"AABBBBAAA"
"AB"
"ABA"
"ABBBBBBBAAA"
"B"
"BA"
"BAAAAAAABBB"
"BAB"
"BB"
"BBA"
"BBAA"
"BBAAA"
"BBAAAABBB"
"BBAB"
"BBB"
"BBBA"
"BBBAAA"
"BBBAAAA"
"BBBAAAABBBA"
"BBBAAABB"
"BBBAAABBB"
"BBBABAA"
"BBBBAAA"
"BBBBBAAAA"
"BBBBBAAAAA"
*/