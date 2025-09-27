#pragma once
#include "Coalition.h"
class Simulation;
class JoinPolicy {
public:
    virtual void join(int ,int ,Simulation& sim,const std::vector<int>&,const std::vector<Coalition*>&) const =0 ;
    virtual ~JoinPolicy()=default;
    virtual JoinPolicy* clone()=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    void join(int ,int,Simulation& sim,const std::vector<int>&,const std::vector<Coalition*>&) const override;
    JoinPolicy* clone() override;
};

class LastOfferJoinPolicy : public JoinPolicy {
    void join(int ,int, Simulation& sim,const std::vector<int>&,const std::vector<Coalition*>&) const override;
    JoinPolicy* clone() override;
};