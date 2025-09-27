#pragma once
#include <algorithm>
#include <vector>
#include "Graph.h"
#include "Coalition.h"
#include "SelectionPolicy.h"

class Agent
{
public:
    Agent();

    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent clone(int pId , int aId);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setCoalition(Coalition* coalition);
    void setGraph(Graph*);
    //rule of five
    Agent(const Agent&);
    ~Agent();
    Agent& operator=(const Agent&);
    Agent(Agent&&) noexcept ;
    Agent& operator=(Agent&&) noexcept ;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition* myCoalition;
    Graph* myGraph;
};
