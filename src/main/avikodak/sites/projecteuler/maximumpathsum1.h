/****************************************************************************************************************************************************
 *  File Name                   : maximumpathsum1.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\maximumpathsum1.h
 *  Created on                  : Aug 12, 2015 :: 8:42:44 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=18
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

#ifndef MAXIMUMPATHSUM1_H_
#define MAXIMUMPATHSUM1_H_

//Tested
//Ans : 1074
void getMaximumPathSum(){
	unsigned int rows,input;
	cin >> rows;
	vector<vector<unsigned int> > userInput(rows);
	for(unsigned int rowCounter = 1;rowCounter <= rows;rowCounter++){
		for(unsigned int columnCounter = 1;columnCounter <= rowCounter;columnCounter++){
			cin >> input;
			userInput[rowCounter-1].push_back(input);
		}
	}
	for(int rowCounter = userInput.size()-2;rowCounter >= 0;rowCounter--){
		for(int columnCounter = userInput[rowCounter].size()-1;columnCounter >= 0;columnCounter--){
			userInput[rowCounter][columnCounter] += max(userInput[rowCounter+1][columnCounter],userInput[rowCounter+1][columnCounter+1]);
		}
	}
	cout << userInput[0][0] << endl;
}

#endif /* MAXIMUMPATHSUM1_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
