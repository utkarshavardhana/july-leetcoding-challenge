class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> Indegree(numCourses), res;
        for(auto & prerequisite : prerequisites) {
            graph[prerequisite[0]].emplace(prerequisite[1]);
            Indegree[prerequisite[1]]++;
        }
        queue<int> vQue;
        for(int i=0; i<numCourses; i++)    if(!Indegree[i])    vQue.push(i);
        while(!vQue.empty()) {
           int node = vQue.front();    vQue.pop();
            res.push_back(node);
           for(auto elem : graph[node]) {
               Indegree[elem]--;
               if(!Indegree[elem]) {
                   vQue.push(elem);
               }
           }
        }
        for(auto elem : Indegree)   if(elem)    return vector<int>();
        reverse(res.begin(), res.end());
        return res;
    }
};
