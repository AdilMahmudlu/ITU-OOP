//--- 2021-2022 Summer Object Oriented Programing Assignment 3 ---//
//--------------------------//
//---Name & Surname: Adil Mahmudlu
//---Student Number: 150200915
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//

#include "statistics.h"
#include <random>
#include <iostream>

//General

double StatisticalDistribution::get_mean() const {
    return mean;
}

std::vector<double> StatisticalDistribution::calculate_confidence_interval(std::vector<double> random_sample, int sample_size, double t_value) const {
    double sum = 0, sample_mean = 0, variance = 0, standart_dev, lower_bound, upper_bound;
    for (auto i : random_sample) {
        sum+= i;
    }
    sample_mean = sum/sample_size;
    for (auto i : random_sample) {
        variance += std::pow(i - sample_mean, 2);
    }
    standart_dev = std::sqrt(variance/sample_size);
    lower_bound = sample_mean - t_value*standart_dev/std::sqrt(sample_size);
    upper_bound = sample_mean + t_value*standart_dev/std::sqrt(sample_size);
    return std::vector<double>{lower_bound, sample_mean, upper_bound};
}

//Normal

NormalDistribution::NormalDistribution() : StatisticalDistribution() {
    mean = 0;
    stddev = 1;
}

std::vector<double> NormalDistribution::sample(int sample_size, int seed_val) const {
    std::vector<double> normal_sample;
    std::default_random_engine generator ;
    generator.seed(seed_val);
    std::normal_distribution<double> distribution(mean,stddev);
    for (int i = 0; i < sample_size; i++)
    {
        double number = distribution(generator);
        normal_sample.push_back(number);
    }
    return normal_sample;
}

//Uniform

UniformDistribution::UniformDistribution() : StatisticalDistribution() {
    mean = 0;
    a = -1;
    b = 1;
}

std::vector<double> UniformDistribution::sample(int sample_size, int seed_val) const {
    std::vector<double> uniform_sample;
    std::default_random_engine generator ;
    generator.seed(seed_val);
    std::uniform_real_distribution<double> distribution(a, b);
    for (int i = 0; i < sample_size; i++) {
        double number = distribution(generator);
        uniform_sample.push_back(number);
    }
    return uniform_sample;
}

//Exponential

ExponentialDistribution::ExponentialDistribution() : StatisticalDistribution() {
    mean = 1;
    lambda = 1;
}

std::vector<double> ExponentialDistribution::sample(int sample_size, int seed_val) const {
    std::vector<double> exponential_sample;
    std::default_random_engine generator ;
    generator.seed(seed_val);
    std::exponential_distribution<double> distribution(lambda);
    for (int i = 0; i < sample_size; i++) {
        double number = distribution(generator);
        exponential_sample.push_back(number);
    }
    return exponential_sample;
}