/****************************************************************************************************************************************************
 *  File Name                   : pathsumtwoways.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\pathsumtwoways.h
 *  Created on                  : Aug 19, 2015 :: 11:04:49 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=81
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

#ifndef PATHSUMTWOWAYS_H_
#define PATHSUMTWOWAYS_H_

//Tested
vector<vector<unsigned int> > getMatrix(){
	unsigned int size,input;
	cin >> size;
	vector<vector<unsigned int> > userInput(size);
	for(unsigned int counter = 0;counter < size;counter++){
		userInput[counter].assign(size,0);
	}
	for(unsigned int rowCounter = 0;rowCounter < size;rowCounter++){
		for(unsigned int columnCounter = 0;columnCounter < size;columnCounter++){
			cin >> input;
			userInput[rowCounter][columnCounter] = input;
		}
	}
	return userInput;
}

//Tested
//Ans : 427337
void printMinimalPathSum(){
	vector<vector<unsigned int> > userInput = getMatrix();
	unsigned int size = userInput.size();
	for(int columnCounter = size-2;columnCounter >= 0;columnCounter--){
		userInput[size-1][columnCounter] += userInput[size-1][columnCounter+1];
	}
	for(int rowCounter = size-2;rowCounter >= 0;rowCounter--){
		userInput[rowCounter][size-1] += userInput[rowCounter+1][size-1];
	}
	for(int rowCounter = size-2;rowCounter >= 0;rowCounter--){
		for(int columnCounter = size-2;columnCounter >=0;columnCounter--){
			userInput[rowCounter][columnCounter] += min(userInput[rowCounter][columnCounter+1],userInput[rowCounter+1][columnCounter]);
		}
	}
	cout << userInput[0][0] << endl;
}

#endif /* PATHSUMTWOWAYS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
