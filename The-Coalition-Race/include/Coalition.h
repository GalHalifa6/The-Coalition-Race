#pragma once
#include <vector>

using std::vector;
class Coalition {
public:

    Coalition(int aId, int pId , int mandates);


    void updateCoalition(int aId , int pId ,int mmandates);
    int getMandates() const;
    bool isAgent(int i);
    bool checkForUpdates();
    void updateLastAgent(int aId);
    int checkSharedPointer() const;
    void decSharedPointer();
    void incSharedPointer();
    const vector<int>& getAids();
    const vector<int>& getPids();
private:
    int shared_pointer_agents;
    int last_known_size;
    vector<int> agents_in_coalition;
    vector<int> parties_in_coalition;
    int mandates;

};


