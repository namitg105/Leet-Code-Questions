//CODE WITHOUT USING IF STATEMENTS


/*
This solution uses a very neat trick:

morseCode[c - 'a']

Instead of writing 26 if statements, it calculates the index of each letter directly.

Let's trace it.

Step 1: Morse code vector
vector<string> morseCode = {
".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
"-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
"..-","...-",".--","-..-","-.--","--.."
};

The indices are

Index	Letter	Morse
0	a	.-
1	b	-...
2	c	-.-.
3	d	-..
4	e	.
5	f	..-.
6	g	--.
7	h	....
8	i	..
9	j	.---
...	...	...
25	z	--..
Step 2

Suppose char c = 'g';   

ASCII values are

'a' = 97
'g' = 103

So

c - 'a'  becomes 103 - 97 = 6

Therefore  morseCode[c - 'a'] becomes

morseCode[6]

which is

"--."

*/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        unordered_set<string> uniqueMorse;

        for (const string& word : words) {
            string morseRepresentation = "";
            for (char c : word) {
                morseRepresentation += morseCode[c - 'a'];
            }
            uniqueMorse.insert(morseRepresentation);
        }

        return uniqueMorse.size();
    }
};