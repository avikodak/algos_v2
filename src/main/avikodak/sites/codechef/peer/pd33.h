/****************************************************************************************************************************************************
 *  File Name                   : pd33.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/pd33.h
 *  Created on                  : 22-Sep-2015 :: 12:28:29 am
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.codechef.com/problems/PD33
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
#include <stdint.h>
#include <iomanip>
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

#ifndef PD33_H_
#define PD33_H_

//Tested
void printResults(){
	unsigned int columnSize;
	string userInput;
	while(scanf("%u",&columnSize) && columnSize > 0){
		cin >> userInput;
		unsigned int rows = userInput.size()/columnSize;
		vector<vector<char> > matrix(rows);
		for(unsigned int counter = 0;counter < rows;counter++){
			matrix[counter].assign(columnSize,'x');
		}
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			matrix[counter/columnSize][counter%columnSize] = userInput[counter];
		}
		for(unsigned int columnCounter = 0;columnCounter < columnSize;columnCounter++){
			for(unsigned int rowCounter = 0;rowCounter < matrix.size();rowCounter++){
				if(rowCounter%2 == 0){
					cout << matrix[rowCounter][columnCounter];
				}else{
					cout << matrix[rowCounter][columnSize-columnCounter-1];
				}
			}
		}
		cout << endl;
	}
}

#endif /* PD33_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
