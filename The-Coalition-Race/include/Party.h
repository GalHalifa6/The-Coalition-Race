#pragma once
#include <string>
#include <vector>
#include "JoinPolicy.h"

using std::vector;
using std::string;
class Coalition;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void setCoalitions(const vector<Coalition*>&);
    vector<int>& getOffers() const;
    void addOffer(int aId);
    //rule of 5
    ~Party();
    Party(const Party&);
    Party& operator=(const Party&);
    Party(Party&&) noexcept;
    Party& operator=(Party&&) noexcept;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int counter;
    vector<int>* offers;
    vector<Coalition*> coalitions;
};
