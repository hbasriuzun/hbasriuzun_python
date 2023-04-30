#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

double dense(vector<double> x, vector<double> w, double b){
    double sum = 0;
    for(int i = 0; i < x.size(); i++){
        sum += x[i] * w[i];
    }
    return sum + b;
}

double dot(vector<double> x, vector<double> w){
    double sum = 0;
    for(int i = 0; i < x.size(); i++){
        sum += x[i] * w[i];
    }
    return sum;
}
double sigmoid(double x){

    return 1 / (1 + exp(-x));
}

int main(){
    vector<double> x ={200,17};
    vector<double> w1_1 ={1,2}, w1_2 ={-3,4}, w1_3 ={5,-6},
                   w2_1 ={-7,8,9};
    vector<double> b1_1 ={-1}, b1_2 ={1}, b1_3 ={2},
                   b2_1 ={3};
    vector<double> z1_1, z1_2, z1_3,
                   z2_1;
    vector<double> a1_1, a1_2, a1_3,
                   a2_1;

    z1_1.push_back(dot(x, w1_1) + b1_1[0]);
    a1_1.push_back(sigmoid(z1_1[0]));

    z1_2.push_back(dot(x, w1_2) + b1_2[0]);
    a1_2.push_back(sigmoid(z1_2[0]));

    z1_3.push_back(dot(x, w1_3) + b1_3[0]);
    a1_3.push_back(sigmoid(z1_3[0]));

    vector<double> a1 = {a1_1[0], a1_2[0], a1_3[0]};

    z2_1.push_back(dot(a1, w2_1) + b2_1[0]);
    a2_1.push_back(sigmoid(z2_1[0]));

    cout << a2_1[0] << endl;
    return 0;
}