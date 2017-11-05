//
//  unittest.cpp
//  SV Project
//
//  Created by Samara Frey on 03.11.17.
//  Copyright © 2017 Samara Frey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "neuron.hpp"
#include "gtest/include/gtest/gtest.h"
#include "constants.h"
#include <cmath>

/**
 * TESTING: that membrane potential is never over 30. Technically the membrane potential can overexceed the threshold, but only to a certain amount.
 */

TEST (NeuronTest, MembranePotential){
    Neuron neuron;
    
    neuron.update(1, 0);
    ASSERT_TRUE(neuron.getMemPot() < 30);
}

/**
 * TESTING: the membrane potential can never be smaller then 0 having an exhibitory neuron
 */

TEST (NeuronTest, ExMembranePotential){
    Exhibitory neuron;
    
    neuron.update(1, 0);
    ASSERT_TRUE(neuron.getMemPot() >= 0);
}

/**
 * TESTING: check that the clock is the same as the global time
 */

TEST (NeuronTest, TimeComparison){
    Neuron neuron;
    
    neuron.update(1, 0);
    ASSERT_EQ(neuron.getClock(), 1);
}

/**
 * TESTING: check that the connection vector increases in size if a neuron gets a connection (first element is always nullptr, so size = amount of connection+1)
 */
TEST (NeuronTest, ConnectionSize){
    Neuron neuron1;
    Neuron neuron2;
    neuron1.addConnect(& neuron2);
    
    size_t compare = 2;
    ASSERT_EQ(neuron1.getConnecSize(), compare);
}

/**
 * TESTING: if the external current is 0, then the neuron will not spike. If the external current is incredibely high, it must have spiked and therefore increase the spikeVectSize by 1.
 */

TEST (NeuronTest, Spiked){
    Neuron neuron;
    neuron.update(0, 0);
    
    //!< the neuron can't have spiked at time 0 without an external current
    ASSERT_NE(neuron.spiked(), true);
    
    //!< Make neuron spike -> it spikes in the update and increases the size of the spike Vect
    neuron.update(0, 1000);
    ASSERT_TRUE(neuron.getSpikeVectSize() == 1);
}

/**
 * TESTING: If the external current is incredibely high, it must have spiked and therefore have a membrane potential that is 0.
 */

TEST (NeuronTest, ResetMembranePot){
    Neuron neuron;
    
    neuron.update(0, 1000);
    ASSERT_TRUE(neuron.getMemPot() == 0);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


