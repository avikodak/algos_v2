/****************************************************************************************************************************************************
 *  File Name                   : encryption.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\implementation\encryption.h
 *  Created on                  : Jul 11, 2015 :: 1:27:18 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : http://www.dnaindia.com/entertainment/report-baahubali-creates-history-rakes-in-rs-50-crore-on-its-opening-day-2103615
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

#ifndef ENCRYPTION_H_
#define ENCRYPTION_H_

//Tested
void getEncryptedData(){
	string userInput;
	cin >> userInput;
	int columns = ceil(sqrt(userInput.length()));
	queue<char> rows[columns];
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		rows[counter%columns].push(userInput[counter]);
	}
	for(unsigned int counter = 0;counter < columns;counter++){
		while(!rows[counter].empty()){
			printf("%c",rows[counter].front());
			rows[counter].pop();
		}
		printf("\n");
	}
}

#endif /* ENCRYPTION_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
