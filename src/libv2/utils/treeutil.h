/****************************************************************************************************************************************************
 *  File Name                   : treeutil.h
 *  File Location               : /algos_v2/src/libv2/utils/treeutil.h
 *  Created on                  : Jan 16, 2016 :: 10:59:00 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
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

#ifndef LIBV2_UTILS_TREEUTIL_H_
#define LIBV2_UTILS_TREEUTIL_H_

class treeutils{
private:
public:
	itNode *getTree(vector<int> userInput,unsigned int index = 0){
		if(userInput.size() == 0 || index >= userInput.size()){
			return null;
		}
		itNode *root = new itNode(userInput[index]);
		root->left = getTree(userInput,2*index+1);
		root->right = getTree(userInput,2*index+2);
		return root;
	}

};

#endif /* LIBV2_UTILS_TREEUTIL_H_ */
