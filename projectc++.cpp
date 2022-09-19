#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double sredniaArytm(const double z[]){
    double srednia=0.00;
    for(unsigned int i=0; i<20; i++){
        srednia+=z[i];
    }
    return srednia/20;
}
//---------------------------------Koniec funkcji - Wyznaczanie X----------------------------//
void zamien(double &x, double &y){
    double pom=y;
    y=x;
    x=pom;
}
double sortowanieMediana(double y[]){
    for(unsigned int i=0;i<20;i++){
        for(unsigned int j=i+1; j<20; j++ ){
            if(y[i]>y[j]) zamien(y[i],y[j]);
        }
    }
    return (y[9]+y[10])/2.00;
}
//---------------------------------Koniec funkcji - Srednia/Mediana/Odchylenie_Standardowe----------------------------//
double odlegloscPunktow(double xa, double xb, double ya, double yb){
    return sqrt(pow(xb-xa,2)+pow(yb-ya,2));
}
//---------------------------------Koniec funkcji - Pole Powierzchni----------------------------//
double calkowanieInterpolacja(double tabX[], double x){
        if(x<=0.210526) return tabX[0]*pow(x,4)+tabX[1]*pow(x,3)+tabX[2]*pow(x,2)+tabX[3]*pow(x,1)+tabX[4]*1;
        else if(x>0.210526 && x<=0.421053) return tabX[5]*pow(x,4)+tabX[6]*pow(x,3)+tabX[7]*pow(x,2)+tabX[8]*pow(x,1)+tabX[9]*1;
        else if(x>0.421053 && x<=0.631579) return tabX[10]*pow(x,4)+tabX[11]*pow(x,3)+tabX[12]*pow(x,2)+tabX[13]*pow(x,1)+tabX[14]*1;
        else if(x>0.631579 && x<=0.842105) return tabX[15]*pow(x,4)+tabX[16]*pow(x,3)+tabX[17]*pow(x,2)+tabX[18]*pow(x,1)+tabX[19]*1;
        else return tabX[20]*pow(x,3)+tabX[21]*pow(x,2)+tabX[22]*pow(x,1)+tabX[23]*1;
    }
double calkowanieAproksymacja(double tabX[], double x ){
        return tabX[0]*x+tabX[1];
    }
//---------------------------------Koniec funkcji - Calkowanie funkcji----------------------------//
double wyliczPochodna(double y1, double y2, double z1, double z2){
    return ((z1-z2)/(y1-y2));
}
//---------------------------------Koniec funkcji - pochodne czastkowe----------------------------//
void monotonicznosc(double pochodne[], double x[]){
    for(unsigned int i=0; i<20; i++){
        if(pochodne[i]<0) cout<<"Pochodna funkcji w punkcie "<<x[i]<<" maleje.\n";
        else cout<<"Pochodna funkcji w punkcie "<<x[i]<<" rosnie.\n";
    }
    cout<<endl<<endl;
}
//---------------------------------Koniec funkcji - monotonicznosc----------------------------//
void przerywnik(string tekst){
    cout<<endl<<endl;
    cout<<setw(80)<<setfill('-')<<tekst<<"------------------------------------------------------------"<<endl;
    cout<<endl<<endl;
}
int main(int argc, char** argv){
    double mainZ[400]={4.05, 5.8051, 19.8265, -30.1187, -14.7903, 125.275, -54.7137, -169.865, 269.066, 97.4983, -460.086, 249.654, 518.658, -686.123, -144.1, 1079.66, -526.947, -934.832, 1414.09, 251.808, 56.0546, 57.8097, 71.8311, 21.886, 37.2143, 177.28, -2.7091, -117.86, 321.071, 149.503, -408.082, 301.659, 570.663, -634.118, -92.0954, 1131.66, -474.943, -882.827, 1466.09, 303.812, 77.2344, 78.9895, 93.0109, 43.0658, 58.3941, 198.459, 18.4707, -96.6803, 342.25, 170.683, -386.902, 322.839, 591.843, -612.938, -70.9157, 1152.84, -453.763, -861.647, 1487.27, 324.992, -74.8695, -73.1144, -59.093, -109.038, -93.7098, 46.3555, -133.633, -248.784, 190.146, 18.5788, -539.006, 170.735, 439.739, -765.042, -223.02, 1000.74, -605.867, -1013.75, 1335.17, 172.888, -217.287, -215.532, -201.511, -251.456, -236.128, -96.0622, -276.051, -391.202, 47.7287, -123.839, -681.424, 28.317, 297.321, -907.46, -365.437, 858.321, -748.284, -1156.17, 1192.75, 30.4705, -60.9252, -59.1701, -45.1487, -95.0938, -79.7655, 60.2999, -119.689, -234.84, 204.091, 32.5232, -525.062, 184.679, 453.683, -751.098, -209.075, 1014.68, -591.922, -999.807, 1349.11, 186.833, 278.796, 280.551, 294.572, 244.627, 259.956, 400.021, 220.032, 104.881, 543.812, 372.244, -185.341, 524.4, 793.404, -411.377, 130.646, 1354.4, -252.201, -660.086, 1688.84, 526.554, 317.69, 319.445, 333.467, 283.522, 298.85, 438.915, 258.926, 143.776, 582.706, 411.139, -146.446, 563.294, 832.298, -372.483, 169.54, 1393.3, -213.307, -621.192, 1727.73, 565.448, -114.095, -112.34, -98.3189, -148.264, -132.936, 7.12963, -172.859, -288.01, 150.921, -20.6471, -578.232, 131.509, 400.513, -804.268, -262.245, 961.513, -645.093, -1052.98, 1295.94, 133.662, -498.861, -497.106, -483.085, -533.03, -517.702, -377.636, -557.625, -672.776, -233.845, -405.413, -962.998, -253.257, 15.7469, -1189.03, -647.011, 576.747, -1029.86, -1437.74, 911.179, -251.104, -249.787, -248.032, -234.011, -283.956, -268.628, -128.562, -308.551, -423.702, 15.2286, -156.339, -713.924, -4.18312, 264.821, -939.96, -397.937, 825.821, -780.785, -1188.67, 1160.25, -2.02966, 412.531, 414.286, 428.308, 378.363, 393.691, 533.756, 353.768, 238.617, 677.547, 505.98, -51.6051, 658.136, 927.14, -277.641, 264.381, 1488.14, -118.466, -526.35, 1822.57, 660.289, 611.55, 613.305, 627.326, 577.381, 592.709, 732.775, 552.786, 437.635, 876.566, 704.998, 147.413, 857.154, 1126.16, -78.6232, 463.399, 1687.16, 80.5523, -327.332, 2021.59, 859.307, -28.1293, -26.3742, -12.3528, -62.298, -46.9696, 93.0957, -86.893, -202.044, 236.887, 65.319, -492.266, 217.475, 486.479, -718.302, -176.279, 1047.48, -559.127, -967.011, 1381.91, 219.628, -744.914, -743.159, -729.138, -779.083, -763.755, -623.689, -803.678, -918.829, -479.898, -651.466, -1209.05, -499.31, -230.306, -1435.09, -893.064, 330.694, -1275.91, -1683.8, 665.126, -497.157, -542.907, -541.151, -527.13, -577.075, -561.747, -421.681, -601.67, -716.821, -277.891, -449.458, -1007.04, -297.302, -28.2984, -1233.08, -691.057, 532.702, -1073.9, -1481.79, 867.134, -295.149, 427.646, 429.401, 443.423, 393.477, 408.806, 548.871, 368.882, 253.731, 692.662, 521.094, -36.4904, 673.25, 942.254, -262.527, 279.496, 1503.25, -103.351, -511.236, 1837.69, 675.404, 917.338, 919.094, 933.115, 883.17, 898.498, 1038.56, 858.575, 743.424, 1182.35, 1010.79, 453.202, 1162.94, 1431.95, 227.166, 769.188, 1992.95, 386.341, -21.5433, 2327.38, 1165.1, 182.294, 184.049, 198.07, 148.125, 163.454, 303.519, 123.53, 8.37923, 447.31, 275.742, -281.843, 427.898, 696.902, -507.879, 34.1438, 1257.9, -348.703, -756.588, 1592.33, 430.052, -914.309, -912.554, -898.532, -948.477, -933.149, -793.084, -973.072, -1088.22, -649.293, -820.86, -1378.45, -668.704, -399.701, -1604.48, -1062.46, 161.3, -1445.31, -1853.19, 495.731, -666.551};
    double x[20]={0,0.0526316,0.105263,0.157895,0.210526,0.263158,0.315789,0.368421,0.421053,0.473684,0.526316,0.578947,0.631579,0.684211,0.736842,0.789474,0.842105,0.894737,0.947368,1};
    double sredniaAryt[20]={}, secondZ[20]={}, odchylenia[20]={}, szukanieX[20][2]={},  y[20]={}, yy[20]={};
    unsigned k=0, pom=0;
    for(unsigned int i=0; i<400; i+=20){
        for(unsigned int j=0; j<20; j++){
            secondZ[j]=mainZ[i+j];
        }
        sredniaAryt[k]=sredniaArytm(secondZ);
        for(unsigned int m=0; m<20; m++){
            secondZ[m]=pow(secondZ[m]-sredniaAryt[k],2);   //Policzenie roznicy kwadratow do wzoru
        }
        odchylenia[k]=sqrt(sredniaArytm(secondZ));
        szukanieX[k][0]=odchylenia[k];
        szukanieX[k][1]=x[k];
        k++;        
    } //Wyznaczenie maksymalnego odchylenia standardowego
        double max=szukanieX[0][0];
        for(unsigned int i=1;i<20;i++){
            if(max<szukanieX[i][0]){
                max=szukanieX[i][0];
                pom=i;
            } 
        }
        cout<<"Najwieksze srednie odchylenie dla podanych danych wzgledem wierszy OX dla x="<<szukanieX[pom][1]<<" i wynosi: "<<setprecision(15)<<max<<endl;
        cout<<setprecision(10);
        unsigned int pomocnicza1=0, wartoscI=20*pom;
            for(unsigned int j=0;j<20;j++){
                if(pom==j){
                    for(unsigned int i=wartoscI;i<wartoscI+20;i++){
                    y[pomocnicza1]=mainZ[i];
                    yy[pomocnicza1]=mainZ[i];
                    pomocnicza1++;
                    }
                }
            }
    //---------------------------Wyznaczanie funkcji aproksymujacej - Metoda Najmniejszych Kwadratow ----------------------------------------//
        double suma_x=0.00, suma_y=0.00, iloczynXY=0.00, sumaKwadratowX=0.00; 
        for(unsigned int i=0; i<20; i++){
            suma_x+=x[i]; //Suma X
            suma_y+=y[i]; //Suma y
            iloczynXY+=(x[i]*y[i]);
            sumaKwadratowX+=x[i]*x[i];
        }
        double aa = ((20*iloczynXY)-(suma_x*suma_y))/(20*sumaKwadratowX-(suma_x*suma_x));
        double bb = (0.05)*(suma_y-(aa*suma_x));
        przerywnik("Funkcja aproksymujaca");
        cout<<"Wzor funkcji aproksymujacej: W(x)= "<<aa<<"x ";
        if(bb>0.00) cout<<"+ "<<bb<<endl;
        else cout<<bb<<endl;
    //---------------------------Wyznaczanie sredniej/mediany/odchylenia standardowego----------------------------------------//
        przerywnik("Srednia / Mediana / Odchylenie dla wybranego wiersza");
        cout<<"Srednia: "<<sredniaAryt[pom]<<endl;
        //Mediana
        cout<<"Mediana: "<<sortowanieMediana(yy)<<endl;
        cout<<"Odchylenie standardowe: "<<max <<endl;
    //---------------------------Pole Powierzchni----------------------------------------//
        double polePowierzchni=0.00;
        przerywnik("Pole powierzchni");
        for(unsigned int i=1; i<20; i++){
            polePowierzchni+=odlegloscPunktow(x[i-1],x[i],y[i-1],y[i]);
        }
        cout<<"Pole powierzchni: "<<polePowierzchni<<endl;
    //--------------------------Całkowanie funkcji interpolacyjnych ----------------------------------------//
         double xFourToZerox4[24]={-1214770.681390, 490872.254639, -57052.560952, 1791.558857, -481.417000,-3313195.297398, 3564879.560243, -1366838.995262, 219748.781200, -12876,15890148.110068, -34287340.361557, 27456107.843447, -9668050.341102, 1262493.137603, 36956213.174132, -107123914.757894,  115857019.643662, -55409449.801239,  9887308.733120, 5323963.155411,-15055481.634138,14142300.978777,-4413217.530051};
        //Macierz pomocnicza do sumowania wartosci calek
        const unsigned int n=10000;
        double doObliczenWartosci[10001]={}, a=0.00, b=1.00, calkaInterpolacja=0.00,p=(double)(b-a)/n,pomx=0.00, pomx1=0.00;
        doObliczenWartosci[0]=0;
        //Obliczenie wartosci kazdego 'x' do metody trapezow
        for(unsigned int i=1; i<=n; i++) doObliczenWartosci[i]=doObliczenWartosci[i-1]+p;
        //Wyznaczanie calki z danego x'a podstawiajac pod funkcje interpolacyjne
        for(unsigned int i=0; i<=n-1; i++){
            pomx=calkowanieInterpolacja(xFourToZerox4,doObliczenWartosci[i]);
            pomx1=calkowanieInterpolacja(xFourToZerox4, doObliczenWartosci[i+1]);
            calkaInterpolacja+=(((pomx+pomx1)/2)*p);
        }
        przerywnik("Calkowanie funkcji interpolacyjnych");
        cout<<"Calka z funkcji interpolacyjnej wynosi: "<<calkaInterpolacja<<"\n";
    //--------------------------------------------------Całkowanie funkcji aproksymacyjnej -------------------------------------------------------//
        //Do obliczeń posłużyłem się już istniejącą macierzą z wyliczania całki z funkcji interpolacji oraz innymi zmiennymi
        double xApro[2]={-436.951,-345.743},calkaAproksymacja=0.00;
        pomx=0.00, pomx1=0.00;
        for(unsigned int i=0; i<=n-1; i++){
            pomx=calkowanieAproksymacja(xApro,doObliczenWartosci[i]);
            pomx1=calkowanieAproksymacja(xApro, doObliczenWartosci[i+1]);
            calkaAproksymacja+=((pomx+pomx1)/2)*p;
        }
        przerywnik("Calkowanie funkcji aproksymujacej");
        cout<<"Calka z funkcji aproksymujacej wynosi: "<<calkaAproksymacja<<"\n";
    //--------------------------------------------------Wyznaczanie pochodnych cząstkowych i monotoniczność-------------------------------------------------------//
        double pochodne[20]={};
        pochodne[0]=((y[1]-y[0])/(x[1]-x[0])), pochodne[19]=((y[19]-y[18])/(x[19]-x[18]));
        for(unsigned int i=1; i<19; i++){
            pochodne[i]=wyliczPochodna(x[i+1],x[i-1],y[i+1],y[i-1]);
        }
        przerywnik("Pochodne czastkowe");
        for(unsigned int i=0; i<20;i++) cout<<"Pochodna z punktu: "<<x[i]<<" wynosi : "<<pochodne[i]<<"\n";
        przerywnik("Monotonicznosc");
        monotonicznosc(pochodne,x);
        for(unsigned i=0;i<20;i++) cout<<"x: "<<x[i]<<" y: "<<y[i]<<endl;
        return 0;
}