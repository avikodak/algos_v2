/****************************************************************************************************************************************************
 *  File Name   		: typingdistance.h
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\typingdistance.h
 *  Created on			: Mar 25, 2015 :: 11:59:18 PM
 *  Author				: avikodak
 *  Testing Status 		: Tested
 *  URL 				: http://community.topcoder.com/stat?c=problem_statement&pm=12297
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TYPINGDISTANCE_H_
#define TYPINGDISTANCE_H_

//Tested
class TypingDistance {
public:
    int minDistance(string keyboard, string word) {
        map<char,unsigned int> charIndexMap;
        for(unsigned int counter = 0; counter < keyboard.size(); counter++) {
            charIndexMap.insert(pair<char,unsigned int>(keyboard[counter],counter));
        }
        int totalMoves = 0,prevIndex,temp;
        prevIndex = charIndexMap.find(word[0])->second;
        for(unsigned int counter = 1; counter < word.size(); counter++) {
            temp = (charIndexMap.find(word[counter]))->second;
            totalMoves += abs(prevIndex - temp);
            prevIndex = temp;
        }
        return totalMoves;
    }
};

#endif /* TYPINGDISTANCE_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
