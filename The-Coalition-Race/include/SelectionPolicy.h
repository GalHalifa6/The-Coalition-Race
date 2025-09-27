#pragma once
#include "Graph.h"
class SelectionPolicy {
public:
    virtual void select(Graph&,int,int,const vector<int>&) const=0;
    virtual ~SelectionPolicy() = default;
    virtual SelectionPolicy* clone() =0;
};

class MandatesSelectionPolicy: public SelectionPolicy{
    void select(Graph&,int,int,const vector<int>&) const override;
    SelectionPolicy* clone() override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    void select(Graph&,int,int,const vector<int>&) const override;
    SelectionPolicy* clone() override;
};