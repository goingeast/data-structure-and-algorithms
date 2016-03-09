class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<int> result;
        vector< unordered_set<int> > graph(numCourses, unordered_set<int>());
        vector<int> indegree(numCourses,0);

        for(int i =0 ; i < prerequisites.size(); ++i){
        	if(graph[prerequisites[i].second].find(prerequisites[i].first) == graph[prerequisites[i].second].end()){
        		++indegree[prerequisites[i].first];
        	}
        	
        	graph[prerequisites[i].second].insert(prerequisites[i].first);
        }

        queue<int> beingVisit;

        for(int i = 0; i < numCourses; ++i){
        	if(indegree[i] == 0)
        		beingVisit.push(i);
        }
        while(!beingVisit.empty()){
        	int vertex = beingVisit.front();
        	beingVisit.pop();

        	result.push_back(vertex);

        	for(auto it = graph[vertex].begin(); it != graph[vertex].end(); ++it){
        		--indegree[*it];
        		if(indegree[*it] == 0){
        			beingVisit.push(*it);
        		}
        	}
        }
        if(result.size() != numCourses){
            return {};
        }
        return result;
    }
};