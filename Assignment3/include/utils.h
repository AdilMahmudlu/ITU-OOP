//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#ifndef __UTILS_H
#define __UTILS_H

#include "statistics.h"

StatisticalDistribution* choose_function(int);
double many_trials(StatisticalDistribution*, std::vector<double>, double, int, int, int);

#endif