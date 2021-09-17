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
#include <queue>
using namespace std;
class XYGraph {
    
private:
    vector<int> recordPath;
    vector<vector<int>> allPaths;
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /// 解法1: DFS
        dfs(0, graph);
        /// 解法2:BFS
        bfs(graph);
        return allPaths;
    }
    
    /// 深度搜索
    /// i代表第几个节点
    /// graph代表图领接表
    void dfs(int i,vector<vector<int>>& graph) {
        recordPath.push_back(i);
        if (i == graph.size() -1 ) {
            allPaths.push_back(recordPath);
            recordPath.pop_back();
            return;
        }
        vector<int>subGraph = graph[i];
        for (int j = 0; j < subGraph.size(); j++) {
            int k = subGraph[j];
            dfs(k, graph);
            
        }
        recordPath.pop_back();
    }
    
    /// 广度搜索
    /// 思考怎么存储路径中...
    void bfs(vector<vector<int>>& graph) {
        /// 队列
        queue<vector <int>>_q;
        _q.push(vector<int> {0});
        
        vector<vector<int>> v;
        v.push_back(vector<int> {0});
        
        /// 当队列不为空
        while (!_q.empty()) {
            vector<int> vv = _q.front();
            int i = vv[vv.size() - 1];
            
            /// 遍历子节点
            for (int j = 0; j < graph[i].size(); j++) {
                vector<int> copy_vv = vv;
                copy_vv.push_back(graph[i][j]);
                _q.push(copy_vv);
                /// 如果找到目标元素，则记录路径，并弹出最后一个节点
                if (graph[i][j] == graph.size() - 1) {
                    allPaths.push_back(copy_vv);
                }
            }
            _q.pop();
        }
    }
    
    
};

#endif /* XYGraph_hpp */
