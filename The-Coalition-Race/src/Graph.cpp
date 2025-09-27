#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

void Graph::invokePartyStep(int pId,Simulation& s){
    mVertices[pId].step(s);
}

void Graph::addOfferToParty(int pId, int aId){
    if (mVertices[pId].getState()==Waiting) mVertices[pId].setState(CollectingOffers);
    mVertices[pId].addOffer(aId);
}

void Graph::setCoalitionsToParty(const vector<Coalition*> & co) {
    for (int i=0;i<getNumVertices();i++){
        mVertices[i].setCoalitions(co);
    }
}

void Graph::setPartyToJoined(int i) {
    mVertices[i].setState(Joined);
}



