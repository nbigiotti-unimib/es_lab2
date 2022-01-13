#include <fstream>
#include <vector>

#include <TGraphErrors.h>
#include <TCanvas.h>

using namespace std;

int main() {
    vector<double> times , speeds , spd_err; 
    ifstream speed ("dati.txt" , ios::in);
    do {
        double tmp1 , tmp2 , tmp3;
        speed >> tmp1 >> tmp2 >> tmp3;
        times.push_back(tmp1);
        speeds.push_back(tmp2);
        spd_err.push_back(tmp3);
    } while (speed.eof() == false);

    TGraphErrors speed_graph;

    for(int i = 0 ; i < times.size() ; ++i) {
        speed_graph.SetPoint(i , times[i] , speeds[i]);
        speed_graph.SetPointError(i , 0. , spd_err[i]);
    }

    TCanvas c1;
    speed_graph.Draw();
    c1.Print("speed_graph.png" , "png");

    return 0;
}