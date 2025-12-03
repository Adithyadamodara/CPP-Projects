#include <iostream>
#include <vector>
using namespace std;

double hypothesis(double x,double& w, double&b){
    return w*x + b;
}

double cost(vector<double>& x,vector<double>& y, double& w, double& b){
    double total=0.0;
    int n = x.size();
    for(int i=0;i<n;i++){
        double d = hypothesis(x[i],w,b);
        total += d*d;
    }
    return total/(2*n);
}

void gradient_descent(vector<double>& x,vector<double>& y, double& w, double& b, double lr, int iterations){
    
    const int n = x.size();
    for(int it=0;it<iterations;it++){
        double dw = 0.0, db =0.0;
        for(int i=0;i<n;i++){
            double d = hypothesis(x[i], w, b) - y[i];
            dw += d*x[i];
            db += d;
        }
        dw/=n;
        db/=n;
        w -= lr*dw;
        b -= lr*db;
        if(it % 100 == 0 ){
            cout<<"Iteration: "<<it<<endl;
            cout<<"weight =  "<<w<<" bias = "<<b<<endl;
        }
    }  


}

int main(){
    vector<double> x = {1,2,3,4,5};
    vector<double> y = {2,4,6,8,10};

    double weight=0.0, bias=0.0;
    double learning_rate = 0.01;
    int iterations=1000;

    gradient_descent(x, y, weight, bias, learning_rate, iterations);
    
    cout<<"Final Model: y = "<<weight<<" * x +"<<bias;
    cout<<"For prediction, x = 3, y = "<<hypothesis(3,weight, bias);

    
    return 0;
}