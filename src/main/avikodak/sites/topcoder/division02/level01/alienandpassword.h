/****************************************************************************************************************************************************
 *  File Name   		: alienandpassword.h 
 *	File Location		: D:\projects\cpp\algos_v2\src\main\avikodak\sites\topcoder\division02\level01\alienandpassword.h
 *  Created on			: Mar 28, 2015 :: 11:23:18 AM
 *  Author				: avikodak
 *  Testing Status 		: TODO
 *  URL 				: http://community.topcoder.com/stat?c=problem_statement&pm=12950
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

#ifndef ALIENANDPASSWORD_H_
#define ALIENANDPASSWORD_H_

class AlienAndPassword{
public:
	int getNumber(string userInput){
		int totalCount = 1;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			while(counter < userInput.size() && userInput[counter] == userInput[counter-1]){
				counter++;
			}
			if(counter < userInput.size()){
				totalCount++;
			}
		}
		return totalCount;
	}
};

#endif /* ALIENANDPASSWORD_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/