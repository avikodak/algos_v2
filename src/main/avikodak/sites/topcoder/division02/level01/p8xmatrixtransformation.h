/****************************************************************************************************************************************************
 *  File Name                   : p8xmatrixtransformation.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\p8xmatrixtransformation.h
 *  Created on                  : Jul 17, 2015 :: 8:10:26 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://community.topcoder.com/stat?c=problem_statement&pm=11056
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef P8XMATRIXTRANSFORMATION_H_
#define P8XMATRIXTRANSFORMATION_H_

//Tested
class P8XMatrixTransformation {
public:
	string solve(vector<string> original,vector<string> target){
		unsigned zeroCount[2] = {0},oneCount[2] = {0};
		for(unsigned int rowCounter = 0;rowCounter < original[0].size();rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < original.size();columnCounter++){
				if(original[rowCounter][columnCounter]=='0'){
					zeroCount[0]++;
				}else{
					oneCount[0]++;
				}
			}
		}
		for(unsigned int rowCounter = 0;rowCounter < target[0].size();rowCounter++){
			for(unsigned int columnCounter = 0;columnCounter < target.size();columnCounter++){
				if(target[rowCounter][columnCounter]=='0'){
					zeroCount[1]++;
				}else{
					oneCount[1]++;
				}
			}
		}
		return zeroCount[0] == zeroCount[1] && oneCount[0] == oneCount[1]?"YES":"NO";
	}
};

#endif /* P8XMATRIXTRANSFORMATION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
