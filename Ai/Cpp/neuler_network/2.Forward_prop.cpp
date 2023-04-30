#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef double long ld;
double sigmoid(double x){
    return 1 / (1 + exp(-x));
}
double dot(vector<double> x, vector<double> w){
    double sum = 0;
    for(int i = 0; i < x.size(); i++){
        sum += x[i] * w[i];
    }
    return sum;
}
vector<double> dense(vector<double> a_in, vector<vector<double>> w, vector<double> b){
    double unit = w.size(); 
    vector<double> z, a_out(unit,0); 
    double sum = 0;
    for(int i = 0; i < unit; i++){
        z.push_back(dot(a_in, w[i]) + b[i]);
        a_out[i] = sigmoid(z[i]);
    }
    return a_out;
}
vector<double> sequential(vector<double> x, vector<vector<double>> w, vector<double> b){
    vector<double> a1 = dense(x, w, b);
    vector<double> a2 = dense(a1, w, b);
    return a2;
}
vector<double> my_predict()

int main(){
    vector<vector<double>> W = {{1,2},{-3,4},{5,-6}};
    vector<double> b = {-1,1,2};
    vector<double> a_in ={-2,4};

}