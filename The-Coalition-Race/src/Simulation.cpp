#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) ,coalitions()
{
    // You can change the implementation of the constructor, but not the signature!
    int size= mAgents.size();
    for (int i=0 ; i<size ; i++){
        Coalition* coalition = new Coalition(mAgents[i].getId(), mAgents[i].getPartyId(), getParty(mAgents[i].getPartyId()).getMandates());
        mAgents[i].setCoalition(coalition);
        mAgents[i].setGraph(&mGraph);
        coalitions.push_back(coalition);
    }
    mGraph.setCoalitionsToParty(coalitions);
}



void Simulation::step() {
    // TODO: implement this method
    for (int i = 0; i < mGraph.getNumVertices(); i++) {
        mGraph.invokePartyStep(i,*this);
        for (Coalition *coalition : coalitions){
            if (coalition->checkForUpdates()){
                //clone last agent in getaids
                mAgents.push_back(mAgents[coalition->getAids()[coalition->getAids().size()-1]].clone(i,mAgents.size()));
                coalition->updateLastAgent(mAgents.size()-1);
                mGraph.setPartyToJoined(i);
            }
        }
    }
    int size=mAgents.size();
    for (int i=0; i<size ; i++){
        mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    for (Coalition *coalition: coalitions){
        if (coalition->getMandates()>60) return true;
    }
    bool is_all_joined=true;
    for (int i = 0; i < mGraph.getNumVertices();i++) {
        if (getParty(i).getState() != Joined) {
            is_all_joined = false;
            break;
        }
    }
    return is_all_joined;
}


const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector < vector<int>> parties_by_coalitions;
    for (Coalition *coalition : coalitions) {
        parties_by_coalitions.push_back(coalition->getPids());
    }
    return parties_by_coalitions;
}

