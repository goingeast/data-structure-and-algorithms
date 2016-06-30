class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
        unordered_map<string, multiset<string>> graph;
        for(int i= 0; i < tickets.size(); ++i){
            graph[tickets[i].first].insert(tickets[i].second);
        }
        
        stack<string> beingVisit;
        vector<string> itinerary;
        
        beingVisit.push("JFK");
        
        while(!beingVisit.empty()){
            
            // while(graph.find(beingVisit.top()) != graph.end() && !graph[beingVisit.top()].empty()){
            //     auto it = graph[beingVisit.top()].begin();
            //     beingVisit.push(*it);
            //     graph[beingVisit.top()].erase(it);
            // }
            // result.push_back(beingVisit.top());
            // beingVisit.pop();
            string topAirport = beingVisit.top();
            if (graph[topAirport].empty()){
                // If there is no more outgoing edges, append to itinerary
                // Two cases: 
                // 1. If it searchs the terminal end first, it will simply get
                //    added to the itinerary first as it should, and the proper route
                //    will still be traversed since its entry is still on the stack.
                // 2. If it search the proper route first, the dead end route will also
                //    get added to the itinerary first.
                itinerary.push_back(topAirport);
                beingVisit.pop();
            }
            else {
                // Otherwise push the outgoing edge to the dfs stack and 
                // remove it from the node.
                beingVisit.push(*(graph[topAirport].begin()));
                graph[topAirport].erase(graph[topAirport].begin());
            }
            
        }
        
        return vector<string>(itinerary.rbegin(), itinerary.rend());
    }
};