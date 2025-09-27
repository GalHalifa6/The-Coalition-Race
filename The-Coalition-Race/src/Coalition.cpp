
#include "../include/Coalition.h"

Coalition::Coalition(int aId, int pId,int mmandates):shared_pointer_agents(1),last_known_size(1),agents_in_coalition(),parties_in_coalition(),mandates(mmandates) {
    agents_in_coalition.push_back(aId);
    parties_in_coalition.push_back(pId);
}

void Coalition::updateCoalition(int aId, int pId , int mmandates) {
    shared_pointer_agents++;
    agents_in_coalition.push_back(aId);
    parties_in_coalition.push_back(pId);
    mandates = mandates + mmandates;
}

int Coalition::getMandates() const {
    return mandates;
}

const vector<int> &Coalition::getAids() {
    return agents_in_coalition;
}

const vector<int> &Coalition::getPids() {
    return parties_in_coalition;
}

int Coalition::checkSharedPointer() const {
    return shared_pointer_agents;
}

void Coalition::decSharedPointer() {
    shared_pointer_agents--;
}
void Coalition::incSharedPointer(){
    shared_pointer_agents++;
}

bool Coalition::checkForUpdates() {
    int curr_size=agents_in_coalition.size();
    if (last_known_size!=curr_size) {
        last_known_size++;
        return true;
    }
    else return false;
}

bool Coalition::isAgent(int aId) {
    for (int i: agents_in_coalition){
        if (i==aId) return true;
    }
    return false;
}

void Coalition::updateLastAgent(int aId) {
    agents_in_coalition[agents_in_coalition.size()-1]=aId;
}



