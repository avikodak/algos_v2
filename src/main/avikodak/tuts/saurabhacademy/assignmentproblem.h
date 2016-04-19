/****************************************************************************************************************************************************
 *  File Name                   : assignmentproblem.h
 *  File Location               : \algos_v2\src\main\avikodak\tuts\saurabhacademy\assignmentproblem.h
 *  Created on                  : Dec 18, 2014 :: 8:19:06 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef ASSIGNMENTPROBLEM_H_
#define ASSIGNMENTPROBLEM_H_

int assignmentProblem(vector<vector<int> > payMatrix, int jobCounter, hash_map<unsigned int, unsigned int> personJobMap) {
    if (jobCounter > payMatrix[0].size()) {
        return INT_MAX;
    }
    if (jobCounter == payMatrix[0].size()) {
        return 0;
    }
    int minAmount = INT_MAX;
    for (unsigned int person = 0; person < payMatrix.size(); person++) {
        if (personJobMap.find(person) == personJobMap.end()) {
            personJobMap.insert(pair<unsigned int, unsigned int>(person, jobCounter));
            minAmount = min(minAmount, payMatrix[person][jobCounter] + assignmentProblem(payMatrix, jobCounter, personJobMap));
            personJobMap.erase(person);
        }
    }
    return minAmount;
}

#endif /* ASSIGNMENTPROBLEM_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
