#include<iostream>
using namespace std;

int main(){
    int replicantes, replicantes_error, humanos, humanos_error;
    while(cin >> replicantes >> replicantes_error >> humanos >> humanos_error){
        double perc_error_rep = (double) replicantes_error / replicantes;
        double perc_error_hum = (double) humanos_error / humanos;
        int rep_ciudad, hum_ciudad;
        cin >> hum_ciudad >> rep_ciudad;
        
        double retirados = perc_error_hum * hum_ciudad + (1- perc_error_rep) * rep_ciudad;
        if (perc_error_hum * hum_ciudad > 0.1 * retirados) cout << "SUSPENDE\n";
        else cout << "APRUEBA\n";
    }
    return 0;
}
