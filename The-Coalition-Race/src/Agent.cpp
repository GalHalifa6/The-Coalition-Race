#include "Agent.h"

#include <iostream>
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
,myCoalition(),myGraph()
{
    // You can change the implementation of the constructor, but not the signature!
}
Agent::Agent(): mAgentId(),mPartyId(),mSelectionPolicy(),myCoalition(),myGraph(){}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    vector<int> *parties_to_offer = new vector<int>;
    bool did_coalition_offer;
    for (int i=0; i<myGraph->getNumVertices();i++){
        did_coalition_offer=false;
        for(int j:myGraph->getParty(i).getOffers()){
                if (myCoalition->isAgent(j))
                {
                    did_coalition_offer=true;
                    break;
                }
            }

        if(myGraph->getParty(i).getState()==Joined||myGraph->getEdgeWeight(i,mPartyId)==0||did_coalition_offer) continue;
        parties_to_offer->push_back(i);
    }
    if(!parties_to_offer->empty())
        mSelectionPolicy->select(*myGraph,mAgentId,mPartyId,*parties_to_offer);
    delete parties_to_offer;
}


void Agent::setCoalition(Coalition *coalition) {
    myCoalition=coalition;
}

Agent::Agent(const Agent &other):mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->clone())
,myCoalition(other.myCoalition),myGraph(other.myGraph) {
}

Agent::~Agent() {
    delete mSelectionPolicy;
    myGraph = nullptr;
    if (myCoalition != nullptr) {
        if (myCoalition->checkSharedPointer() == 1) {
            delete myCoalition;
        } else {
            myCoalition->decSharedPointer();
            myCoalition= nullptr;
        }
    }
}
Agent &Agent::operator=(const Agent & other) {
    if(this == &other) return *this;
    else{
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        myGraph = other.myGraph;
        myCoalition = other.myCoalition;
        return *this;
    }
}

Agent::Agent(Agent &&other) noexcept :mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy)
,myCoalition(other.myCoalition),myGraph(other.myGraph){
    other.mSelectionPolicy = nullptr;
    other.myGraph = nullptr;
    other.myCoalition = nullptr;
}

Agent &Agent::operator=(Agent && other)  noexcept {
    if(this == &other) return *this;
    else{
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        myGraph = other.myGraph;
        myCoalition = other.myCoalition;
        other.myGraph= nullptr;
        other.mSelectionPolicy= nullptr;
        other.myCoalition = nullptr;
        return *this;
    }
}

void Agent::setGraph(Graph *g) {
    myGraph=g;
}

Agent Agent::clone(int pId, int aId) {
    Agent a(aId,pId,mSelectionPolicy->clone());
    a.setGraph(myGraph);
    a.setCoalition(myCoalition);
    return a;
}



