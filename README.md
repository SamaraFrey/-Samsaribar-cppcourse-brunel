# -Samsaribar-cppcourse-brunel

----------------------
Introduction
----------------------

This programm is a simple simulation of the brain. It connects 12'500 neurons of different nature randomly together and calculates the membrane Potential depending on them as well as a random background noise of the brain. The different types of neurons are exhibitory and inhibitory, which differ in the value of J.
More over one obtains a spike.txt file while running the programm. This spike.txt contains the times of the spikes from all neurons, that occur during the given time interval. Later on, one can recreate the graph using Jupyter. These graphs have been added to this repository in pdf format. The values changing from graph to graph, are the ratio of the J of the different neurons as well as the lambda, which has been used for generating the background noise.

-------------------------
Stucture of the programm
-------------------------
This porgramm consists of 5 different files. The unittest is only used for using googletest, which allows the programmer to detect mistakes that could have been made and not been detected, because it might not be a compilation error.
The neuron.cpp and .hpp are the class of neurons. They will be used to create that "brain". The simulation of it all takes place in the main.cpp. There the "brain" is recreated, connected and updated for each timestep given.


----------------------
Issues
----------------------

This programm is not a correct representation of the brain, it is way to simplyfied. It is biologically not accurate. This has not been the aim of this project, therefore one can use this programm only  in this context and only for generating the graphs.
