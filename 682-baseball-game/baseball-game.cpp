

class Solution {
   vector<int> answers;
public:

    int calPoints(vector<string>& operations) {
for(int i=0;i<operations.size();i++){
    if(operations[i]=="D"){
int prevElement=answers.back();
answers.push_back(prevElement*2);
    }
else if(operations[i]=="C"){
    answers.pop_back();
}
else if(operations[i]=="+"){
    int prevElement=answers.back();
    answers.pop_back();
    int prevPrevElement=answers.back();
    answers.push_back(prevElement);
    answers.push_back(prevElement+prevPrevElement);
}
else{
    answers.push_back(stoi(operations[i]));
}


}

return accumulate(answers.begin(),answers.end(),0);
   }
};