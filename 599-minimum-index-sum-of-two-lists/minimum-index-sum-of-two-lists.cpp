class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        vector<string> result;
        int minSum = INT_MAX;

        for(int i = 0; i < list1.size(); ++i){
            indexMap[list1[i]] = i;
        }

        for(int j = 0; j < list2.size(); ++j){
            const string& str = list2[j];
            if(indexMap.find(str) != indexMap.end()){
                int sum = j + indexMap[str];
                if(sum < minSum){
                    result = {str};
                    minSum = sum;
                } else if(sum == minSum){
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};