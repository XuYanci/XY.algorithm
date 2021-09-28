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
    bool hasCycle;
    
    /// 访问路径
    vector<bool>onPathes;
    /// 访问节点
    vector<bool>visited;
    
private:
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
    
    void canFinishTraverse(vector<vector<int>>&graph,
                           vector<bool>&visited,
                           int k) {
        
        if(onPathes[k]) {
            hasCycle = true;
        }
        
        /// 如果已经访问过，则代表有环
        if (visited[k] == true || hasCycle ) {
            return;
        }
        visited[k] = true;
        onPathes[k] = true;
        for (int i = 0; i < graph[k].size(); i++) {
            int to = graph[k][i];
            canFinishTraverse(graph, visited, to);
        }
        onPathes[k] = false;
    }
    
    
public:
    ///从起点到目标点的所有路径
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        /// 解法1: DFS
        dfs(0, graph);
        /// 解法2: BFS
        bfs(graph);
        return allPaths;
    }
    
    /// 课程表1
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        hasCycle = false;
        if(prerequisites.size() <= 0) {
            return true;
        }
        
        /// 构建图
        vector<vector<int>>graph = vector<vector<int>>(numCourses);
        /// 访问节点
        visited = vector<bool>(numCourses);
        /// 访问节点
        onPathes = vector<bool>(numCourses);
        
        /// Build Graph
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> pre = prerequisites[i];
            int from = pre[1];
            int to = pre[0];
            graph[from].push_back(to);
        }
        
        ///Traverse Graph
        for (int i = 0; i < numCourses; i++) {
            canFinishTraverse(graph, visited, i);
        }
        
        return !hasCycle;
        
    }
    // 课程表2
    vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites) {
        return vector<int>();
    }
    /// 网络延迟时间
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return 0;
    }
    
    int weight(int from,int to) {
        return 0;
    }
    
    /// 迪杰斯特拉
    vector<int> dijkstra(int start, vector<vector<int>> graph) {
        /// DistTo代表从起始点到dist[i]第i个节点的最短距离
        vector<int> distTo = vector<int>(graph.size(), INT8_MAX);
        /// 队列，主要用于层次遍历
        queue<int> queue;
        /// 压入首节点到队列
        queue.push(start);
        /// 首节点默认为0
        distTo[start] = 0;
        
        while (!queue.empty()) {
            int curIndex = queue.front();
            for(int i = 0; i < graph[curIndex].size();i++) {
                int nextGraphIndex = graph[curIndex][i];
                int caculateDistTo = distTo[curIndex] + weight(curIndex, nextGraphIndex); /// 计算到目标节点的路径
                if (caculateDistTo < distTo[nextGraphIndex]) {
                    distTo[nextGraphIndex] = caculateDistTo;
                    queue.push(nextGraphIndex);
                }
            }
            queue.pop();
        }
   
        return vector<int>();
    }
};

#endif /* XYGraph_hpp */
