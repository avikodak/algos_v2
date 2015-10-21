/****************************************************************************************************************************************************
 *  File Name                   : ci3.h
 *  File Location               : /home/avikodak/Desktop/projects/algos_v2/src/main/avikodak/sites/codechef/peer/ci3.h
 *  Created on                  : 20-Oct-2015 :: 7:50:11 pm
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : https://www.codechef.com/problems/CI3
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

#ifndef CI3_H_
#define CI3_H_

double area(double a,double b,double c){
	double semiPerimeter = (a+b+c)/2;
	return sqrt(semiPerimeter*(semiPerimeter-a)*(semiPerimeter-b)*(semiPerimeter-c));
}

void printResults(){
	unsigned int testCases;
	scanf("%u",&testCases);
	double a,b,c,areaOfTriangle,sum = 0;
	vector<double> areasOfTriangles;
	while(testCases--){
		cin >> a >> b >> c;
		areaOfTriangle = area(a,b,c);
		sum +=  areaOfTriangle;
		areasOfTriangles.push_back(areaOfTriangle);
	}
	sort(areasOfTriangles.begin(),areasOfTriangles.end());
	cout << "Min : " << areasOfTriangles[0] << endl;
	cout << "Max : " << areasOfTriangles[areasOfTriangles.size()-1] << endl;
	cout << "Avg : " << sum/areasOfTriangles.size() << endl;
	if(areasOfTriangles.size()%2 == 0){
		cout << "Med : " << (areasOfTriangles[areasOfTriangles.size()/2]+areasOfTriangles[areasOfTriangles.size()/2])/2 << endl;
	}else{
		cout << "Med : " << areasOfTriangles[areasOfTriangles.size()/2] << endl;
	}

}

#endif /* CI3_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
