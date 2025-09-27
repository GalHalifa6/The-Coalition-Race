
#include "JoinPolicy.h"

void MandatesJoinPolicy::join(int pId,int mandates,Simulation &sim,const std::vector<int>& offers,const std::vector<Coalition*>& coalitions) const {
    int max_mandates=0;
    int accepted_agent=-1;
    Coalition* coalition_to_update;
    for (int i:offers){
        for(Coalition *coalition:coalitions){
            if (coalition->isAgent(i)){
                if(coalition->getMandates()>max_mandates){
                    max_mandates = coalition->getMandates();
                    accepted_agent=i;
                    coalition_to_update = coalition;
                }
            }
        }
    }
    coalition_to_update->updateCoalition(accepted_agent,pId,mandates);
}

JoinPolicy *MandatesJoinPolicy::clone() {
    return new MandatesJoinPolicy(*this);
}

void LastOfferJoinPolicy::join(int pId,int mandates,Simulation &sim,const std::vector<int>& offers,const std::vector<Coalition*>& coalitions) const {
    Coalition * coalition_to_update;
    for (Coalition *coalition:coalitions){
        if(coalition->isAgent(offers[offers.size()-1])) coalition_to_update=coalition;
    }
    coalition_to_update->updateCoalition(offers[offers.size()-1],pId,mandates);
}

JoinPolicy *LastOfferJoinPolicy::clone() {
    return new LastOfferJoinPolicy(*this);
}
