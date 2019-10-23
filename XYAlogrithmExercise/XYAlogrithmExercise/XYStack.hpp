//
//  XYStack.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/25.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYStack_hpp
#define XYStack_hpp
#include <list>
#include <stdio.h>
#include <set>
struct Node {
    int val;
    std::list<Node>list;
};

class XYStack {
    bool dfs(Node cur,Node target, std::set<Node *> visited);
};

#endif /* XYStack_hpp */
