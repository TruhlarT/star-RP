/***************************************************************************
 *
 * $Id: StRpsCollection.h,v 2.3 2015/10/02 19:50:50 ullrich Exp $
 *
 * Author: Thomas Ullrich, Nov 2009
 ***************************************************************************
 *
 * Description:
 *
 ***************************************************************************
 *
 * $Log: StRpsCollection.h,v $
 * Revision 2.3  2015/10/02 19:50:50  ullrich
 * Added containers for tracks and points.
 *
 * Revision 2.2  2010/02/04 18:16:09  ullrich
 * Added new member mSiliconBunch and referring access methods.
 *
 * Revision 2.1  2009/11/23 22:18:25  ullrich
 * Initial Revision
 *
 **************************************************************************/
#ifndef StRpsCollection_hh
#define StRpsCollection_hh

#include "TObject.h" // "StObject.h"
#include "TClonesArray.h" // "StContainers.h"
#include "StRpsRomanPot.h"
#include "StRpsTrackPoint.h"
#include "StRpsTrack.h"
#include <vector> // added

using namespace std; // added

class StRpsCollection : public TObject {
public:
    StRpsCollection();
    ~StRpsCollection();
    
    unsigned int numberOfRomanPots() const;
    
    const StRpsRomanPot* romanPot(unsigned int) const;
    StRpsRomanPot* romanPot(unsigned int);
    
    vector<StRpsCluster*> clusters() const; // StPtrVecRpsCluster clusters() const;
    vector<StRpsTrackPoint*> trackPoints() const; // StPtrVecRpsTrackPoint trackPoints() const;
    vector<StRpsTrack*> tracks() const; // StPtrVecRpsTrack tracks() const;

    unsigned char siliconBunch() const;
    
    void setSiliconBunch(unsigned char);
    void addTrackPoint(StRpsTrackPoint*); // void addTrackPoint(const StRpsTrackPoint*);
    void addTrack(StRpsTrack*); // void addTrack(const StRpsTrack*);
    
    enum {mNumberOfRomanPots = 8};
    
private:
    StRpsRomanPot mRomanPots[mNumberOfRomanPots];
    UChar_t mSiliconBunch;
    
    vector<StRpsTrackPoint*> 	mTrackPoints; // StSPtrVecRpsTrackPoint mTrackPoints;
	vector<StRpsTrack*> 		mTracks; // StSPtrVecRpsTrack mTracks;
    

    ClassDef(StRpsCollection, 3)
};

// inline void StRpsCollection::addTrackPoint(const StRpsTrackPoint *trackPoint) {
inline void StRpsCollection::addTrackPoint(StRpsTrackPoint *trackPoint) {
    mTrackPoints.push_back(trackPoint);
}

// inline void StRpsCollection::addTrack(const StRpsTrack *track) {
inline void StRpsCollection::addTrack(StRpsTrack *track) {
    mTracks.push_back(track);
}

#endif
