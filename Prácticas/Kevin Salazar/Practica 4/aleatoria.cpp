#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main(){
    
    int m=50;
    Mat img = imread("coliseo.jpg");
    Mat mapa1(img.size(), CV_32FC1);
    Mat mapa2(img.size(), CV_32FC1);
    for (int y= 0; 
         y<img.size().height; y++)
    for (int x= 0; x<img.size().width; x++) {
        mapa1.at<float>(y, x)= x+rand()%(2*m+1) - m;     // Mapa 1
        mapa2.at<float>(y, x)= y+rand()%(2*m+1) - m;     // Mapa 2
    }
    Mat resultado;
    remap (img, resultado, mapa1, mapa2, INTER_NEAREST);
    imwrite ( "aleatoria50.jpg", resultado);
    return 0;
    

}
