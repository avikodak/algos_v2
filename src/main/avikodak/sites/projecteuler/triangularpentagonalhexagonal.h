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
