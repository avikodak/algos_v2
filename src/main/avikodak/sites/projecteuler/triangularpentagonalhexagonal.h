/****************************************************************************************************************************************************
 *  File Name                   : triangularpentagonalhexagonal.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\triangularpentagonalhexagonal.h
 *  Created on                  : Aug 16, 2015 :: 12:13:26 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=45
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

#ifndef TRIANGULARPENTAGONALHEXAGONAL_H_
#define TRIANGULARPENTAGONALHEXAGONAL_H_

//Tested
unsigned int getTriangleNumber(unsigned int userInput){
	return ((userInput)*(userInput+1))/2;
}

//Tested
unsigned int getPentagonNumber(unsigned int userInput) {
	return ((userInput) * ((3 * userInput) - 1)) / 2;
}

//Tested
unsigned int getHexagonalNumber(unsigned int userInput){
	return (userInput)*((2*userInput)-1);
}

//Tested
//Ans : 1533776805
void getIntersectionNumber(){
	unsigned int counter = 1;
	map<unsigned int,bool> triangleNumberMap;
	map<unsigned int,bool> pentagonNumberMap;
	map<unsigned int,bool> hexagonalNumberMap;
	unsigned int triangleNumber,pentagonNumber,hexagonalNumber;
	while(true){
		triangleNumber = getTriangleNumber(counter);
		pentagonNumber = getPentagonNumber(counter);
		hexagonalNumber = getHexagonalNumber(counter);
		if(triangleNumber > 40755 && hexagonalNumberMap.find(triangleNumber) != hexagonalNumberMap.end() && pentagonNumberMap.find(triangleNumber) != pentagonNumberMap.end()){
			cout << triangleNumber << endl;
			return;
		}
		triangleNumberMap.insert(pair<unsigned int,bool>(triangleNumber,true));
		pentagonNumberMap.insert(pair<unsigned int,bool>(pentagonNumber,true));
		hexagonalNumberMap.insert(pair<unsigned int,bool>(hexagonalNumber,true));
		counter++;
	}
}

#endif /* TRIANGULARPENTAGONALHEXAGONAL_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
