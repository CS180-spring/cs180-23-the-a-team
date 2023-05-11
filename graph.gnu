//researching and trying to implement working with a C++ library to be able to graph a json file data
//this is a good feature for data analysis fields.
//using the library gnuplot
//credit to toturial videos: https://www.youtube.com/watch?v=r9ROtHKxQdY
//https://www.youtube.com/watch?v=vL81B8STPnA
//https://www.youtube.com/watch?v=DHu8nyBSLxY
//http://stahlke.org/dan/gnuplot-iostream/
//configure boost c++ library 
//VC package + install boost
//gnuplot can be launched through terminal as well, a sample code be written that uses gnuplot and we can run the 
//gnu commands, then another window will pop up. 


//graph window size
set terminal png size 2000,1000
set multiplot
unset key
set output "output.png"
set yrange [0:0.8]
set mytrix 2
set style data histogram
set style histogram cluster gap 1
set style fill solid
set boxwidth 0.9
set xtics format
set grid ytics
set border lw 2
set xlabel :X-LABEL(Unit)"font ",18"
set xlabel :Y-LABEL(Unit)"font ",18"
set xlabel "X"
set ylabel "Y"
set xtics font ",15"
set ytics font ",15"

//open files to be plotted

//converting json to tsv and try to get the png graph from it.

jq -r '.data | map([.x, .y] | @tsv) | join("\n")' data.json > data.tsv


//command terminal 
//gnuplot gpraph.gnu
