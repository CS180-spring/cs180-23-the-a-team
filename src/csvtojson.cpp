#include "csvtojson.h"

using namespace std;
using namespace jsoncons;

csvtojson::csvtojson(){}

void csvtojson::addjson(string name)
{
    //Using small amounts of code from: https://danielaparker.github.io/jsoncons/#A5
    ifstream is(name);

    csv::csv_options options;
    options.assume_header(true)
           .trim(true)
           .column_types("string");
    ojson convertedtext = csv::decode_csv<ojson>(is, options);

    string newfile = "jsonof_" + name +".json";
    ofstream o(newfile);
    o << pretty_print(convertedtext);

}
