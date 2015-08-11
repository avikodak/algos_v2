/****************************************************************************************************************************************************
 *  File Name                   : latticepaths.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\latticepaths.h
 *  Created on                  : Aug 11, 2015 :: 9:14:32 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=15
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

#ifndef LATTICEPATHS_H_
#define LATTICEPATHS_H_

//Tested
//Ans : 137846528820
unsigned long long int getTotalLatticePaths(unsigned int size){
	vector<vector<unsigned long long int> > matrix(size+1);
	for(unsigned int counter = 0;counter < matrix.size();counter++){
		matrix[counter].assign(size+1,0);
	}
	for(unsigned int rowCounter = 0;rowCounter < size+1;rowCounter++){
		matrix[rowCounter][size] = 1;
	}
	for(unsigned int columnCounter = 0;columnCounter < size+1;columnCounter++){
		matrix[size][columnCounter] = 1;
	}
	matrix[size][size] = 0;
	for(int rowCounter = size-1;rowCounter >= 0;rowCounter--){
		for(int columnCounter = size-1;columnCounter >= 0;columnCounter--){
			matrix[rowCounter][columnCounter] = matrix[rowCounter][columnCounter+1] + matrix[rowCounter+1][columnCounter];
		}
	}
	cout << matrix[0][0] << endl;
}

#endif /* LATTICEPATHS_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
