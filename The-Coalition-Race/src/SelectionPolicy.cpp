
#include "SelectionPolicy.h"

void MandatesSelectionPolicy::select(Graph &g, int aId , int pId ,const vector<int>& parties_to_offer) const {
    int max_mandates=0;
    int party_to_offer;
    for (int i:parties_to_offer){
        if(g.getParty(i).getMandates()>max_mandates){
            max_mandates = g.getParty(i).getMandates();
            party_to_offer = i;
        }
    }
    g.addOfferToParty(party_to_offer,aId);
}

SelectionPolicy *MandatesSelectionPolicy::clone() {
    return new MandatesSelectionPolicy(*this);
}

void EdgeWeightSelectionPolicy::select(Graph &g, int aId , int pId ,const vector<int> &parties_to_offer) const {
    int max_weight=0;
    int party_to_offer;
    for(int i:parties_to_offer){
        if(g.getEdgeWeight(pId,i)>max_weight){
            max_weight=g.getEdgeWeight(pId,i);
            party_to_offer=i;
        }
    }
    g.addOfferToParty(party_to_offer,aId);
}

SelectionPolicy *EdgeWeightSelectionPolicy::clone() {
    return new EdgeWeightSelectionPolicy(*this);
}
