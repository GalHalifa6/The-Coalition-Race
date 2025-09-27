#include "Party.h"
#include <iostream>
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) ,
counter(0),offers(new vector<int>),coalitions()
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
    if (getState()==Waiting||getState()==Joined) return;
    if (getState()==CollectingOffers) counter++;
    if (counter==3) {
        mJoinPolicy->join(mId, getMandates(), s, *offers, coalitions);
    }
}

vector<int>& Party::getOffers() const{
    return *offers;
}

void Party::addOffer(int aId){
    offers->push_back(aId);
}


void Party::setCoalitions(const vector<Coalition *>& co) {
    coalitions=co;
}

Party::~Party() {
    delete offers;
    delete mJoinPolicy;
}

Party::Party(const Party & other):mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy->clone()),mState(other.mState)
,counter(other.counter),offers(new vector<int>),coalitions(other.coalitions){
 for(int i:*other.offers){
     offers->push_back(i);
    }
}

Party &Party::operator=(const Party & other) {
    if (this == &other) return *this;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    counter = other.counter;
    mJoinPolicy = other.mJoinPolicy->clone();
    coalitions = other.coalitions;
    offers = new std::vector<int>;
    for (int i : *other.offers) {
        offers->push_back(i);
    }
    return *this;
}

Party::Party(Party &&other) noexcept:mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy),mState(other.mState)
        ,counter(other.counter),offers(other.offers),coalitions(other.coalitions) {
    other.mJoinPolicy = nullptr;
    other.offers = nullptr;
}

Party &Party::operator=(Party &&other) noexcept{
    if (this == &other) return *this;
    mId = other.mId;
    mName = other.mName;
    mMandates = other.mMandates;
    mState = other.mState;
    counter = other.counter;
    mJoinPolicy = other.mJoinPolicy;
    offers = other.offers;
    other.offers= nullptr;
    other.mJoinPolicy= nullptr;
    return *this;
}

