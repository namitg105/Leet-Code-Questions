class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     string morseCodes[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

char  a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f',
     g = 'g', h = 'h', i = 'i', j = 'j', k = 'k', l = 'l',
     m = 'm', n = 'n', o = 'o', p = 'p', q = 'q', r = 'r',
     s = 's', t = 't', u = 'u', v = 'v', w = 'w', x = 'x',
     y = 'y', z = 'z';
vector<string> answers(words.size());
 for(int i=0;i<words.size();i++){
    for(int j=0;j<words[i].size();j++){
if (words[i][j] == 'a') answers[i].append(morseCodes[0]);
if (words[i][j] == 'b') answers[i].append(morseCodes[1]);
if (words[i][j] == 'c') answers[i].append(morseCodes[2]);
if (words[i][j] == 'd') answers[i].append(morseCodes[3]);
if (words[i][j] == 'e') answers[i].append(morseCodes[4]);
if (words[i][j] == 'f') answers[i].append(morseCodes[5]);
if (words[i][j] == 'g') answers[i].append(morseCodes[6]);
if (words[i][j] == 'h') answers[i].append(morseCodes[7]);
if (words[i][j] == 'i') answers[i].append(morseCodes[8]);
if (words[i][j] == 'j') answers[i].append(morseCodes[9]);
if (words[i][j] == 'k') answers[i].append(morseCodes[10]);
if (words[i][j] == 'l') answers[i].append(morseCodes[11]);
if (words[i][j] == 'm') answers[i].append(morseCodes[12]);
if (words[i][j] == 'n') answers[i].append(morseCodes[13]);
if (words[i][j] == 'o') answers[i].append(morseCodes[14]);
if (words[i][j] == 'p') answers[i].append(morseCodes[15]);
if (words[i][j] == 'q') answers[i].append(morseCodes[16]);
if (words[i][j] == 'r') answers[i].append(morseCodes[17]);
if (words[i][j] == 's') answers[i].append(morseCodes[18]);
if (words[i][j] == 't') answers[i].append(morseCodes[19]);
if (words[i][j] == 'u') answers[i].append(morseCodes[20]);
if (words[i][j] == 'v') answers[i].append(morseCodes[21]);
if (words[i][j] == 'w') answers[i].append(morseCodes[22]);
if (words[i][j] == 'x') answers[i].append(morseCodes[23]);
if (words[i][j] == 'y') answers[i].append(morseCodes[24]);
if (words[i][j] == 'z') answers[i].append(morseCodes[25]);
    }
 }

 set<string> answerSet(answers.begin(), answers.end());
 return answerSet.size();
    }




};