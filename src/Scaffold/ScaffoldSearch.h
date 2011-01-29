//-----------------------------------------------
// Copyright 2010 Wellcome Trust Sanger Institute
// Written by Jared Simpson (js18@sanger.ac.uk)
// Released under the GPL
//-----------------------------------------------
//
// ScaffoldSearch - Find walks through a scaffold graph
//
#ifndef SCAFFOLDSEARCH_H
#define SCAFFOLDSEARCH_H

#include "GraphSearchTree.h"
#include "ScaffoldWalk.h"
#include "ScaffoldGraph.h"

typedef std::vector<ScaffoldVertexPtrVector> ScaffoldConnectedComponents;

//
struct ScaffoldWalkBuilder
{
    public:
        ScaffoldWalkBuilder(ScaffoldWalkVector& outWalks);
        ~ScaffoldWalkBuilder();

        // These three functions must be provided by the builder object
        // the generic graph code calls these to describe the walks through
        // the graph
        void startNewWalk(ScaffoldVertex* pStartVertex);
        void addEdge(ScaffoldEdge* pEdge);
        void finishCurrentWalk();

    private:
        ScaffoldWalkVector& m_outWalks;
        ScaffoldWalk* m_pCurrWalk;
};

//
namespace ScaffoldSearch
{
    void findVariantWalks(ScaffoldVertex* pX, 
                          EdgeDir initialDir, 
                          int maxDistance,
                          size_t maxWalks, 
                          ScaffoldWalkVector& outWalks);


    // Returns walks from pX to pY that exclusively
    // travel along primary links
    void findPrimaryWalks(ScaffoldVertex* pX,
                          ScaffoldVertex* pY,
                          EdgeDir intialDir,
                          int maxDistance,
                          size_t maxNodes, 
                          ScaffoldWalkVector& outWalks);


    // Compute the connected components of the scaffold graph
    void connectedComponents(ScaffoldGraph* pGraph);

    void printWalks(const ScaffoldWalkVector& walkVector);

};

#endif
