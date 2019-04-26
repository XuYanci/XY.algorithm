//
//  XYSearch.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/4/21.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef XYSearch_hpp
#define XYSearch_hpp

#include <stdio.h>

class XYSearch {
    public:
    
    XYSearch();
    ~XYSearch();
    

    void linearSearch(int *array,int count,int val);
    void divideSearch(int *array,int count,int val);
    
    
};

#endif /* XYSearch_hpp */
