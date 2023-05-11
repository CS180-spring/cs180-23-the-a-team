//file extension dat
#include <cmath>
#include <iostream>
#include <fstream>
#include <map>
double min = -10.0;
double max = 10.0;
double set = 0.2; //distance between two points on the plot

void plotGraph(double (*func)){

    ofstream fileoutput("outputgnu.dat")
    //for a key-value type

    for(auto const& [key, value] : outputgnu){
        fileoutput << key << " " << value << endl;
    }

    fileoutput.close();

   //gnu plot commands

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "plot 'data.dat' with lines\n");
    fflush(gnuplotPipe);
}
//testing other examples,
//math function example to graph with gnuplot
double sinFunc(double val) {
    return sin(val); 

}

int main() {

    plotGraph(sinFunc);

    //trying the json 

    map<string, int > data = {
       {
        "id" : "9873e87e879ueid",
        "Name" : "Farnaz",
        "Age" : "23",
        "College" : "UC Riverside"
    },
    {
        "id" : "98e89r8983009id",
        "Name" : "Golnaz",
        "Age" : "27",
        "College" : "UC Berkely"

    },
    {
        "id" : "7849920id",
        "Name" : "Emily",
        "Age" : "27",
        "College" : "UC Berkely"

    },
    {
        "id" : "976554322219id",
        "Name" : "John",
        "Age" : "39",
        "College" : "UC Berkely"

    },
    {
        "id" : "9898378747382id",
        "Name" : "Niloofar",
        "Age" : "30",
        "College" : "UCLA"

    }
    }

    plotGraph(data); 
    return 0; 
}
