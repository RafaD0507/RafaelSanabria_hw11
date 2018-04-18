#include <iostream>
using namespace std;

// Aqui se inician las funciones, G y M
int G, M;
double dvdt(double x, double v, double t);
double dxdt(double x, double v, double t);

int main(){
  G = 10;
  M = 1000;
  // Parametros para el problema
  double x_inicial = 100;
  double m = 1;
  double v = 1;
  double dt = 0.001;
  double x_final = 0.1*x_inicial;
  double x = x_inicial;
  double t = 0;
  double kv, kv_1, kv_2, kv_3, kv_4;
  double kx, kx_1, kx_2, kx_3, kx_4;
  
  while(x>=x_final){
    cout << x << " "<< v << " "<< t << endl;

    //Aqui se calculan los ks para el metodo de Runge-Kutta
    kx_1 = dxdt(x, v, t);
    kv_1 = dvdt(x, v, t);

    kx_2 = dxdt(x+kx_1*dt/2, v+kv_1*dt/2, t+dt/2);
    kv_2 = dvdt(x+kx_1*dt/2, v+kv_1*dt/2, t+dt/2);

    kx_3 = dxdt(x+kx_2*dt/2, v+kv_2*dt/2, t+dt/2);
    kv_3 = dvdt(x+kx_2*dt/2, v+kv_2*dt/2, t+dt/2);

    kx_4 = dxdt(x+kx_3*dt, v+kv_3*dt, t+dt);
    kv_4 = dvdt(x+kx_3*dt, v+kv_3*dt, t+dt);

    kv = (kv_1+2*kv_2+2*kv_3+kv_4)/6;
    kx = (kx_1+2*kx_2+2*kx_3+kx_4)/6;

    // Se evaluan los proximos valores
    v = v + dt*kv;
    x = x + dt*kx;
    t = t + dt;
  }

}

//Relaciones entre las variables
double dxdt(double x, double v, double t){
  return v;
}

double dvdt(double x, double v, double t){
  return -G*M/(x*x);
}
