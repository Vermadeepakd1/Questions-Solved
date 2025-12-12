class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if (t1 == t2) {
                return a[0] == "OFFLINE"; 
            }
            return t1 < t2;
        });
        set<int> online;
        vector<int> mentions(numberOfUsers,0);
        for(int i = 0; i< numberOfUsers; i++){
            online.insert(i);
        }
        // priority_queue<pair<int,vector<int>>> msg;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> onTime;
        int allcount = 0;
        for(auto &vec : events){
            int ts = stoi(vec[1]);
            while(!onTime.empty() && onTime.top().first <= ts){
                online.insert(onTime.top().second);
                onTime.pop();
            }
            if(vec[0] == "MESSAGE"){
                string mention = vec[2];

                if(mention == "ALL"){
                    allcount++;
                }else if(mention == "HERE"){
                    for(int i : online){
                        mentions[i]++;
                    }
                }else{
                    string id = "";
                    for(char i : mention){
                        if(i == 'i' || i == 'd')continue;
                        else if (i != ' '){
                            id += i;
                        }else{
                            if (!id.empty()) {
                                mentions[stoi(id)]++;
                                id = "";
                            }
                        }

                    }
                    if(id != "")mentions[stoi(id)]++;
                }
            }else{
                int id = stoi(vec[2]);
                onTime.push({ts + 60, id});
                online.erase(id);
            }
        }

        for(int i = 0; i<numberOfUsers; i++){
            mentions[i] += allcount;
        }

        return mentions;
    }
};