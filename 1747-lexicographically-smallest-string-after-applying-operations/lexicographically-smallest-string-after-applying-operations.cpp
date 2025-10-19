class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string smallest = s;

        queue<string> q;
        q.push(s);

        unordered_set<string> visited;
        visited.insert(s);

        while(!q.empty()){
            string front = q.front();
            q.pop();

            if(front < smallest) smallest = front;

            // add
            string temp = front;
            for(int i = 1; i<temp.size(); i+=2){
                temp[i] = (((temp[i] - '0')+a)%10)+'0';
            }

            if(!visited.count(temp)){
                visited.insert(temp);
                q.push(temp);
            }

            //rotate
            reverse(front.begin(),front.end());
            reverse(front.begin(), front.begin()+b);
            reverse(front.begin()+b, front.end());

            if(!visited.count(front)){
                visited.insert(front);
                q.push(front);
            }
        }

        return smallest;

    }
};