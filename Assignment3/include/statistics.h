//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

#ifndef __STATISTICS_H
#define __STATISTICS_H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include <vector>

class StatisticalDistribution {
    protected:
        double mean;
    public:
        double get_mean() const;
        virtual std::vector<double> sample(int, int) const = 0;
        std::vector<double> calculate_confidence_interval(std::vector<double>, int, double) const;
};

class NormalDistribution : public StatisticalDistribution {
    private:
        double stddev;
    public:
        NormalDistribution();
        std::vector<double> sample(int, int) const;
};

class UniformDistribution : public StatisticalDistribution {
    private:
        double a, b;
    public:
        UniformDistribution();
        std::vector<double> sample(int, int) const;
};

class ExponentialDistribution : public StatisticalDistribution {
    private:
        double lambda;
    public:
        ExponentialDistribution();
        std::vector<double> sample(int, int) const;
};


#endif