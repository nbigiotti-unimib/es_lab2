#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"

int main (int argc , char * argv[]) {
    TH1F * h1_ptr = new TH1F ("h1" , "Istogramma esercizio 1" , 3 , 0. , 1.);
    h1_ptr->Fill(0.2);
    h1_ptr->Fill(0.45);
    h1_ptr->Fill(0.3);
    h1_ptr->Fill(0.1);
    h1_ptr->Fill(0.37);

    TApplication myApp ("myApp" , &argc , argv);
        TCanvas c1;
        h1_ptr->Draw();
        c1.Print("misc_output/es31_h1.png" , "png");
    myApp.Run();
    delete h1_ptr;
    
    return 0;
}
