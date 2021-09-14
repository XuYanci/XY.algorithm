//
//  XYGraph.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci Xu on 2021/9/14.
//  Copyright © 2021 Yanci. All rights reserved.
//

#ifndef XYGraph_hpp
#define XYGraph_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class XYGraph {
    
private:
    vector<int> recordPath;
    vector<vector<int>> allPaths;
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        recordPath.push_back(0);
        dfs(0, graph);
        return allPaths;
    }
    
    /// i代表第几个节点
    /// graph代表图领接表
    void dfs(int i,vector<vector<int>>& graph) {
        if (i == graph.size() -1 ) {
            allPaths.push_back(recordPath);
            return;
        }
        vector<int>subGraph = graph[i];
        for (int j = 0; j < subGraph.size(); j++) {
            int k = subGraph[j];
            recordPath.push_back(k);
            dfs(k, graph);
            recordPath.pop_back();
        }
    }
    
 
};

#endif /* XYGraph_hpp */
