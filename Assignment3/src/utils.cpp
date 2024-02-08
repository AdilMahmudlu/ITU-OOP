//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "utils.h"


StatisticalDistribution* choose_function(int dist_type) {
    switch (dist_type)
    {
    case 0:
        return new NormalDistribution();
        break;
    case 1:
        return new UniformDistribution();
        break;
    case 2:
        return new ExponentialDistribution();
        break;
    default:
        throw "Unidentified distribution function!";
        break;
    }
}

double many_trials(StatisticalDistribution* dist, std::vector<double> random_sample, double t_value, int trials, int sample_size, int seed_value) {
    double success = 0;
    for (int i = 0; i < trials; i++)
    {
        std::vector<double> random_sample = dist->sample(sample_size, seed_value);
        std::vector<double> interval = dist->calculate_confidence_interval(random_sample, sample_size, t_value);
        if (dist->get_mean() > interval[0] && dist->get_mean() < interval[2]) {
            success += 1.0;
        }
        seed_value++;
    }
    return success / trials;
};