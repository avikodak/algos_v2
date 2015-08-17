/****************************************************************************************************************************************************
 *  File Name                   : integerrighttriangles.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\projecteuler\integerrighttriangles.h
 *  Created on                  : Aug 17, 2015 :: 9:01:42 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://projecteuler.net/problem=39
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

#ifndef INTEGERRIGHTTRIANGLES_H_
#define INTEGERRIGHTTRIANGLES_H_

//Tested
//Ans : 840
void printMaxTrianglesForPerimeter(){
	map<unsigned int,unsigned int> perimeterTriangleCount;
	map<unsigned int,unsigned int>::iterator itToPerimeterTriangleCount;
	unsigned int perimeter,maxTriangles = 0,maxPerimeter;
	for(unsigned int outerCounter = 3;outerCounter <= 1000;outerCounter++){
		for(unsigned int innerCounter = outerCounter+1;innerCounter <= 1000;innerCounter++){
			for(unsigned int difference = innerCounter+1;difference <= 1000;difference++){
				perimeter = outerCounter + innerCounter + difference;
				if(perimeter <= 1000){
					if(difference*difference == ((outerCounter*outerCounter) + (innerCounter*innerCounter))){
						perimeter = outerCounter + innerCounter + difference;
						if((itToPerimeterTriangleCount = perimeterTriangleCount.find(perimeter)) == perimeterTriangleCount.end()){
							perimeterTriangleCount.insert(pair<unsigned int,unsigned int>(perimeter,1));
						}else{
							perimeterTriangleCount[perimeter]++;
						}
						if(maxTriangles < perimeterTriangleCount[perimeter]){
							maxTriangles = perimeterTriangleCount[perimeter];
							maxPerimeter = perimeter;
						}
					}
				}
			}
		}
	}
	cout << maxPerimeter << endl;
	return;
}

#endif /* INTEGERRIGHTTRIANGLES_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
